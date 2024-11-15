#include "Device.h"
#include <iostream>
/*
function returns the device's OS
input: none
output: the device's OS
*/
std::string Device::getOS() const
{
	return this->os;
}

/*
function returns the device's state
input: none
output: true if the device is active or false if it is not
*/
bool Device::isActive() const
{
	return this->state;
}

/*
function turns the device on
input: none
output: none
*/
void Device::activate()
{
	this->state = true;
}

/*
function turns the device off
input: none
output: none
*/
void Device::deactivate()
{
	this->state = false;
}
/*
function initializes the device object
input: id - the device's id, type - the device's type, os - the device's os
output: none
*/
void Device::init(unsigned int id, DeviceType type, std::string os)
{
	this->id = id;
	this->type = type;
	this->os = os;
	this->state = true;
}

/*
function returns the device's id
input: none
output: the device's id
*/
unsigned int Device::getID() const
{
	return this->id;
}

/*
function returns the device's type
input: none
output: the device's type
*/
DeviceType Device::getType() const
{
	return this->type;
}