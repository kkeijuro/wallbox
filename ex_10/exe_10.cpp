#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class ElectricVehicle {
    public:
    ElectricVehicle(std::string p_brand, std::string p_model, float p_energy) :
            brand(p_brand), model(p_model), energy_capacity(p_energy) {}
    float getMaxEnergy() const { return energy_capacity; }
    std::string getBrand() const { return brand; }
    std::string getModel() const { return model; }
    private:
    std::string brand;
    std::string model;
    float energy_capacity;
};

static std::vector<ElectricVehicle> e_vehicles{ElectricVehicle("Tesla", "Model 3", 75),
                                          ElectricVehicle("Kia", "Soul", 64),
                                          ElectricVehicle("BMW", "i3", 42.2),
                                          ElectricVehicle("Renault", "Zoe", 52),
                                          ElectricVehicle("Peugeot", "e-208", 50)};

static void print_cars() {
    std::cout<<"==="<<std::endl;
    std::for_each(e_vehicles.begin(), e_vehicles.end(), [](const ElectricVehicle& e_vehicle){
        std::cout<<e_vehicle.getBrand()<<" "<< e_vehicle.getModel()<< " "<< e_vehicle.getMaxEnergy()<<std::endl;
    });
    std::cout<<"==="<<std::endl;
};

int main() {
    print_cars();
    /*
     * Ok, is a very large line, but still just one line ;)
     */
    std::sort(e_vehicles.begin(), e_vehicles.end(), [](const ElectricVehicle& e_vehicle_lcmp, const ElectricVehicle& e_vehicle_rcmp){
                                                            return e_vehicle_rcmp.getMaxEnergy() < e_vehicle_lcmp.getMaxEnergy();
                                                        });
    print_cars();
}