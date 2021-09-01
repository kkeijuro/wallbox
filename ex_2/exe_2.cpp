#include <iostream>
#include "exe_2.hpp"

int main() {
	ev_t* car = new ev_t();
        std::cout<<"Car: "<< car->a<<" "<<car->b<<" "<<car->c<<" "<<car->d<<std::endl;
	memset(&car, 0, sizeof(car));
        std::cout<<"Car: "<< car->a<<" "<<car->b<<" "<<car->c<<" "<<car->d<<std::endl;
};
