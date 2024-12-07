#include "Kickboard.h"
#include <unordered_map>

Kickboard::Kickboard(long id, double lat, double lng, int cluster_id, int parking_zone, bool acting)
        : id(id), lat(lat), lng(lng), cluster_id(cluster_id), parking_zone(parking_zone), acting(acting) {
}

Kickboard::Kickboard(long id, double lat, double lng, int parking_zone)
        :id(id), lat(lat),lng(lng),parking_zone(parking_zone),cluster_id(-1){}

void Kickboard::set_cluster_id(int num) {
    cluster_id = num;
}

void Kickboard::set_parking_zone(int num) {
    parking_zone = num;
}

long Kickboard::get_id() const {
    return id;
}

double Kickboard::get_lat() const {
    return lat;
}

double Kickboard::get_lng() const {
    return lng;
}

int Kickboard::get_cluster_id() const {
    return cluster_id;
}

int Kickboard::get_parking_zone() const {
    return parking_zone;
}

bool Kickboard::get_acting() const {
    return acting;
}

std::pair<double, double> Kickboard::get_coordinates() const {
    return {lat, lng};
}



