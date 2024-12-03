#include "src/Kickboard.h"
#include "src/DBSCAN.h"
#include "src/ConvexHull.h"
#include "src/PolygonUtils.h"
#include "test/test_dataset.h"

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
  // srand(static_cast<unsigned>(time(0)));
  // 데이터셋 호출
  vector<Kickboard> kickboard_info_list_181 = get_test_dataset_181();
  vector<Kickboard> kickboard_info_list_550 = get_test_dataset_550();
  vector<Kickboard> kickboard_info_list_1000 = generate_new_data(kickboard_info_list_550, 1000);
  vector<Kickboard> kickboard_info_list_550_random = randomly_modify_positions(kickboard_info_list_550, 50);

  // DBSCAN 클러스터링 실행
  vector<Kickboard> clustered_kickboards = DBSCAN(kickboard_info_list_550_random);
//  vector<Kickboard> clustered_kickboards = DBSCAN(kickboard_info_list_1000);

  // DBSCAN JSON 변환
  Json::Value dbscan_json = DBSCANToJson(clustered_kickboards);

  // JSON 파싱
  pair<vector<Cluster>, int> clusters_pair = parseJson(dbscan_json);
  vector<Cluster> clusters = clusters_pair.first;
  int max_cluster = clusters_pair.second;

  // 파싱 결과 출력
//  for (const auto& cluster : clusters) {
//    cout << "Cluster ID: " << cluster.cluster_id << '\n';
//    for (const auto& kickboard : cluster.kickboard_list) {
//      cout << "  Kickboard ID: " << kickboard.get_id()
//                << fixed << setprecision(15) << ", Lat: " << kickboard.get_lat()
//                << fixed << setprecision(15) << ", Lng: " << kickboard.get_lng() << "\n";
//    }
//  }

  // Convex Hull 실행
  vector<Kickboard> kickboards, border_kickboards;
  vector<vector<Kickboard>> border_kickboard_list;
  for(int i=1; i<=max_cluster; i++){
    kickboards = clusters[i].kickboard_list;
    border_kickboards = grahamScan(kickboards);

    // kickboard_info_list_550 일 때, ID = 512 킥보드의 Cluster_id = 35 군집 포함 여부 체크를 위한 출력 코드
//    if(i==35){
//      Kickboard comp_kick = kickboard_info_list_550[511];
//
//      cout << "  Kickboard ID: " << comp_kick.get_id()
//           << fixed << setprecision(15) << ", Lat: " << comp_kick.get_lat()
//           << fixed << setprecision(15) << ", Lng: " << comp_kick.get_lng()
//           << ", PointInPolygon: "<< isPointInPolygon(border_kickboards, comp_kick) << "\n";
//    }

    border_kickboard_list.push_back(border_kickboards);
  }

  Json::Value convex_json = ConvexToJson(border_kickboard_list, max_cluster);

//  for(int i=0; i<max_cluster; i++){
//    // convex hull 실행 결과 출력
//    cout << "Cluster ID: " << i+1 << '\n';
//    for (const auto& kickboard : border_kickboard_list[i]) {
//      cout << "  Kickboard ID: " << kickboard.get_id()
//           << fixed << setprecision(15) << ", Lat: " << kickboard.get_lat()
//           << fixed << setprecision(15) << ", Lng: " << kickboard.get_lng() << "\n";
//    }
//  }

  return 0;
}