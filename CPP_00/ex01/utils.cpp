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
