#include <ctime>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>

#include "exe_5.hpp"

int main () {
    FileInformationManagement file_management;
    std::ifstream infile("file_info.txt");
    std::string line;

    while(std::getline(infile, line)) {
        FileInformation new_file_information = FileInformation::create_instance(line);
        file_management.addFileInformation(new_file_information);
    }
    // Accumulate all the filters needed

    file_management.applyFilter(ContainsPermissionFilter('x'));
    file_management.applyFilter(OwnerFilter("admin"));
    file_management.applyFilter(MaxSizeFilter(14*pow(2, 20)));
    file_management.sortByDate();
    file_management.showFiles();
    std::cout<<std::endl;
    FileInformation file_information = file_management.getFile();
    std::cout<<"Last File:" << file_information;
    assert(file_information.getName() == "logs.zip");
    return 0;
};
