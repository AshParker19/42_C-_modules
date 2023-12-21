#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string name;
        std::string last_name;
        std::string nick_name;
        int         phone_number;
        std::string darkst_secret;
    
    public:
        Contact(std::string name, std::string last_name, std::string nick_name,
                int phone_number, std::string darkest_secret);

        // getters
        std::string get_name();
        std::string get_last_name();
        std::string get_nick_name();
};

#endif