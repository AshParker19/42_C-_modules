#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) 
{
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convertToChar(const std::string &str)
{
    int status;

    std::cout << "char: ";
    status = validateChar(str);
    if (status == 0)
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (status == 1)
    {
        std::cout << "Non displayable" << std::endl;
        return ;
    }
    std::cout << static_cast<char>(std::atoi(str.c_str())) << std::endl;
}

bool ScalarConverter::validateLimits(const std::string &str)
{
    std::string trimmed = str;
    size_t firstNonZero;

    if (str.empty())
        return (false);

    if (trimmed[0] == '-' || trimmed[0] == '+')
        trimmed = trimmed.substr(1);
    firstNonZero = trimmed.find_first_not_of('0');
    if (firstNonZero != std::string::npos)
        trimmed = trimmed.substr(firstNonZero);
    else
        trimmed = "0";

    if (str[0] == '-') 
    {
        if (trimmed.length() > 10) 
            return (false);
        if (trimmed.length() == 10 && trimmed > "2147483648")
            return (false);
    } 
    else 
    {
        if (trimmed.length() > 10)
            return (false);
        if (trimmed.length() == 10 && trimmed > "2147483647")
            return (false);
    }
    return (true);
}

void ScalarConverter::convertToInt(const std::string &str)
{
    std::cout << "int: ";
    if (!validateInt(str) || !validateLimits(str))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    std::cout << static_cast<int>(std::atoi(str.c_str())) << std::endl;
}

void ScalarConverter::convertToFloat(const std::string &str)
{
    (void)str;
}

void ScalarConverter::convertToDouble(const std::string &str)
{
    (void)str;
}

int ScalarConverter::validateChar(const std::string &str)
{
    if (str.empty() || str.length() != 3 || str[0] != '\'' || str[2] != '\'')
        return (0);
    if (!isprint(str[1]))
        return (1);
    return (2);
}

bool ScalarConverter::validateInt(const std::string &str)
{
    if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')
        return (false);
    for (std::size_t i = 1; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool ScalarConverter::validateFloatDouble(const std::string &str, int type)
{
    (void)str;
    (void)type;
    return (true);
}
