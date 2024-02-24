#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);
        ~ScalarConverter();
    
    public:
        static int isChar(const std::string &str);
        static bool isInteger(const std::string &str);
        static int isFloatDouble(const std::string &str);

        static bool validateLimits(const std::string &str);
        static int isPseudoLiteral(const std::string &str);
        static void errorImpossible();
        
        static void convertMain(const std::string &str);
        static void convertFromChar(const std::string &str);
        static void convertFromInt(const std::string &str);
        static void convertFromFloat(const std::string &str);
        static void convertFromDouble(const std::string &str);
        static void convertFromFloatLit(const std::string &str);
        static void convertFromDoubleLit(const std::string &str);
};

#endif