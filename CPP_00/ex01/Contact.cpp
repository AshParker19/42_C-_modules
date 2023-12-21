#include "Contact.hpp"

// Contact constructor to initialize all the members
Contact::Contact(std::string name, std::string last_name, std::string nick_name,
                int phone_number, std::string darkest_secret)
{
                this->name = name,
                this->last_name = last_name,
                this->nick_name = nick_name,
                this->phone_number = phone_number;
                this->darkst_secret = darkest_secret;
}

std::string Contact::get_name(void)
{
    return (name);
}
std::string Contact::get_last_name(void)
{
    return (last_name);
}
std::string Contact::get_nick_name(void)
{
    return (nick_name);
}
