#include "Profile.h"

/*
function initializes the profile
input: owner - the owner of the profile
output: none
*/
void Profile::init(User& owner)
{
    this->owner = &owner;
    this->friendList.init();
    this->page.init();
}

/*
function clears the profile
input: none
output: none
*/
void Profile::clear()
{
    if (owner) 
    {
        this->owner = nullptr;
    }
    this->friendList.clear();
    this->page.clearPage();
    this->page.setStatus("");
}

/*
function returns the owner of the profile
input: none
output: the owner of the profile
*/
User Profile::getOwner() const
{
    return *owner;
}


/*
function sets the status of the profile
input: new_status - the new status of the profile
output: none
*/
void Profile::setStatus(const std::string new_status)
{
    this->page.setStatus(new_status);
}

/*
function adds a new post to the profile
input: post - the new post
output: none
*/
void Profile::addPostToProfilePage(const std::string post)
{
    this->page.addLineToPosts(post);
}

/*
function adds a user to the friend list
input: friend_to_add - the friend that is added to the friend list
output: none
*/
void Profile::addFriend(const User& friend_to_add)
{
    this->friendList.add(friend_to_add);
}

/*
function returns the profile's page
input: none
output: none
*/
std::string Profile::getPage() const
{
    return ("Status: " + this->page.getStatus() + "\n*******************\n*******************\n" + this->page.getPosts());
}

/*
function returns the friend list 
input: none
output: the friend list
*/
std::string Profile::getFriends() const
{
    std::string str = "";
    UserNode* curr = this->friendList.get_first();
    while (curr != nullptr)
    {
        if (!str.empty())
        {
            str += ",";
        }
        str += curr->get_data().getUserName();
        curr = curr->get_next();
    }
    return str;
}

/*
function returns friends with same name length as the owner's name
input: none
output: friends with same name length as the owner's name
*/
std::string Profile::getFriendsWithSameNameLength() const
{
    std::string str = "";
    UserNode* curr = this->friendList.get_first();
    while (curr != nullptr)
    {
        if (this->owner->getUserName().length() == curr->get_data().getUserName().length())
        {
            if (!str.empty())
            {
                str += ",";
            }
            str += curr->get_data().getUserName();
        }
        curr = curr->get_next();
    }
    return str;
}
