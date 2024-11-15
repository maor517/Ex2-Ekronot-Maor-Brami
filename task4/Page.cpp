#include <iostream>
#include "Page.h"

/*
function initializes the page
input: none
output: none
*/
void Page::init()
{
	this->posts = "";
	this->status = "";
}

/*
function returns the page's posts
input: none
output: the page's posts
*/
std::string Page::getPosts() const
{
	return this->posts;
}

/*
function returns the page's status
input: none
output: the page's status
*/
std::string Page::getStatus() const
{
	return this->status;
}

/*
function clears the page
input: none
output: none
*/
void Page::clearPage()
{
	this->posts = "";
}

/*
function sets a new status for the page
input: status - the new status
output: none
*/
void Page::setStatus(const std::string status)
{
	this->status = status;
}

/*
function adds a new line to the page's posts
input: new_line - the new line that is added to the posts
output: none
*/
void Page::addLineToPosts(const std::string new_line)
{
	this->posts += new_line + "\n";
}