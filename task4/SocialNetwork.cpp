#include "SocialNetwork.h"
#include <iostream>
#define WINDOWS "Windows"

/*
function initializes a social network
input: networkName - the name of the network, minAge - the minimum age for the social network
output: none
*/
void SocialNetwork::init(const std::string networkName, const int minAge)
{
	this->networkName = networkName;
	this->age = minAge;
	this->profiles.init();
}

/*
function clears the social network
input: none
output: none
*/
void SocialNetwork::clear()
{
	this->networkName = "";
	this->age = 0;
	this->profiles.clear();
}

/*
function returns the network name
input: none
output: the network name
*/
std::string SocialNetwork::getNetworkName() const
{
	return this->networkName;
}

/*
function returns the age
input: none
output: the age of the network
*/
int SocialNetwork::getMinAge() const
{
	return this->age;
}

/*
function adds a profile to the network
input: profile_to_add - the profile that is added to the network
output: false if the profile's is lower then the minimum age or true if it is not
*/
bool SocialNetwork::addProfile(const Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < this->age)
	{
		return false;
	}
	this->profiles.add(profile_to_add);
	return true;
}

/*
function returns all of the windows devices
input: none
output: all of the windows devices
*/
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