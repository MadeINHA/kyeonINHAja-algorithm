#include "src/Kickboard.h"
#include "src/DBSCAN.h"
#include "src/ConvexHull.h"
#include "test/test_dataset.h"

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
  // 데이터셋 호출
  vector<Kickboard> kickboard_info_list_181 = get_test_dataset_181();
  vector<Kickboard> kickboard_info_list_550 = get_test_dataset_550();

  // DBSCAN 클러스터링 실행
  vector<Kickboard> clustered_kickboards = DBSCAN(kickboard_info_list_550);

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