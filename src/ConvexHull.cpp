#include "ConvexHull.h"

std::vector<Cluster> parseJson(const Json::Value& root) {
  std::vector<Cluster> clusters;

  // 클러스터 리스트 파싱
  const Json::Value cluster_list = root["cluster_list"];
  for (const auto& cluster : cluster_list) {
    int cluster_id = cluster["cluster_id"].asInt();
    Cluster current_cluster(cluster_id);

    // 킥보드 리스트 파싱
    const Json::Value kickboard_list = cluster["kickboard_list"];
    for (const auto& kickboard : kickboard_list) {
      int id = kickboard["id"].asInt();
      double lat = kickboard["lat"].asDouble();
      double lng = kickboard["lng"].asDouble();
      current_cluster.kickboard_list.emplace_back(id, lat, lng, 0);
    }

    clusters.push_back(current_cluster);
  }

  return clusters;
}