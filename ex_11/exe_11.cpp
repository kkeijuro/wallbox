#include <algorithm>
#include <iostream>
#include <vector>

static std::vector<int> v1 {50,200,800,35,75,150,190,750,900};
static std::vector<int> v1_transform {};


int main() {
    std::transform(v1.begin(), v1.end(), std::back_inserter(v1_transform), [](int value) {
        if(value < 100) return value*2;
        if(value > 400) return value/4;
        return value;
    });
    std::for_each(v1.begin(), v1.end(), [](int value) {std::cout<<value<<" ";});
    std::cout<<std::endl;
    std::for_each(v1_transform.begin(), v1_transform.end(), [](int value) {std::cout<<value<<" ";});
}
