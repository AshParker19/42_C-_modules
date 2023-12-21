#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    private:
        std::string name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        //default constructor
        Contact(); // are we allowed to have initializing lists in a class file?

        //setters
        void        set_name(std::string name);
        void        set_last_name(std::string last_name);
        void        set_nick_name(std::string nick_name);
        void        set_phone_number(std::string phone_number);
        void        set_darkest_secret(std::string darkest_secret);

        // getters
        std::string get_name();
        std::string get_last_name();
        std::string get_nick_name();
        std::string get_phone_number();
        std::string get_darkest_secret();

        bool        name_is_empty();
};

#endif