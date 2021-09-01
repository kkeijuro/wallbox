#include <iostream>
struct Vehicle {
	virtual ~Vehicle() = default;
	virtual void Move() {std::cout<<"Going to fly"<<std::endl;}
};

struct WheelVehicle: Vehicle {
	virtual void TurnRight() {}
};

struct WingVehicle: Vehicle {
	virtual void TakeOff() {}
};

// A plane is a vehicle with wheels and wings
struct Plane: WheelVehicle, WingVehicle {
	void Move() {
	    WheelVehicle::Move();
	};
};

