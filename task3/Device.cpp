#include "Device.h"
#include <iostream>

std::string Device::getOS() const
{
	return this->os;
}

bool Device::isActive() const
{
	return this->state;
}

void Device::activate()
{
	this->state = true;
}

void Device::deactivate()
{
	this->state = false;
}

void Device::init(unsigned int id, DeviceType type, std::string os)
{
	this->id = id;
	this->type = type;
	this->os = os;
	this->state = true;
}

unsigned int Device::getID() const
{
	return this->id;
}

DeviceType Device::getType() const
{
	return this->type;
}