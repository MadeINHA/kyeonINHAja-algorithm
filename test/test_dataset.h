#ifndef TEST_DATASET_H
#define TEST_DATASET_H

#include "../src/Kickboard.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <random>

// 함수 선언
std::vector<Kickboard> get_test_dataset_181();

std::vector<Kickboard> get_test_dataset_550();

std::vector<Kickboard> generate_new_data(const std::vector<Kickboard>& existing_data, int total_count);

std::vector<Kickboard> randomly_modify_positions(const std::vector<Kickboard>& existing_data, int modify_count);

#endif // TEST_DATASET_H