#include <string>
#include "ProfileList.h"
#include "UserList.h"
#include "DeviceList.h"

class SocialNetwork
{
public:
	void init(const std::string networkName, const int minAge);
	void clear();
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(const Profile profile_to_add);
	std::string getWindowsDevices() const;
private:
	std::string networkName;
	int age;
	ProfileList profiles;
};