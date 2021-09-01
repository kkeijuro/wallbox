#include <iostream>
#include <sstream>
#include "exe_12.hpp"

DeviceInformation::DeviceInformation(std::string connection_type, std::string name, uint64_t uid):
    name(name), connection_type(connection_type), uid(uid) {

};

std::string DeviceInformation::getConnectionType() const {
    return this->connection_type;
};

std::string DeviceInformation::getName() const {
    return this->name;
};

uint64_t DeviceInformation::getUID() const{
    return this->uid;
};

std::string JSonParser::parseDevice(const DeviceInformation& device_information) {
    std::stringstream s_stream;
    s_stream<<"{\"device\":\""<< device_information.getName()<<"\","
                    << "\"uid\":"<< device_information.getUID()<<","
                    << "\"connection_type\":"<<device_information.getConnectionType()<<"\"}";
    return s_stream.str();
};

std::string TextParser::parseDevice(const DeviceInformation& device_information) {
    std::stringstream s_stream;
    s_stream<<"TEXT: "<< device_information.getName()<<" "
            << device_information.getUID()<<" "
            << device_information.getConnectionType();
    return s_stream.str();
};

int main() {
    /* Strategy pattern */
    DeviceInformation device_information("Serial", "Simulated_Device", 12345);
    DeviceInformationParser* parser = new JSonParser();
    std::cout<<" Return: " << parser->parseDevice(device_information)<<std::endl;
    parser = new TextParser();
    std::cout<<" Return: " << parser->parseDevice(device_information)<<std::endl;
};