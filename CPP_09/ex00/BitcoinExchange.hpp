#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange
{
    private:
        std::ifstream inputFile;
        std::ifstream fileDB;
        std::string tempDate;
        double tempAmount;
        std::map<std::string, double> DB;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void validateInputFile(const std::string &path);
        void validateFileDB();
        void validateDBLine(const std::string &content);
        void validateDate(const std::string &date, int flag);
        void validateAmount(const std::string &price, int flag);
        void readStoreDB();
        void proceedInputFile();
        void validateInputFileLine(const std::string &content);
        void calculateResult();
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

    class ContentException : public std::exception
    {
        private:
            std::string msg;
        public:
            ContentException(const std::string& message);
            ~ContentException() throw();

            virtual const char* what() const throw();
    };
};


#endif