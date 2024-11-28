#ifndef ConvexHull_H
#define ConvexHull_H

#include "Kickboard.h"
#include <vector>
#include <json/json.h>

struct Cluster {
    int cluster_id;
    std::vector<Kickboard> kickboard_list;

    Cluster(int cluster_id) : cluster_id(cluster_id) {}
};

// JSON 파싱 함수
std::vector<Cluster> parseJson(const Json::Value& root);

#endif // ConvexHull_H