#include "PolygonUtils.h"
#include <cmath>

using namespace std;

bool isPointInPolygon(const std::vector<Kickboard>& border_kickboards, const Kickboard& comp_kickboard) {
  int cross_cnt = 0; // 교차 횟수

  for (size_t i = 0; i < border_kickboards.size(); ++i) {
    const Kickboard& kick1 = border_kickboards[i];
    const Kickboard& kick2 = border_kickboards[(i + 1) % border_kickboards.size()]; // 다음 점

    // lng좌표가 점의 lat좌표와 교차하는지 확인
    if ((kick1.get_lat() > comp_kickboard.get_lat()) != (kick2.get_lat() > comp_kickboard.get_lat())) {
      // lng좌표에서 교차점 계산
      double lng_intersect = kick1.get_lng() + (comp_kickboard.get_lat() - kick1.get_lat()) * (kick2.get_lng() - kick1.get_lng()) / (kick2.get_lat() - kick1.get_lat());
      if (lng_intersect > comp_kickboard.get_lng()) {
        ++cross_cnt;
      }
    }
  }

  return (cross_cnt % 2 == 1);
}

Coordinate calculateCentroid(const std::vector<Kickboard>& border_kickboards) {
  double area = 0.0; // 다각형 면적
  double lngCenter = 0.0;   // 중심점 get_lng() 좌표
  double latCenter = 0.0;   // 중심점 get_lat() 좌표

  size_t n = border_kickboards.size();
  for (size_t i = 0; i < n; ++i) {
    const Kickboard& kick1 = border_kickboards[i];
    const Kickboard& kick2 = border_kickboards[(i + 1) % n]; // 마지막 점과 첫 번째 점을 연결

    double cross = kick1.get_lng() * kick2.get_lat() - kick2.get_lng() * kick1.get_lat();
    area += cross;
    lngCenter += (kick1.get_lng() + kick2.get_lng()) * cross;
    latCenter += (kick1.get_lat() + kick2.get_lat()) * cross;
  }

  area *= 0.5;
  lngCenter /= (6.0 * area);
  latCenter /= (6.0 * area);

  return {lngCenter, latCenter};
}