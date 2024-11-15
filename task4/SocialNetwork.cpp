#include "SocialNetwork.h"
#include <iostream>
#define WINDOWS "Windows"

void SocialNetwork::init(const std::string networkName, const int minAge)
{
	this->networkName = networkName;
	this->age = minAge;
	this->profiles.init();
}

void SocialNetwork::clear()
{
	this->networkName = "";
	this->age = 0;
	this->profiles.clear();
}

std::string SocialNetwork::getNetworkName() const
{
	return this->networkName;
}

int SocialNetwork::getMinAge() const
{
	return this->age;
}

bool SocialNetwork::addProfile(const Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < this->age)
	{
		return false;
	}
	this->profiles.add(profile_to_add);
	return true;
}

std::string SocialNetwork::getWindowsDevices() const
{
    std::string str = "";
    ProfileNode* currProfile = this->profiles.get_first();
    while (currProfile != nullptr)
    {
        DeviceNode* currDevice = currProfile->get_data().getOwner().getDevices().get_first();
        while (currDevice != nullptr) // Iterate through devices of the current profile
        {
            if (currDevice->get_data().getOS().find(WINDOWS) != std::string::npos)
            {
                if (!str.empty())
                {
                    str += ", ";
                }
                str += "[" + std::to_string(currDevice->get_data().getID());
                str += ", " + currDevice->get_data().getOS();
                str += "]";
            }
            currDevice = currDevice->get_next();
        }
        currProfile = currProfile->get_next();
    }
    return str;
}