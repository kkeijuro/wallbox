class DeviceInformation {
public:
    DeviceInformation(std::string connection_type, std::string name, uint64_t uid);
    std::string getConnectionType() const;
    std::string getName() const;
    uint64_t getUID() const;

private:
    std::string connection_type;
    std::string name;
    uint64_t uid;
};

class DeviceInformationParser {
    public:
    virtual std::string parseDevice(const DeviceInformation& device_information) = 0;
};

class JSonParser: public DeviceInformationParser {
    public:
    std::string parseDevice(const DeviceInformation& device_information);
};

class TextParser: public DeviceInformationParser {
    public:
    std::string parseDevice(const DeviceInformation& device_information);
};