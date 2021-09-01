#include <vector>


class FileInformation {
private:
    tm date;
    std::string name;
    std::string owner;
    std::string permissions;
    uint64_t size;
public:
    FileInformation();
    FileInformation(std::string name);
    tm getDate() const;
    std::string getName() const;
    std::string getOwner() const;
    std::string getPermissions() const;
    uint64_t getSize() const;
    static FileInformation& create_instance(const std::string& line);
    friend std::ostream& operator<<(std::ostream& os, const FileInformation& file_information);
};


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
 * FILE MANAGEMENT
 */
class FileInformationManagement {
    public:
    typedef std::vector<FileInformation>  type_file_container;
    FileInformationManagement();
    void addFileInformation(const FileInformation& file_information);
    void applyFilter(std::function<bool(const FileInformation&)> function);
    void showFiles();
    void sortByDate();
    FileInformation getFile();
    void reset();
    private:
    type_file_container::iterator begin_it;
    type_file_container::iterator end_it;
    type_file_container file_container;
};