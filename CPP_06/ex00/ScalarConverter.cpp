#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convertToChar(const std::string &str)
{

}

void ScalarConverter::convertToInt(const std::string &str)
{
    // check min max int
    std::cout << static_cast<char>(std::atoi(str.c_str()));
}

void ScalarConverter::convertToFloat(const std::string &str)
{

}

void ScalarConverter::convertToDouble(const std::string &str)
{

}

bool ScalarConverter::isChar(const std::string &str)
{
    if (str.empty() || str.length() != 3 || str[0] != '\'' || str[2] != '\'')
        return (false);
    return (true);
}

bool ScalarConverter::isInt(const std::string &str)
{
    if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')
        return (false);
    for (int i = 1; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool ScalarConverter::isFloatDouble(const std::string &str, int type)
{

}

int ScalarConverter::determineType(const std::string &str)
{
    if (isChar(str))
        return (0);
    else if (isInt(str))
        return (1);
    else if (isFloatDouble(str, 0))
        return (2);
    else if (isFloatDouble(str, 1))
        return (3);
    return (-1);
}

void ScalarConverter::convertMain(const std::string &str)
{
    int type;

    type = determineType(str);
    switch (type)
    {
        case (0):
            convertToChar(str);
            break ;
        
        case (1):
            convertToInt(str);
            break ;
        
        case (2):
            convertToFloat(str);
            break ;
        
        case (3):
            convertToDouble(str);
            break ;
        
        default:
            std::cout << "Error: Unknown type" << std::endl;
    } 
}
