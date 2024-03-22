#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : tempDate(NULL), tempPrice(0.0f)
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "Constructor called\n";
}

void BitcoinExchange::validateFileDB(const std::string &path)
{
    if (path.substr(path.find_last_of(".") + 1) != "csv")
        throw (WrongDataBaseFileFormatException());

    fileDB.open(path);
    if (fileDB.fail() || fileDB.peek() == EOF)
    {
        if (fileDB)
            fileDB.close();
        throw (InvalidDataBaseFileException());
    }
}

void BitcoinExchange::validateDate(const std::string &date)
{
    int yearMonthDay[3];
    
    // check date's structure
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw (WrongDateFormatException());

    yearMonthDay[0] = atoi(date.substr(0, 4).c_str());
    yearMonthDay[1] = atoi(date.substr(5, 2).c_str());
    yearMonthDay[2] = atoi(date.substr(8, 2).c_str());

    if (yearMonthDay[0] < 2009 || yearMonthDay[1] < 1 || yearMonthDay[2] < 1 ||
        yearMonthDay[0] > 2024 || yearMonthDay[1] > 12 || yearMonthDay[2] > 31)
        throw (WrongDateFormatException());
    
    if (yearMonthDay[0] == 2009 && yearMonthDay[2] < 2)
        throw (BitcoinDidNotExistException());
    tempDate = date;
}

void BitcoinExchange::validatePrice(const std::string &price)
{
    float floatPrice = 0.0f;

    std::istringstream iss(price); // Use the price string directly
    if (!(iss >> floatPrice) || !iss.eof()) // Check if conversion succeeds and if there's no extra data
        throw InvalidFloatValueException();
    
     if (floatPrice < 0.0f)
        throw InvalidPriceException();
    tempPrice = floatPrice;
}

void BitcoinExchange::validateLine(const std::string &content)
{
    size_t numComma = 0;
    size_t commaPos;
    size_t pricePos;
    bool onlySpaces = false;

    // check if there is only one comma
    for (size_t i = 0; i < content.size(); i++)
    {
        if (content[i] == ',')
            numComma++;
    }
    if (numComma != 1)
        throw (DataBaseRowErrorException());
    
    // check if comma is not the last character in a line
    commaPos = content.find(',');
    if (commaPos == content.size() - 1)
        throw (DataBaseRowErrorException());
    
    /* 
        check if there are any not whitespaces after comma
        find the position of the first not whitespace
    */
    for (size_t i = commaPos + 1; i < content.size(); i++)
    {
        if (!isspace(content[i]))
        {
            onlySpaces = true;
            pricePos = i;
            break;
        }
    }
    if (!onlySpaces)
        throw (DataBaseRowErrorException());

    validateDate(content.substr(0, commaPos));
    validatePrice(content.substr(pricePos));
}

void BitcoinExchange::readStoreDB()
{
    std::string content;

    try 
    {
        std::getline(fileDB, content);
        if (content.empty())
            throw (DataBaseRowErrorException());
        while (std::getline(fileDB, content))
        {
            if (content.empty())
                throw (DataBaseRowErrorException());
            validateLine(content);
            // DB[]
        }
    }
    catch (const std::exception &e)
    {
        if (fileDB)
            fileDB.close();
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


const char *BitcoinExchange::WrongDataBaseFileFormatException::what(void) const throw()
{
    return ("Wrong format of database file");
}

const char *BitcoinExchange::InvalidDataBaseFileException::what(void) const throw()
{
    return ("Invalid database file");
}

const char *BitcoinExchange::DataBaseRowErrorException::what(void) const throw()
{
    return ("Database row error");
}

const char *BitcoinExchange::WrongDateFormatException::what(void) const throw()
{
    return ("Wrong date format");
}

const char *BitcoinExchange::InvalidFloatValueException::what(void) const throw()
{
    return ("Invalid float value");
}

const char *BitcoinExchange::InvalidPriceException::what(void) const throw()
{
    return ("Invalid price");
}

const char *BitcoinExchange::BitcoinDidNotExistException::what(void) const throw()
{
    return ("Bitcoin was created on 2009-01-02");
}