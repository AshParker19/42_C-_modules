#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact()
{
    first_name = "";
}

// setters
void    Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void    Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void    Contact::set_nick_name(std::string nick_name)
{
    this->nick_name = nick_name;
}

void    Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}

void    Contact::set_darkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

// getters
const std::string &Contact::get_first_name(void) const
{
    return (first_name);
}
const std::string &Contact::get_last_name(void) const
{
    return (last_name);
}
const std::string &Contact::get_nick_name(void) const
{
    return (nick_name);
}

const std::string &Contact::get_phone_number(void) const
{
    return (phone_number);
}

const std::string &Contact::get_darkest_secret(void) const
{
    return (darkest_secret);
}

bool    Contact::name_is_empty()
{
    return (first_name.empty());
}
