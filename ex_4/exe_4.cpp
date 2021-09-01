#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>



int main() {
	std::vector<int> numbers(16);
	std::iota (numbers.begin(), numbers.end(), 1);
	uint64_t sum = std::accumulate(numbers.begin(), numbers.end(), 0,
                                [](int acc_value, int value) { return (value%3==0 || value%5==0)? acc_value + value: acc_value;});
        std::cout<<"SUM VALUE IS: "<< sum << std::endl;
};
