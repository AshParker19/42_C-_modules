#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        Contact contacts[8];

    void    add_contact(Contact& contact);
    
    void    search();
    void    add();


    bool    prompt_input(std::string& str);
    bool    prompt_input(size_t& nbr);
};

#endif