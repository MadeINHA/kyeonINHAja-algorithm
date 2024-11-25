#include "src/Kickboard.h"
#include "src/DBSCAN.h"
#include "test/test_dataset.h"
#include <vector>

using namespace std;

int main() {
  // 데이터셋 호출
  vector<Kickboard> kickboard_info_list_181 = get_test_dataset_181();
  vector<Kickboard> kickboard_info_list_550 = get_test_dataset_550();

  // DBSCAN 클러스터링 실행
  vector<Kickboard> clustered_kickboards = DBSCAN(kickboard_info_list_181);

  // JSON 결과 출력
  makeReturnJson(clustered_kickboards);

  return 0;
}