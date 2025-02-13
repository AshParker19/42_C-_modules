#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
        return (*this);
    tempDate = other.tempDate;
    tempAmount = other.tempAmount;
    DB = other.DB;

    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::validateFile(const std::string &path)
{
    inputFile.open(path.c_str());
    if (inputFile.fail() || inputFile.peek() == EOF)
    {
        if (inputFile)
            inputFile.close();
        throw (CouldNotOpenFileException());
    }
}

void BitcoinExchange::validateFile()
{
    fileDB.open("data.csv");
    if (fileDB.fail() || fileDB.peek() == EOF)
    {
        if (fileDB)
            fileDB.close();
        throw (CouldNotOpenFileException());
    }
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void BitcoinExchange::validateDate(const std::string &date, int flag)
{
    int year, month, day;
    
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        if (flag == 0)
            throw (WrongDateFormatException());
        throw (ContentException("bad input => " + date));
    }

    year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 ||
        (year == 2009 && (month < 1 || (month == 1 && day < 2))) ||
        year > 2024 ||
        (year == 2024 && (month > 4 || (month == 4 && day > 22))) || // submission day
        (month < 1 || month > 12) ||
        (day < 1 || day > 31) ||
        (month == 2 && day > 29) ||
        (month == 2 && day == 29 && !isLeapYear(year)) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
        { 
            throw WrongDateFormatException();
        }
    
    tempDate = date;
}

void BitcoinExchange::validateAmount(const std::string &amount, int flag)
{
    int numDot = 0;
    size_t dotPos;

    for (size_t i = 0; i < amount.size(); i++)
    {
        if (!std::isdigit(amount[i]) && amount[i] != '.')
        {
            if (flag == 0)
                throw (DataBaseRowErrorException());
            throw (InputFileRowErrorException());
        }
        if (amount[i] == '.')
            numDot++;
    }
    
    if (numDot != 0 && numDot != 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        throw (InputFileRowErrorException());
    }
    
    dotPos = amount.find('.');
    if (dotPos == amount.size() - 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        throw (InputFileRowErrorException());
    }
    tempAmount = std::atof(amount.c_str());
    if (flag == 0 && (tempAmount < 0 || tempAmount > 73737.94))
        throw (InvalidPriceException());
    if (flag == 1)
    {
        if (tempAmount < 0)
            throw (ContentException("not a positive number."));
        else if (tempAmount > 1000)
            throw (ContentException("too large a number."));
    }
}

/*
    flag 0 --> Database
    flag 1 --> InputFile
*/
void BitcoinExchange::validateLine(const std::string &content, int flag, char sep)
{
    size_t numSep = 0;
    size_t sepPos;
    std::string afterSep;

    for (size_t i = 0; i < content.size(); i++)
    {
        if (content[i] == sep)
            numSep++;
    }
    if (numSep != 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        throw (ContentException("bad input => " + content));
    }

    sepPos = content.find(sep);
    if (sepPos == content.size() - 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        throw (ContentException("bad input => " + content));
    }
    
    afterSep = content.substr(sepPos + 1);
    if (afterSep.empty() || afterSep.find_first_not_of(" \t\n\r") == std::string::npos)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        throw (ContentException("bad input => " + content));
    }

    validateDate(trim(content.substr(0, sepPos)), flag);
    validateAmount(trim(content.substr(sepPos + 1)), flag);
}

void BitcoinExchange::readStoreDB()
{
    std::string content;

    std::getline(fileDB, content);
    if (content.empty())
        throw (DataBaseRowErrorException());
    content = trim(content);
    if (content != "date,exchange_rate")
        throw (WrongHeadingException());
    while (std::getline(fileDB, content))
    {
        if (content.empty())
            continue;
        validateLine(content, 0, ',');
        DB[tempDate] = tempAmount;
    }
    if (fileDB)
        fileDB.close();
}

void BitcoinExchange::calculateResult()
{
    std::map<std::string, double>::iterator it = DB.lower_bound(tempDate);
    float result;

    if (it != DB.begin() && (it == DB.end() || it->first != tempDate))
        it--;

    result = tempAmount * it->second;
    std::cout << tempDate << " => "<< tempAmount << " = " << result << "\n";
}

void BitcoinExchange::proceedInputFile()
{
    std::string content;

    std::getline(inputFile, content);
    if (content.empty())
        throw (InputFileRowErrorException());
    content = trim(content);
    if (content != "date | value")
        throw (WrongHeadingException());
    while (std::getline(inputFile, content))
    {
        if (content.empty())
            continue;
        try
        {
            validateLine(content, 1, '|');
            calculateResult();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    if (inputFile)
        inputFile.close();
}

std::string BitcoinExchange::trim(const std::string& str)
{
    const std::string whitespace = " \t\n\r\f\v";

    size_t start = str.find_first_not_of(whitespace);
    size_t end = str.find_last_not_of(whitespace);
    return (str.substr(start, end - start + 1));
}

const char *BitcoinExchange::DataBaseRowErrorException::what(void) const throw()
{
    return ("Database row error.");
}

const char *BitcoinExchange::InputFileRowErrorException::what(void) const throw()
{
    return ("Input file row error.");
}

const char *BitcoinExchange::WrongDateFormatException::what(void) const throw()
{
    return ("Wrong date format.");
}

const char *BitcoinExchange::InvalidPriceException::what(void) const throw()
{
    return ("Invalid price.");
}

const char *BitcoinExchange::BitcoinDidNotExistException::what(void) const throw()
{
    return ("Bitcoin was created on 2009-01-02.");
}

const char *BitcoinExchange::CouldNotOpenFileException::what(void) const throw()
{
    return ("Could not open file.");
}

const char *BitcoinExchange::WrongHeadingException::what(void) const throw()
{
    return ("Wrong file heading.");
}

BitcoinExchange::ContentException::ContentException(const std::string& message) : msg(message) {}

BitcoinExchange::ContentException::~ContentException() throw() {}

const char *BitcoinExchange::ContentException::what(void) const throw()
{
    return (msg.c_str());
}