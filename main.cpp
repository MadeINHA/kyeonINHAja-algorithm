#include "src/Kickboard.h"
#include "src/DBSCAN.h"
#include "src/ConvexHull.h"
#include "src/PolygonUtils.h"
#include "algorithm_service.grpc.pb.h"
#include "algorithm_service.pb.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <grpcpp/grpcpp.h>

using namespace std;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using algorithm::AlgorithmRequest;
using algorithm::AlgorithmResponse;
using algorithm::AlgorithmService;

Json::Value dbscan_json;

vector<Kickboard> parseKickboards(const std::string& jsonString) {
    vector<Kickboard> kickboards;

    // JSON 파싱 객체
    Json::CharReaderBuilder builder;
    Json::Value root;
    string errors;

    // JSON 문자열 파싱
    istringstream stream(jsonString);
    if (!Json::parseFromStream(builder, stream, &root, &errors)) {
        throw runtime_error("Failed to parse JSON: " + errors);
    }

    // kickboard_list 배열 가져오기
    const Json::Value& kickboardList = root["kickboard_list"];
    for (const auto& kickboardData : kickboardList) {
        long id = kickboardData["kickboardId"].asLargestInt();
        double lat = kickboardData["lat"].asDouble();
        double lng = kickboardData["lng"].asDouble();
        int cluster_id = kickboardData["clusterId"].asInt();
        int parking_zone = kickboardData["parkingZone"].asInt();
        bool acting = kickboardData["acting"].isNull() ? false : kickboardData["acting"].asBool();

        // Kickboard 객체 생성 및 벡터에 추가
        kickboards.emplace_back(id, lat, lng, cluster_id, parking_zone, acting);
    }

    return kickboards;
}

class AlgorithmServiceImpl final : public algorithm::AlgorithmService::Service{
public :
    Status DbScan(ServerContext* context, const AlgorithmRequest* request, AlgorithmResponse* response) override {
        string &input = const_cast<string &>(request->json_input());

        vector<Kickboard> kickboard_list = parseKickboards(input);
        vector<Kickboard> clustered_kickboards = DBSCAN(kickboard_list);
        dbscan_json = DBSCANToJson(clustered_kickboards);

        string output_json = DBSCANToResponse(clustered_kickboards).toStyledString();

        response->set_json_output(output_json);
        return Status::OK;
    }

    Status convexHull(ServerContext* context, const AlgorithmRequest* request, AlgorithmResponse* response) override {
        auto clusters_pair = parseJson(dbscan_json);
        auto clusters = clusters_pair.first;
        int max_cluster = clusters_pair.second;

        vector<Kickboard> kickboards, border_kickboards;
        vector<vector<Kickboard>> border_kickboard_list;
        for(int i=1; i<=max_cluster; i++){
            kickboards = clusters[i].kickboard_list;
            border_kickboards = grahamScan(kickboards);
            border_kickboard_list.push_back(border_kickboards);
        }

        Json::Value convex_json = ConvexToJson(border_kickboard_list, max_cluster);
        string output_json = convex_json.toStyledString();

        response->set_json_output(output_json);
        return Status::OK;
    }

};

void RunServer(){
    string server_address("0.0.0.0:50051");
    AlgorithmServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    unique_ptr<Server> server(builder.BuildAndStart());
    cout << "Server on : " << server_address << endl; // 나중에 꼭 지우셈

    server->Wait();
}


int main() {
    RunServer();
    return 0;
}
