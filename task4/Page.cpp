#include <iostream>
#include "Page.h"

void Page::init()
{
	this->posts = "";
	this->status = "";
}

std::string Page::getPosts() const
{
	return this->posts;
}

std::string Page::getStatus() const
{
	return this->status;
}

void Page::clearPage()
{
	this->posts = "";
}

void Page::setStatus(const std::string status)
{
	this->status = status;
}

void Page::addLineToPosts(const std::string new_line)
{
	this->posts += new_line + "\n";
}