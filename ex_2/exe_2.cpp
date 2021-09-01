#include <iostream>
#include "exe_2.hpp"

int main() {
	ev_t* car = new ev_t();
	std::cout<<"Car: "<< car->a<<" "<<car->b<<" "<<car->c<<" "<<car->d<<std::endl;
	memset(&car, 0, sizeof(car));
	//Only 4 bytes from class are initialized to 0. sizeof(ev_t) will reinitialize full class
	std::cout<<"Car: "<< car->a<<" "<<car->b<<" "<<car->c<<" "<<car->d<<std::endl;
};
