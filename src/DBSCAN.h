#ifndef DBSCAN_H
#define DBSCAN_H

#include "Kickboard.h"
#include <vector>
#include <utility> // for std::pair
#include <json/json.h>
#include <fstream>

// 전역 변수 초기화 함수
void initial_global(int num_kickboards);

// 거리 계산 함수
double get_distance(const std::pair<double, double>& kick1, const std::pair<double, double>& kick2);

// BFS 기반 클러스터링 함수
void bfs(std::vector<Kickboard>& kickboard_info_list, int start);

// DBSCAN 알고리즘 함수
std::vector<Kickboard> DBSCAN(std::vector<Kickboard>& kickboard_info_list);

// DBSCAN 결과를 JSON 형식 변환하는 함수
Json::Value DBSCANToJson(const std::vector<Kickboard>& kickboards);

#endif // DBSCAN_H