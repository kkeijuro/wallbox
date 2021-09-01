#include <iostream>
#include <set>
#include <vector>
#include "exe_3.hpp"


XY::XY(int x, int y): x(x), y(y){};
bool operator<(const XY& xy_lcmp, const XY& xy_rcmp){
	if(xy_lcmp.x < xy_rcmp.x) return true;
        else if(xy_lcmp.x == xy_rcmp.y) return xy_lcmp.y < xy_rcmp.y;
        return false;
};

float operator%(const XY& xy_lcmp, int divisor) {
    return (xy_lcmp.x + xy_lcmp.y)%divisor;
}

std::ostream& operator<<(std::ostream& os, const XY& xy){
    os << "("<< xy.x << "," << xy.y << ")";
    return os;
};


void find_ordered_divisible_pairs(const std::set<XY*>& xy_set, int divisor, std::set<XY*>& filtered_result){
    std::copy_if(xy_set.begin(), xy_set.end(), inserter(filtered_result, filtered_result.end()), [divisor] (const XY* xy) { return (*xy)%divisor == 0;});
}


static constexpr int A = 2;
static constexpr int B = 4;
static constexpr int C = 3;
static constexpr int O = 10;
static constexpr int P = 10;
 
int main(int argc, char** argv) {
    std::cout<<"A: "<<A<<" B: "<<B<<" O: "<<O<<" P: "<<P<<std::endl;
    std::set<XY*> xy_original_set;
    for(int index_x = 1; index_x<=O; index_x++)
	for(int index_y = 1; index_y<=P; index_y++) {
            XY* xy_instance = new XY(index_x, index_y);
            xy_original_set.insert(xy_instance);
	}

    /* This is a first idea for the algortihm, to be able to add divisors easyly*/
    std::set<XY*> filtered_result;
    std::set<XY*> xy_set = xy_original_set;
    std::vector<int> divisor_values{A,B, C};
    for(std::vector<int>::iterator it = divisor_values.begin(); it != divisor_values.end(); it++) {
	std::cout<<"Divisor: "<<*it<<std::endl;
    	find_ordered_divisible_pairs(xy_set, *it, filtered_result);
        xy_set = filtered_result;
        filtered_result.clear();
    }
    
    std::for_each(xy_set.begin(), xy_set.end(),  [] (XY* xy) {std::cout<<*xy<<"\n"; });
};

