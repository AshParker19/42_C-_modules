#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
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
    size_t numHyphen = 0;
    
    if (date.size() != 10)
        throw (WrongDateFormatException());
    for (size_t i = 0; i < date.size(); i++)
    {
        if (date[i] == '-')
            numHyphen++;
    }
    if (numHyphen != 2)
        throw (WrongDateFormatException());

}

void BitcoinExchange::validatePrice(const std::string &price)
{
    (void)price;
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
        find the position of the fisrt not whitespace
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

const char *BitcoinExchange::InvalidPriceException::what(void) const throw()
{
    return ("Invalid price");
}
