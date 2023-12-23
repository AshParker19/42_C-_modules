#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void    put_line(int type)
{
    std::string    c1;
    std::string    c2;

    if (type == 0)
    {
        c1 = "╔";
        c2 = "╗";
    }
    else if (type == 1)
    {
        c1 = "╚";
        c2 = "╝";
    }
    std::cout << CYAN;
    std::cout << c1;
    for (int i = 43; i > 0; i--)
        std::cout << "═";
    std::cout << c2;
    std::cout << RESET << "\n";
}

int visible_length(const std::string& str)
{
    int     length = 0;
    bool    in_escape_sequence = false;

    for (std::size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '\033' || str[i] == '\x1b')
            in_escape_sequence = true;
        else if (in_escape_sequence && str[i] == 'm')
            in_escape_sequence = false;
        else if (!in_escape_sequence)
            ++length;
    }
    return (length);
}

void    put_text_center(std::string text, std::string color, bool sides)
{
    int wordlen = visible_length(text);

    if (sides)
        std::cout << CYAN << "║";
    for (int i = 0; i < (43 - wordlen) / 2; i++)
        std::cout << " ";
    if (sides)
    {
        std::cout << color << text << CYAN;
        for (int i = 0; i < (43 - wordlen) / 2; i++)
            std::cout << " ";
        if (wordlen % 2 == 0)
            std::cout << " ";
        if (sides)
            std::cout << "║" << RESET << "\n";
    }
    else
        std::cout << color << text << RESET;
}

void    PhoneBook::greeting(void)
{
    put_line(0);
    put_text_center("Welcome to PhoneBook v.42++", YELLOW, true);
    put_line(1);
}

void    PhoneBook::put_msg(std::string msg, bool no_nl, std::string color)
{
    if (no_nl)
    {
        put_text_center(msg, color, false);
        return ;
    }
    put_line(0);
    put_text_center(msg, color, true);
    put_line(1);
}

void    PhoneBook::put_msg(std::string msgs[], int size, std::string color)
{
    put_line(0);
    for (int i = 0; i < size; i++)
        put_text_center(msgs[i], color, true);
    put_line(1);
}
