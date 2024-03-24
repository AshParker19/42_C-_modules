#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception> 

class BitcoinExchange
{
    private:
        std::ifstream inputFile;
        std::ifstream fileDB;
        std::string tempDate;
        int tempAmount;
        std::map<std::string, int> DB;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void validateInputFile(const std::string &path);
        void validateFileDB();
        bool validateLine(const std::string &content, int flag, char sepcontent);
        bool validateDate(const std::string &date, int flag);
        bool validateAmount(const std::string &price, int flag);
        void readStoreDB();
        void proceedInputFile();
        void putError(int flag);
        std::string trim(const std::string &str);
    
    class WrongDataBaseFileFormatException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

     class InvalidDataBaseFileException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class DataBaseRowErrorException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
    class WrongDateFormatException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class InvalidFloatValueException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class InvalidPriceException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class BitcoinDidNotExistException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class CouldNotOpenFileException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class WrongHeadingException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class InputFileRowErrorException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class OutOfLimitsAmountException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

};

#endif