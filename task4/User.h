#include <string>
#include "DeviceList.h"

class User
{
public:
	void init(const unsigned int id, const std::string username, const unsigned int age);
	void clear();
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices();
	void addDevice(const Device newDevice);
	bool checkIfDevicesAreOn() const;
private:
	unsigned int id;
	std::string username;
	unsigned int age;
	DevicesList devices;
};