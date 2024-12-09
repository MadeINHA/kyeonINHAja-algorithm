#ifndef ConvexHull_H
#define ConvexHull_H

#include "Kickboard.h"
#include "PolygonUtils.h"
#include <vector>
#include <json/json.h>
#include <fstream>

struct Cluster { // JSON 파싱된 데이터를 담기 위한 구조체
    int cluster_id;
    std::vector<Kickboard> kickboard_list;

    Cluster(int cluster_id) : cluster_id(cluster_id) {}
};

struct KickboardAngle{
    double angle;
    Kickboard kickboard;

    KickboardAngle(double angle, Kickboard kickboard) : angle(angle), kickboard(kickboard) {}
};

// JSON 파싱 함수
std::pair<std::vector<Cluster>, int> parseJson(const Json::Value& root);

// 세 점의 외적을 계산하는 함수
double getCrossProduct(Kickboard& kick1, Kickboard& kick2, Kickboard& kick3);

// grahamScan 함수
std::vector<Kickboard> grahamScan (std::vector<Kickboard> kickboard_list);

// Convex Hull 결과 값을 Json으로 변환하는 함수
Json::Value ConvexToJson(const std::vector<std::pair<std::vector<Kickboard>,int>>& border_kickboard_list, int max_cluster);

#endif // ConvexHull_H