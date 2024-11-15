#include "Profile.h"

void Profile::init(User& owner)
{
    this->owner = &owner;
    this->friendList.init();
    this->page.init();
}

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

User Profile::getOwner() const
{
    return *owner;
}

void Profile::setStatus(const std::string new_status)
{
    this->page.setStatus(new_status);
}

void Profile::addPostToProfilePage(const std::string post)
{
    this->page.addLineToPosts(post);
}

void Profile::addFriend(const User& friend_to_add)
{
    this->friendList.add(friend_to_add);
}

std::string Profile::getPage() const
{
    return ("Status: " + this->page.getStatus() + "\n*******************\n*******************\n" + this->page.getPosts());
}

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
