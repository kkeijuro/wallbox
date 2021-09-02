#include <bitset>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

constexpr uint32_t number_of_flips = 10;


std::vector<std::pair<std::bitset<number_of_flips>, uint8_t>> flips_results = {{0b1010101010, 0},
                                                                                    {0b1010101011, 1},
                                                                                    {0b1010101111, 2}};

std::bitset<number_of_flips> get_mask_A() {
    std::bitset<number_of_flips> mask{};
    std::bitset<number_of_flips> add_value = 0;
    for(uint32_t index = 0; index < number_of_flips; index++) {
        mask = mask<<1;
        mask |= add_value;
        add_value = add_value == 1? 0: 1;
    }
    return mask;
};

std::bitset<number_of_flips> get_mask_B() {
    std::bitset<number_of_flips> mask{};
    std::bitset<number_of_flips> add_value = 1;
    for(uint32_t index = 0; index < number_of_flips; index++) {
        mask = mask<<1;
        mask |= add_value;
        add_value = add_value == 1? 0: 1;
    }
    return mask;
};

/* Based on XOR and then counting bits to 1*/

uint32_t check_flips(std::bitset<number_of_flips> flips_result) {
    std::bitset <number_of_flips> mask_A = get_mask_A();
    std::bitset <number_of_flips> mask_B = get_mask_B();
    std::bitset <number_of_flips> mask_result_A = mask_A ^flips_result;
    std::bitset <number_of_flips> mask_result_B = mask_B ^flips_result;
    uint32_t result = std::min(mask_result_A.count(), mask_result_B.count());
    return result;
}


int main() {
    for (const auto& pair_values: flips_results) {
        auto flips_result = pair_values.first;
        uint32_t expected_result = pair_values.second;
        uint32_t result = check_flips(flips_result);
        assert(expected_result == result);
    }
}