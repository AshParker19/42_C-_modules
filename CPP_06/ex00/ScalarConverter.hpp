#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);
        ~ScalarConverter();
    
    public:
        static void convertToChar(const std::string &str);
        static void convertToInt(const std::string &str);
        static void convertToFloat(const std::string &str);
        static void convertToDouble(const std::string &str);

        static void convertMain(const std::string &str);
        static int  determineType(const std::string &str);
        static bool isChar(const std::string &str);
        static bool isInt(const std::string &str);
        static bool isFloatDouble(const std::string &str, int type);
};

#endif