#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

void    PhoneBook::input_loop()
{
    std::string choice;
    std::string options[] = {   "Options: ",
                                "ADD --> save a new contact",
                                "SEARCH --> display specific contact",
                                "EXIT --> quit PhoneBook"};
    std::string wrong_option[] =    {"WRONG OPTION!!!",
                                    "Please select one from the list!"};

    while (1)
    {
        put_msg(options, 4, GREEN);
        put_msg("Enter your choice: ", true, PURPLE);
        getline(std::cin, choice);
        if (std::cin.eof())
            break ;
        if (choice == "ADD")
            add();
        else if (choice == "SEARCH")
            search();
        else if (choice == "EXIT")
            exit(0);
        else
            put_msg(wrong_option, 2, RED);
    }
}

void    PhoneBook::add()
{
    static int  i = 0;
    std::string user_input; //TODO: check if it's input is empty in this funciotn

    put_msg("New Contact", false, YELLOW);

    put_msg("First name: ", true, YELLOW);
    std::getline(std::cin, user_input);
    contacts[i].set_first_name(user_input);
    user_input.clear();

    put_msg("Last name: ", true, YELLOW);
    std::getline(std::cin, user_input);
    contacts[i].set_last_name(user_input);
    user_input.clear();

    put_msg("Nick name: ", true, YELLOW);
    std::getline(std::cin, user_input);
    contacts[i].set_nick_name(user_input);
    user_input.clear();

    put_msg("Phone number: ", true, YELLOW);
    std::getline(std::cin, user_input);
    contacts[i].set_phone_number(user_input);
    user_input.clear();

    put_msg("Darkest secret: ", true, YELLOW);
    std::getline(std::cin, user_input);
    contacts[i].set_darkest_secret(user_input);
    user_input.clear();

    i++;
    if (i == 8)
        i = 0;
}

std::string format_string(std::string input)
{
    std::string copy;

    copy = input;
    copy[9] = '.';
    copy = copy.substr(0, 10);
    return (copy);
}

bool    PhoneBook::display_contacts()
{
    int         field_w;
    std::string output;

    field_w = 10;
    std::cout   << CYAN << "---------------------------------------------\n" << RESET;
    std::cout   << CYAN << "|" << GREEN << "   Index  " << CYAN << "|"  
                << GREEN << "First name" << CYAN << "|" << GREEN << "Last  name"
                << CYAN << "|" << GREEN << " Nickname " << CYAN << "|";
    if (contacts[0].name_is_empty())
    {
        std::cout << CYAN << "\n---------------------------------------------\n" << RESET;
        return (false);
    }
    for (int i = 0; i <= 7; i++)
    {
        if (contacts[i].name_is_empty())
            break ;
    
        std::cout << CYAN << "\n---------------------------------------------\n";
        std::cout << CYAN << "|" << RESET << std::right << std::setw(field_w) << i;

        if (contacts[i].get_first_name().size() > 10)
            output = format_string(contacts[i].get_first_name());
        else
            output = contacts[i].get_first_name();
        std::cout << CYAN << "|" << RESET << std::right << std::setw(field_w) << output;

        if (contacts[i].get_last_name().size() > 10)
            output = format_string(contacts[i].get_last_name());
        else 
            output = contacts[i].get_last_name();
        std::cout << CYAN << "|" << RESET << std::right << std::setw(field_w) << output;

        if (contacts[i].get_nick_name().size() > 10)
            output = format_string(contacts[i].get_nick_name());
        else 
            output = contacts[i].get_nick_name();
        std::cout << CYAN << "|" << RESET << std::right << std::setw(field_w) << output << CYAN << "|";
 }
    std::cout << "\n---------------------------------------------\n" << RESET;
    return (true);
}

void    PhoneBook::search()
{
    int index = 0;
    std::string info[5];
    int right_index = false;
    std::string wrong_index[] = {   "Wrong index!!!", 
                                    "Please choose an index between 0 and 7"};

    if (!display_contacts())
        return ;
    while (!right_index)
    {
        put_msg("ENTER THE INDEX: ", true, YELLOW);
        std::string input;
        getline(std::cin, input);
        std::stringstream p(input);

        p >> index;

        if (p.fail() || index < 0 || index > 7)
        {
            put_msg(wrong_index, 2, RED);
            continue ;
        }
        right_index = true;
    }
    for (int i = 0; i <= 7; i++)
    {
        if (i == index)
        {
            info[0] = "First name --> " + contacts[i].get_first_name();
            info[1] = "Last name --> " + contacts[i].get_last_name();
            info[2] = "Nick name --> " + contacts[i].get_nick_name();
            info[3] = "Phone number --> " + contacts[i].get_phone_number();
            info[4] = "Darkest secret --> " + contacts[i].get_darkest_secret();
            put_msg(info, 5, GREEN);
        }
    }
}