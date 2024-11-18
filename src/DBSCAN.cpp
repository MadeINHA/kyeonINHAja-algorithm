#include "Kickboard.h"

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>

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

// 거리 계산 함수
double get_distance(const std::pair<double, double>& kick1, const std::pair<double, double>& kick2) {
  double tmp = sqrt(pow(kick1.first - kick2.first, 2) + pow(kick1.second - kick2.second, 2));
  double dist = tmp * 100000;
  return dist;
}

void makeReturnJson(const vector<Kickboard>& k_tmp) {
  cout << "[ ";
  for (const auto& kick : k_tmp) {
    cout << "{ \"id\": " << kick.get_id()
         << ", \"lat\": " << kick.get_lat()
         << ", \"lon\": " << kick.get_lng()
         << ", \"cluster_id\": " << kick.get_cluster_id()
         << " }, " << endl;
  }
  cout << " ]";
}

// DBSCAN 알고리즘 함수
vector<Kickboard> DBSCAN(vector<Kickboard>& kickboard_info_list) {
  initial_global(kickboard_info_list.size());

  // 거리 계산 및 인접 리스트 생성
  for (const auto& kick1 : kickboard_info_list) {
    for (const auto& kick2 : kickboard_info_list) {
      if (kick1.get_id() <= kick2.get_id()) continue;
      double dist = get_distance(kick1.get_coordinates(), kick2.get_coordinates());
      adj[kick1.get_id()].emplace_back(dist, kick2.get_id());
      adj[kick2.get_id()].emplace_back(dist, kick1.get_id());
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
    bfs(kickboard_info_list, i);
  }

  return kickboard_info_list;
}