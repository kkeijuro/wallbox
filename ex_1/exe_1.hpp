#include <iostream>
struct Vehicle {
	virtual ~Vehicle() = default;
	virtual void Move() {std::cout<<"Going to fly"<<std::endl;}
};

struct WheelVehicle: virtual Vehicle {
	virtual void TurnRight() {}
};

struct WingVehicle: virtual Vehicle {
	virtual void TakeOff() {}
};

// A plane is a vehicle with wheels and wings
struct Plane: WheelVehicle, WingVehicle {
	void Move() {
	    WheelVehicle::Move();
	};
};

