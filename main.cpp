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

};

int main() {

}
