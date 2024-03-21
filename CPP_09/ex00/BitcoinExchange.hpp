#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>

class BitcoinExchange
{
    private:
        std::ifstream fileDB;
        std::map<std::string, float> DB;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void validateFileDB(const std::string &path);
        void validateLine(const std::string &content);
        void validateDate(const std::string &date);
        void validatePrice(float price);
        void readStoreDB();
    
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

    class InvalidPriceException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

#endif