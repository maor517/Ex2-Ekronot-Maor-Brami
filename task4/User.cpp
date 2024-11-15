#include "User.h"
#include <iostream>

/*
function initializes a user
input: id - the user's id, username - the user's username, age - the user's age
output: none
*/
void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this->id = id;
	this->username = username;
	this->age = age;
	this->devices.init();
}


/*
function clears the user
input: none
output: none
*/
void User::clear()
{
	this->age = 0;
	this->id = 0;
	this->username = "";
	this->devices.clear();
}

/*
function returns the user's id
input: none
output: the user's id
*/
unsigned int User::getID() const
{
	return this->id;
}

/*
function returns the user's user name
input: none
output: the user's user name
*/
std::string User::getUserName() const
{
	return this->username;
}

/*
function returns the user's age
input: none
output: the user's age
*/
unsigned int User::getAge() const
{
	return this->age;
}

/*
function returns the user's devices
input: none
output: the user's devices
*/
DevicesList& User::getDevices()
{
	return this->devices;
}

/*
function adds a new device to the device list
input: newDevice - the new device
output: none
*/
void User::addDevice(const Device newDevice)
{
	this->devices.add(newDevice);
}

/*
function checks if all of the user's devices are on
input: none
output: true if the user's devices are on, or false if they are not
*/
bool User::checkIfDevicesAreOn() const
{
	DeviceNode* curr = this->devices.get_first();
	while (curr != nullptr)
	{
		if (!curr->get_data().isActive())
		{
			return false;
		}
		curr = curr->get_next();
	}
	return true;
}