#include "ConvexHull.h"

#include <iostream>
using namespace std;

std::pair<std::vector<Cluster>, int> parseJson(const Json::Value& root) {
    vector<Cluster> clusters;

    // 클러스터 리스트 파싱
    const Json::Value cluster_list = root["cluster_list"];
    for (const auto& cluster : cluster_list) {
        int cluster_id = cluster["cluster_id"].asInt();
        Cluster current_cluster(cluster_id);

        // 킥보드 리스트 파싱
        const Json::Value kickboard_list = cluster["kickboard_list"];
        for (const auto& kickboard : kickboard_list) {
            long id = kickboard["id"].asLargestInt();
            double lat = kickboard["lat"].asDouble();
            double lng = kickboard["lng"].asDouble();
            current_cluster.kickboard_list.emplace_back(id, lat, lng,cluster_id,0, false);
        }

        clusters.push_back(current_cluster);
    }

    const Json::Value max_cluster = root["max_cluster"];
    int max_cluster_int = max_cluster.asInt();

    return {clusters, max_cluster_int};
}

double getCrossProduct(Kickboard& kick1, Kickboard& kick2, Kickboard& kick3){
  double x1 = kick1.get_lng(), x2 = kick2.get_lng(), x3 = kick3.get_lng();
  double y1 = kick1.get_lat(), y2 = kick2.get_lat(), y3 = kick3.get_lat();

  return (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);
}

vector<Kickboard> grahamScan (vector<Kickboard> kickboard_list){
  // lat이 가장 작은 킥보드를 minLatKickboard로 설정, lat이 같다면 lng가 가장 작은 것으로!
  Kickboard minLatKickboard = kickboard_list[0];

  for (const auto& kickboard : kickboard_list) {
    if(kickboard.get_lat() < minLatKickboard.get_lat()
       || (kickboard.get_lat() == minLatKickboard.get_lat()
           && kickboard.get_lng() < minLatKickboard.get_lng())){
      minLatKickboard = kickboard;
    }
  }

  // minLatKickBoard를 기준으로 다른 킥보드와의 각도를 구함.
  vector<KickboardAngle> kickboardAngle;
  for (const auto& kickboard : kickboard_list) {
    if(kickboard.get_id() == minLatKickboard.get_id()) continue;

    double lat_gap = kickboard.get_lat() - minLatKickboard.get_lat();
    double lng_gap = kickboard.get_lng() - minLatKickboard.get_lng();
    double angle = atan2(lat_gap, lng_gap);

    kickboardAngle.emplace_back(angle, kickboard);
  }

  // 각도를 기준으로 KickboardAngle 정렬
  std::sort(kickboardAngle.begin(), kickboardAngle.end(),
            [](const KickboardAngle& a, const KickboardAngle& b) {
                return a.angle < b.angle; // 오름차순 정렬
            });

  // Convex hull 시작점과 끝점 추가
  kickboardAngle.insert(kickboardAngle.begin(), KickboardAngle(0, minLatKickboard));
  //kickboardAngle.emplace_back(0, minLatKickboard);


  vector<Kickboard> border_kickboard_list;
  // 첫 번째, 두 번째, 세 번째 요소를 border_kickboard_list에 추가, kickboardAngle에서 제거
  for(int i=0; i<3; i++){
    border_kickboard_list.push_back(kickboardAngle.front().kickboard);
    kickboardAngle.erase(kickboardAngle.begin());
  }

  int cursor = 2;
  while(true){
    Kickboard kick1 = border_kickboard_list[cursor-2];
    Kickboard kick2 = border_kickboard_list[cursor-1];
    Kickboard kick3 = border_kickboard_list[cursor];

    double crossProduct = getCrossProduct(kick1, kick2, kick3);

    if(crossProduct > 0){
      // 반시계 방향 회전: 점을 유지
      if (kickboardAngle.empty()) break;
      border_kickboard_list.push_back(kickboardAngle.front().kickboard);
      kickboardAngle.erase(kickboardAngle.begin());
      cursor++;
    }
    else {
      // 시계 방향 회전 또는 일직선 상: 마지막 점 제거
      border_kickboard_list.erase(border_kickboard_list.begin() + (cursor - 1));
      cursor--;
    }
  }

  return border_kickboard_list;
}

Json::Value ConvexToJson(const std::vector<std::vector<Kickboard>>& border_kickboard_list, int max_cluster) {
  Json::Value root;
  Json::Value cluster_list(Json::arrayValue);

  for(int i=0; i<max_cluster; i++){
    Json::Value cluster_json;
    cluster_json["cluster_id"] = i + 1; // 클러스터 ID는 1부터 시작한다고 가정

    Json::Value kickboard_list(Json::arrayValue);

    for (const auto& kickboard : border_kickboard_list[i]) {
      Json::Value kickboard_json;
      kickboard_json["id"] = static_cast<Json::Int64>(kickboard.get_id());
      kickboard_json["lat"] = kickboard.get_lat();
      kickboard_json["lng"] = kickboard.get_lng();
      kickboard_list.append(kickboard_json);
    }
    const Coordinate &coordinate = calculateCentroid(border_kickboard_list[i]);
    cluster_json["kickboard_list"] = kickboard_list;
    cluster_json["cent_lat"] = coordinate.lat;
    cluster_json["cent_lng"] = coordinate.lng;
    cluster_list.append(cluster_json);
  }
  root["cluster_list"] = cluster_list;
  root["max_cluster"] = max_cluster;

  return root;
}