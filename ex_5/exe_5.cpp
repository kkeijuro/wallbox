#include <ctime>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>

#include "exe_5.hpp"

FileInformation::FileInformation() {}

FileInformation::FileInformation(std::string name): name(name), owner(""), permissions("---"), size(0) {
    memset(&date, 0, sizeof(tm));
};

std::string FileInformation::getOwner() const {return this->owner;};

tm FileInformation::getDate() const {return this->date;};

std::string FileInformation::getPermissions() const {return this->permissions;};

uint64_t FileInformation::getSize() const {return this->size;};

std::string FileInformation::getName() const {return this->name;};

FileInformation& FileInformation::create_instance(const std::string& line) {
    FileInformation* file_information = new FileInformation;
    std::istringstream iss(line);
    std::string day, year, month, day_month_year;
    iss >> file_information->owner >> file_information->permissions >> day >> month >> year >> file_information->size >> file_information->name;
    day_month_year = day + month + year;
    strptime(day_month_year.c_str(), "%d%B%Y", &file_information->date);
    return *file_information;
}

std::ostream& operator<<(std::ostream& os, const FileInformation& file_information){
    char* buf = new char[128];
    strftime(buf, 128, "%d %B %Y", &file_information.date);
    os << file_information.owner<<" "
        << file_information.permissions <<" "
        << buf <<" "
        << file_information.size <<" "
        << file_information.name;
    delete[] buf;
    return os;
};

struct {
        bool operator()(const FileInformation& file_information_lcmp, const FileInformation& file_information_rcmp) const { 
	     tm tm_lcmp = file_information_lcmp.getDate();
             tm tm_rcmp = file_information_rcmp.getDate();	
             if(tm_rcmp.tm_year < tm_lcmp.tm_year) return true;
             if(tm_rcmp.tm_year > tm_lcmp.tm_year) return false; 
             if(tm_rcmp.tm_mon < tm_lcmp.tm_mon) return true;
             if(tm_rcmp.tm_mon > tm_lcmp.tm_mon) return false;
             if(tm_rcmp.tm_yday < tm_lcmp.tm_yday) return true;
             if(tm_rcmp.tm_yday > tm_lcmp.tm_yday) return false;
             return true;
	}
} Sort_Date;

/*
 *  FILTERS AVAILABLE
 *
 */

struct ContainsPermissionFilter {
        ContainsPermissionFilter(char contains_value): contains_value(contains_value){};
        bool operator()(const FileInformation& file_information_lcmp) const {
             return file_information_lcmp.getPermissions().find(contains_value) == std::string::npos;
        }
        private:
        char contains_value;
};

struct OwnerFilter {
    OwnerFilter(std::string owner): owner(owner){};
    bool operator()(const FileInformation& file_information_lcmp) const {
        return file_information_lcmp.getOwner() != this->owner;
    }
private:
    std::string owner;
};

struct MaxSizeFilter {
    MaxSizeFilter(uint64_t max_size): max_size(max_size){};
    bool operator()(const FileInformation& file_information_lcmp) const {
        return file_information_lcmp.getSize() < max_size;
    }
private:
    uint64_t max_size;
};

/*
 * FILE INFORMATION MANAGEMENT
 */

FileInformationManagement::FileInformationManagement(){
    this->begin_it = this->file_container.begin();
    this->end_it = this->file_container.end();
};

void FileInformationManagement::addFileInformation(const FileInformation& file_information) {
    this->file_container.push_back(file_information);
    this->begin_it = this->file_container.begin();
    this->end_it = this->file_container.end();
};

void FileInformationManagement::sortByDate() {
    std::sort(this->begin_it, this->end_it, Sort_Date);
};

void FileInformationManagement::applyFilter(std::function<bool(const FileInformation&)> function) {
    this->begin_it = std::partition(this->begin_it, this->end_it, function);
};

void FileInformationManagement::showFiles() {
    std::for_each(this->begin_it, this->end_it,
                  [] (const FileInformation& file_information) {std::cout<<file_information<<"\n"; });
};

FileInformation FileInformationManagement::getFile() {
    if(this->begin_it == this->file_container.end())
        return FileInformation("NO FILE");
    return *this->begin_it;
};

int main () {
    FileInformationManagement file_management;
    std::ifstream infile("file_info.txt");
    std::string line;

    while(std::getline(infile, line)) {
        FileInformation new_file_information = FileInformation::create_instance(line);
        file_management.addFileInformation(new_file_information);
    }
    file_management.applyFilter(ContainsPermissionFilter('x'));
    file_management.applyFilter(OwnerFilter("admin"));
    file_management.applyFilter(MaxSizeFilter(14*pow(2, 20)));
    file_management.sortByDate();
    file_management.showFiles();
    std::cout<<std::endl;
    std::cout<<"Last File:" <<file_management.getFile();
    return 0;
};
