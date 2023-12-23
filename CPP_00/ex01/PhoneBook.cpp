#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <stdlib.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    data[0] = "First name";
    data[1] = "Last name";
    data[2] = "Nick name";
    data[3] = "Phone Book";
    data[4] = "Darkest secret";
}

void    PhoneBook::input_loop()
{
    std::string choice;
    std::string options[] = {   "Options: ",
                                "ADD --> \x1b[33msave a new contact",
                                "SEARCH --> \x1b[33mdisplay specific contact",
                                "EXIT --> \x1b[33mquit PhoneBook"};
    std::string wrong_option[] =    {"WRONG OPTION!!!",
                                    "Please select one from the list!"};

    while (1)
    {
        put_msg(options, 4, GREEN);
        put_msg("Enter your choice: ", true, PURPLE);
        std::getline(std::cin, choice);
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

bool    validate_input(std::string input)
{
    for (std::size_t i = 0; i < input.length(); i++)
        if (!isspace(static_cast<unsigned char>(input[i])))
            return (true);
    return (false);
}

void    PhoneBook::add()
{
    std::string info[5];
    static int  i = 0;
    bool        right_input = false;
    std::string wrong_input[] = {"WRONG INPUT!!!", "Please enter a valid input"};
    std::string user_input;

    while (!right_input)
    {
        put_msg("New Contact", false, YELLOW);
        for (int j = 0; j < 5; j++)
        {
            put_msg((data[j] + ": "), true, BLUE);
            user_input.clear();
            std::getline(std::cin, user_input);
            if (std::cin.eof())
                exit (0);
            if (validate_input(user_input))
                info[j] = user_input;
            else
            {
                put_msg(wrong_input, 2, RED);
                j = -1;
            }
        }
        right_input = true;
    }
    contacts[i].set_first_name(info[0]);
    contacts[i].set_last_name(info[1]);
    contacts[i].set_nick_name(info[2]);
    contacts[i].set_phone_number(info[3]);
    contacts[i].set_darkest_secret(info[4]);
    i++;
    if (i == 8)
        i = 0;
}

std::string format_string(std::string input, int pos, int len)
{
    std::string copy;

    copy = input;
    copy[pos] = '.';
    copy = copy.substr(0, len);
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
            output = format_string(contacts[i].get_first_name(), 9, 10);
        else
            output = contacts[i].get_first_name();
        std::cout << CYAN << "|" << RESET << std::right << std::setw(field_w) << output;

        if (contacts[i].get_last_name().size() > 10)
            output = format_string(contacts[i].get_last_name(), 9, 10);
        else 
            output = contacts[i].get_last_name();
        std::cout << CYAN << "|" << RESET << std::right << std::setw(field_w) << output;

        if (contacts[i].get_nick_name().size() > 10)
            output = format_string(contacts[i].get_nick_name(), 9, 10);
        else 
            output = contacts[i].get_nick_name();
        std::cout << CYAN << "|" << RESET << std::right << std::setw(field_w) << output << CYAN << "|";
 }
    std::cout << "\n---------------------------------------------\n" << RESET;
    return (true);
}

void    PhoneBook::search()
{
    int         index = 0;
    bool        right_info = false;
    std::string info[5];
    std::string no_info[] = {"NO INFO!!!", "Please add a contact first"};
    std::string wrong_index[] = {   "WRONG INDEX!!!",
                                    "Please choose an index between \033[32m0 \033[31mand \033[32m7"};

    if (!display_contacts())
        return ;
    while (!right_info)
    {
        put_msg("ENTER THE INDEX: ", true, YELLOW);
        std::string input;
        std::getline(std::cin, input);
        std::stringstream p(input);
        p >> index;
        if (std::cin.eof())
            exit (0);
        if (p.fail() || index < 0 || index > 7)
            put_msg(wrong_index, 2, RED);
        else if (contacts[index].name_is_empty())
            put_msg(no_info, 2, RED);
        else
        {
            info[0] = (data[0] + " --> ") + (YELLOW + contacts[index].get_first_name());
            info[0] = (info[0].length() > 43) ? format_string(info[0], 47, 48) : info[0];
            info[1] = (data[1] + " --> ") + (YELLOW + contacts[index].get_last_name());
            info[1] = (info[1].length() > 43) ? format_string(info[1], 47, 48) : info[1];
            info[2] = (data[2] + " --> ") + (YELLOW + contacts[index].get_nick_name());
            info[2] = (info[2].length() > 43) ? format_string(info[2], 47, 48) : info[2];
            info[3] = (data[3] + " --> ") + (YELLOW + contacts[index].get_phone_number());
            info[3] = (info[3].length() > 43) ? format_string(info[3], 47, 48) : info[3];
            info[4] = (data[4] + " --> ") + (YELLOW + contacts[index].get_darkest_secret());
            info[4] = (info[4].length() > 43) ? format_string(info[4], 47, 48) : info[4];
            put_msg(info, 5, PURPLE);
            right_info = true;
        }
    }
}