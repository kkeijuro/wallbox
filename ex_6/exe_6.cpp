#include <bitset>
#include <cassert>
#include <iostream>

constexpr uint32_t number_of_flips = 10;
constexpr std::bitset<number_of_flips> flip_results = 0b1010101010;

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

int main() {
    std::bitset<number_of_flips> mask_A = get_mask_A();
    std::bitset<number_of_flips> mask_B = get_mask_B();
    std::bitset<number_of_flips> mask_result_A = mask_A^flip_results;
    std::bitset<number_of_flips> mask_result_B = mask_B^flip_results;
    std::cout<< mask_result_A << std::endl;
    std::cout<< mask_result_B << std::endl;
    std::cout<< "Total changes needed: "<< std::min(mask_result_A.count(), mask_result_B.count())<<std::endl;
}