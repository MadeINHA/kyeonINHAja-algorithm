#include "Kickboard.h"

Kickboard::Kickboard(int id, double lat, double lng, int parking_zone)
        : id(id), lat(lat), lng(lng), cluster_id(-1), parking_zone(parking_zone), border_index(-1) {}

void Kickboard::set_cluster_id(int num) {
  cluster_id = num;
}

void Kickboard::set_parking_zone(int num) {
  parking_zone = num;
}

int Kickboard::get_id() const {
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

std::pair<double, double> Kickboard::get_coordinates() const {
  return {lat, lng};
}