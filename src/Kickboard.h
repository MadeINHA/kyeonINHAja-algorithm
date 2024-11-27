#ifndef KICKBOARD_H
#define KICKBOARD_H

#include <string>
#include <map>
#include <utility>
#include <variant>

class Kickboard {
private:
    int id;
    double lat;
    double lng;
    int cluster_id;
    int parking_zone; // 0 : 주차 금지 구역, 1 : 주차 가능 구역, 2 : 주차 권장 구역
    bool border; // 가장 바깥에 위치한 킥보드인지 여부

public:
    Kickboard(int id, double lat, double lng, int parking_zone);

    void set_cluster_id(int num);
    void set_parking_zone(int num);

    int get_id() const;
    double get_lat() const;
    double get_lng() const;
    int get_cluster_id() const;
    int get_parking_zone() const;

    std::pair<double, double> get_coordinates() const;
};

#endif