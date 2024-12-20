#include "PolygonUtils.h"
#include <cmath>

using namespace std;

bool isPointInPolygon(const vector<Kickboard>& border_kickboards, const Kickboard& comp_kickboard) {
  int cross_cnt = 0; // 교차 횟수

  for (size_t i = 0; i < border_kickboards.size(); ++i) {
    const Kickboard& kick1 = border_kickboards[i];
    const Kickboard& kick2 = border_kickboards[(i + 1) % border_kickboards.size()]; // 다음 점

    // 점이 선분의 경계 위에 있는지 확인
    double cross_product = (comp_kickboard.get_lat() - kick1.get_lat()) * (kick2.get_lng() - kick1.get_lng()) -
                           (comp_kickboard.get_lng() - kick1.get_lng()) * (kick2.get_lat() - kick1.get_lat());

    if (abs(cross_product) < 1e-9) { // cross_product가 0에 가까우면 선분 위
      if (min(kick1.get_lng(), kick2.get_lng()) <= comp_kickboard.get_lng() &&
          comp_kickboard.get_lng() <= max(kick1.get_lng(), kick2.get_lng()) &&
          min(kick1.get_lat(), kick2.get_lat()) <= comp_kickboard.get_lat() &&
          comp_kickboard.get_lat() <= max(kick1.get_lat(), kick2.get_lat())) {
        return true; // 경계 위에 위치하면 포함으로 간주
      }
    }

    // Ray-Casting 알고리즘에 따라 교차점 확인
    if ((kick1.get_lat() > comp_kickboard.get_lat()) != (kick2.get_lat() > comp_kickboard.get_lat())) {
      double lng_intersect = kick1.get_lng() + (comp_kickboard.get_lat() - kick1.get_lat()) * (kick2.get_lng() - kick1.get_lng()) / (kick2.get_lat() - kick1.get_lat());
      if (lng_intersect > comp_kickboard.get_lng()) {
        ++cross_cnt;
      }
    }
  }

  return (cross_cnt % 2 == 1); // 교차 횟수가 홀수면 내부, 짝수면 외부
}

Coordinate calculateCentroid(const vector<Kickboard>& border_kickboards) {
    double avgLat = 0.0;
    double avgLng = 0.0;

    size_t n = border_kickboards.size();
    for (const auto& kick : border_kickboards) {
        avgLat += kick.get_lat();
        avgLng += kick.get_lng();
    }

    avgLat /= n;
    avgLng /= n;

    return {avgLat, avgLng};
}