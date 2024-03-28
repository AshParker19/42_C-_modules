#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other; // TODO:
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::validateInputFile(const std::string &path)
{
    inputFile.open(path.c_str());
    if (inputFile.fail() || inputFile.peek() == EOF)
    {
        if (inputFile)
            inputFile.close();
        throw (InvalidDataBaseFileException());
    }
}

void BitcoinExchange::validateFileDB()
{
    fileDB.open("data.csv");
    if (fileDB.fail() || fileDB.peek() == EOF)
    {
        if (fileDB)
            fileDB.close();
        throw (CouldNotOpenFileException());
    }
}

void BitcoinExchange::validateDate(const std::string &date, int flag)
{
    int yearMonthDay[3];
    
    // check date's structure
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        if (flag == 0)
            throw (WrongDateFormatException());
        throw (ContentException("bad input => " + date));
    }

    yearMonthDay[0] = std::atoi(date.substr(0, 4).c_str());
    yearMonthDay[1] = std::atoi(date.substr(5, 2).c_str());
    yearMonthDay[2] = std::atoi(date.substr(8, 2).c_str());

    if (yearMonthDay[0] == 2009 && yearMonthDay[1] == 1 && yearMonthDay[2] < 2)
            throw (BitcoinDidNotExistException());

    if (yearMonthDay[0] < 2009 || yearMonthDay[1] < 1 || yearMonthDay[2] < 1 ||
        yearMonthDay[0] > 2024 || yearMonthDay[1] > 12 || yearMonthDay[2] > 31) //TODO: limit it by the date of the evaluation day
    {
        throw (WrongDateFormatException()); // TODO: change to a more suitable exception
    }
    
    tempDate = date;
}

void BitcoinExchange::validateAmount(const std::string &amount, int flag)
{
    int numDot = 0;
    size_t dotPos;

    for (size_t i = 0; i < amount.size(); i++)
    {
        if (amount[i] == '.')
            numDot++;
    }
    
    if (numDot != 0 && numDot != 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        throw (ContentException("not a positive number."));
    }
    
    dotPos = amount.find('.');
    if (dotPos == amount.size() - 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        throw (ContentException("not a positive number."));
    }
    tempAmount = std::atof(amount.c_str());
    if (flag == 0 && tempAmount < 0) //TODO: add a limit for BTC ATH at the day of submission
        throw (InvalidPriceException());
    if (flag == 1 && (tempAmount < 0 || tempAmount > 10000))
        throw (ContentException("too large a number."));
}

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

    try 
    {
        std::getline(fileDB, content);
        if (content.empty())
            throw (DataBaseRowErrorException());
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
    catch (const std::exception &e)
    {
        if (fileDB)
            fileDB.close();
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void BitcoinExchange::calculateResult()
{
    std::map<std::string, double>::iterator it = DB.lower_bound(tempDate);

    double finalPrice = it->second;
    double finalAmount = tempAmount;
    std::cout << tempDate << " => "<< finalAmount << " = " << finalAmount * finalPrice << "\n";
}

void BitcoinExchange::proceedInputFile()
{
    std::string content;

    std::getline(inputFile, content);
    if (content.empty())
        throw (InputFileRowErrorException());
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

const char *BitcoinExchange::WrongDataBaseFileFormatException::what(void) const throw()
{
    return ("Wrong format of database file.");
}

const char *BitcoinExchange::InvalidDataBaseFileException::what(void) const throw()
{
    return ("Invalid database file.");
}

const char *BitcoinExchange::DataBaseRowErrorException::what(void) const throw()
{
    return ("Database row error.");
}

const char *BitcoinExchange::WrongDateFormatException::what(void) const throw()
{
    return ("Wrong date format.");
}

const char *BitcoinExchange::InvalidFloatValueException::what(void) const throw()
{
    return ("Invalid float value.");
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

const char *BitcoinExchange::InputFileRowErrorException::what(void) const throw()
{
    return ("Input file row error.");
}

const char *BitcoinExchange::OutOfLimitsAmountException::what(void) const throw()
{
    return ("Out of limits amount.");
}

BitcoinExchange::ContentException::ContentException(const std::string& message) : msg(message) {}

BitcoinExchange::ContentException::~ContentException() throw() {}

const char *BitcoinExchange::ContentException::what(void) const throw()
{
    return (msg.c_str());
}