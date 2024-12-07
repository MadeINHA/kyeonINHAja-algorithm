#include "DBSCAN.h"

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const double EPS = 5.0;
const int MIN_CLUSTER = 3;

// 전역 변수 초기화
vector<bool> visited;
vector<vector<pair<double, int>>> adj;
int cluster_count = 0;

// BFS 기반 클러스터링 함수
void bfs(vector<Kickboard>& kickboard_info_list, int start) {
  deque<int> queue = { start };
  vector<int> cluster_sequence;
  visited[start] = true;

  while (!queue.empty()) {
    int x = queue.front();
    queue.pop_front();
    cluster_sequence.push_back(x);

    for (const auto& p : adj[x]) {
      if (p.first > EPS) break;
      if (visited[p.second]) continue;

      const Kickboard& neighbor_kickboard = kickboard_info_list[p.second];

      // 추가 조건: acting == true 또는 parking_zone < 2인 경우 제외
      if (neighbor_kickboard.get_acting() || neighbor_kickboard.get_parking_zone() < 2) {
        continue;
      }
      
      visited[p.second] = true;
      queue.push_back(p.second);
    }
  }

  if (cluster_sequence.size() < MIN_CLUSTER) return;

  cluster_count++;
  for (int v : cluster_sequence) {
    kickboard_info_list[v].set_cluster_id(cluster_count);
  }
}

// 초기화 함수
void initial_global(int num_kickboards) {
  visited.assign(num_kickboards, false);
  adj.assign(num_kickboards, vector<pair<double, int>>());
  cluster_count = 0;
}

const double EARTH_RADIUS_KM = 6371.0; // 지구 반경 (킬로미터)

double toRadians(double degree) {
  return degree * M_PI / 180.0;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
  double dLat = toRadians(lat2 - lat1);
  double dLon = toRadians(lon2 - lon1);

  lat1 = toRadians(lat1);
  lat2 = toRadians(lat2);

  double a = sin(dLat / 2) * sin(dLat / 2) +
             cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);

  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  return EARTH_RADIUS_KM * c;
}

Json::Value DBSCANToJson(const vector<Kickboard>& kickboards) {
  // 클러스터별로 데이터를 그룹화하기 위한 map
  map<int, vector<Kickboard>> cluster_map;
  int max_cluster_id = -1;

  for (const auto& kickboard : kickboards) {
    int cluster_id = kickboard.get_cluster_id();

    // 클러스터 ID별로 킥보드 데이터 저장
    cluster_map[cluster_id].push_back(kickboard);

    // 최대 클러스터 ID 갱신
    if (cluster_id > max_cluster_id) {
      max_cluster_id = cluster_id;
    }
  }

  // JSON 객체 생성
  Json::Value kickboard_info_list_json;
  kickboard_info_list_json["max_cluster"] = max_cluster_id;

    Json::Value cluster_list(Json::arrayValue);
    for (const auto& [cluster_id, kickboard_list] : cluster_map) {
        Json::Value cluster;
        cluster["cluster_id"] = cluster_id;

        Json::Value kickboard_list_json(Json::arrayValue);
        for (const auto& kickboard : kickboard_list) {
            Json::Value kickboard_json;
            kickboard_json["id"] = static_cast<Json::Int64>(kickboard.get_id());
            kickboard_json["lat"] = kickboard.get_lat();
            kickboard_json["lng"] = kickboard.get_lng();
            kickboard_list_json.append(kickboard_json);
        }

        cluster["kickboard_list"] = kickboard_list_json;
        cluster_list.append(cluster);
    }

    kickboard_info_list_json["cluster_list"] = cluster_list;

    return kickboard_info_list_json;
}

// DBSCAN 알고리즘 함수
vector<Kickboard> DBSCAN(vector<Kickboard>& kickboard_info_list) {
  initial_global(kickboard_info_list.size());

  // 거리 계산 및 인접 리스트 생성
  for (size_t i = 0; i < kickboard_info_list.size(); ++i) {
    for (size_t j = 0; j < i; ++j) {
      double dist = haversine(
              kickboard_info_list[i].get_lat(), kickboard_info_list[i].get_lng(),
              kickboard_info_list[j].get_lat(), kickboard_info_list[j].get_lng()
      ) * 1000;
      adj[i].emplace_back(dist, j);
      adj[j].emplace_back(dist, i);
    }
  }

  // 거리 기준으로 인접 리스트 정렬
  for (auto& list : adj) {
    sort(list.begin(), list.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        return a.first < b.first;
    });
  }

  // BFS를 통한 클러스터링
  for (int i = 0; i < kickboard_info_list.size(); ++i) {
    if (visited[i]) continue;

    // 킥보드가 주행중인 경우 탐색하지 않음
    // 주차 금지 구역에 위치(0) or 기존 주차 구역(1)에 위치한 경우 탐색하지 않음
    if (kickboard_info_list[i].get_acting() || kickboard_info_list[i].get_parking_zone() < 2) {
      visited[i] = true;
      continue;
    }
    bfs(kickboard_info_list, i);
  }

  return kickboard_info_list;
}