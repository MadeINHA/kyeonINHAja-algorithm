cmake_minimum_required(VERSION 3.28)
project(kyeonINHAja_algorithm)

set(CMAKE_CXX_STANDARD 17)

# gRPC 및 Protobuf 설정
find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)
find_package(JsonCpp REQUIRED)

include_directories(src)
include_directories(src/src)
include_directories(test)

add_executable(kyeonINHAja_algorithm
        src/src/algorithm_service.grpc.pb.cc
        src/src/algorithm_service.pb.cc
        src/ConvexHull.cpp
        src/ConvexHull.h
        src/DBSCAN.cpp
        src/DBSCAN.h
        src/Kickboard.cpp
        src/Kickboard.h
        src/PolygonUtils.cpp
        src/PolygonUtils.h
        test/test_dataset.cpp
        test/test_dataset.h
        main.cpp
)
target_link_libraries(kyeonINHAja_algorithm
        gRPC::grpc++
        protobuf::libprotobuf
        protobuf::libprotoc
        JsonCpp::JsonCpp
)