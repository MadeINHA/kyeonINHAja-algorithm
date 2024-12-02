#ifndef MADEINHA_POLYGONUTILS_H
#define MADEINHA_POLYGONUTILS_H

#include "Kickboard.h"
#include <vector>
#include <utility>

struct Coordinate{
    double lat, lng;
};

// 특정 킥보드가 주차 구역 혹은 주차 금지 구역에 속하는 지를 판단하는 함수
bool isPointInPolygon(const std::vector<Kickboard>& border_kickboards, const Kickboard& comp_kickboard);

// Convex Hull 레이어 무게 중심 계산
Coordinate calculateCentroid(const std::vector<Kickboard>& border_kickoards);

#endif //MADEINHA_POLYGONUTILS_H
