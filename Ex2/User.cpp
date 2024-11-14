#include "User.h"
#include <iostream>

void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this->id = id;
	this->username = username;
	this->age = age;
	this->devices.init();
}

void User::clear()
{
	this->age = 0;
	this->id = 0;
	this->username = "";
	this->devices.clear();
}

unsigned int User::getID() const
{
	return this->id;
}

std::string User::getUserName() const
{
	return this->username;
}

unsigned int User::getAge() const
{
	return this->age;
}

DevicesList& User::getDevices()
{
	return this->devices;
}

void User::addDevice(const Device newDevice)
{
	this->devices.add(newDevice);
}

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