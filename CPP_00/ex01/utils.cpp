#include "my_awesome_phonebook.hpp"

bool    validate_input(std::string &input)
{
    for (std::size_t i = 0; i < input.length(); i++)
        if (!isspace(static_cast<unsigned char>(input[i])))
            return (true);
    return (false);
}

bool    is_numeric(std::string &input)
{
    int start = 0;

    if (input.size() > 1 && input[0] == '+')
        start = 1;
    for (std::size_t i = start; i < input.size(); i++)
        if (!std::isdigit(input[i]))
            return (false);
    return (true);
}

std::string truncate_space(std::string &input)
{
    std::size_t i = 0;

    while (i < input.size() && std::isspace(input[i]))
        i++;
    return (input.substr(i));
}

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
