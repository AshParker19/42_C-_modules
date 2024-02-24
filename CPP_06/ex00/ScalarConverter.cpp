#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) 
{
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

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

int ScalarConverter::isChar(const std::string &str)
{
    if (str.empty() || str.length() != 3 || str[0] != '\'' || str[2] != '\''
        || !isprint(str[1]))
        return (0);
    return (1);
}

bool ScalarConverter::isInteger(const std::string& str) 
{
    size_t i = 0;

    if (str.empty())
        return (false);
    if (str[0] == '+' || str[0] == '-') 
    {
        if (str.size() == 1)
            return (false);
        else
            i = 1;
    }
    for (; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

int ScalarConverter::isFloatDouble(const std::string& str)
{
    bool hasDecimal = false, hasExponent = false, hasF = false;
    size_t i = 0;

    if (str.empty() || str.size() == 1) 
        return (0);
    if (str[0] == '+' || str[0] == '-') 
        i = 1;
    for (; i < str.size(); i++)
    {
        if (str[i] == '.') 
        {
            if (hasDecimal || hasExponent) 
                return (0);
            hasDecimal = true;
        } 
        else if (str[i] == 'e' || str[i] == 'E') 
        {
            if (hasExponent) 
                return (0);
            hasExponent = true;
            if (i + 1 < str.size() && (str[i + 1] == '+' || str[i + 1] == '-')) 
                i++;
        }
        else if (str[i] == 'f' && i == str.size() - 1)
            hasF = true;
        else if (!isdigit(str[i]))
            return (0); 
    }
    if (hasF)
        return (2);
    else
        return (3);
}

int ScalarConverter::isPseudoLiteral(const std::string& str)
{
    if (str == "-inff" || str == "+inff")
        return (4);
    else if (str == "-inf" || str == "+inf" || str == "nan")
        return (5);
    return (0);
}

int ScalarConverter::identifyType(const std::string &str)
{
    if (isChar(str))
        return (0);
    else if (isInteger(str) && validateLimits(str))
        return (1);
    else if (isFloatDouble(str) == 2)
        return (2);
    else if (isFloatDouble(str) == 3)
        return (3);
    else if (isPseudoLiteral(str) == 4)
        return (4);
    else if (isPseudoLiteral(str) == 5)
        return (5);
    return (-1);
}

void ScalarConverter::convertFromChar(const std::string &str)
{
    char c = str[1];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromInt(const std::string &str)
{
    int i = std::atoi(str.c_str());
    char c = (i >= 32 && i <= 126) ? static_cast<char>(i) : '?';
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    std::cout << "char: ";
    if(c == '?')
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << "'" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string &str)
{
    float f = std::atof(str.c_str());
    int i = static_cast<int>(f);
    char c = (i >= 32 && i <= 126) ? static_cast<char>(i) : '?';
    double d = static_cast<double>(f);

    std::cout << "char: ";
    if(c == '?')
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &str)
{
    double d = std::atof(str.c_str());
    int i = static_cast<int>(d);
    char c = (i >= 32 && i <= 126) ? static_cast<char>(i) : '?';
    float f = static_cast<float>(d);

    std::cout << "char: ";
    if (c == '?')
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << "'" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromFloatLit(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << std::endl;
    std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
}

void ScalarConverter::convertFromDoubleLit(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << "f" << std::endl; 
    std::cout << "double: " << str << std::endl;
}

void ScalarConverter::convertMain(const std::string &str)
{
    int type = identifyType(str);

    if (type == 0)
        ScalarConverter::convertFromChar(str);
    else if (type == 1)
        ScalarConverter::convertFromInt(str);
    else if (type == 2)
        ScalarConverter::convertFromFloat(str);
    else if (type == 3)
        ScalarConverter::convertFromDouble(str);
    else if (type == 4)
        ScalarConverter::convertFromFloatLit(str);
    else if (type == 5)
        ScalarConverter::convertFromDoubleLit(str);
}
