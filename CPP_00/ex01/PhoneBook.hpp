#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "my_awesome_phonebook.hpp"
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact     contacts[8];
        std::string data[5];

    public:

        // default constructor
        PhoneBook();

        // dispays message 
        void    greeting();
        void    put_msg(std::string msg, bool no_nl, std::string color);
        void    put_msg(std::string msgs[], int size, std::string color);

        // waits sor user's input
        void    input_loop();

        // adds a new contactto the list
        void    add();

        // looks for s apecific contact
        void    search();

        // prints a table of all the contacts
        bool    display_contacts();
};

#endif