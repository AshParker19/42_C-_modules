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
    (void)date;
}

void BitcoinExchange::validatePrice(float price)
{
    (void)price;
}

void BitcoinExchange::validateLine(const std::string &content)
{
    size_t numComma = 0;
    size_t pos;
    std::string date;
    std::string price;

    for (size_t i = 0; i < content.size(); i++)
    {
        if (content[i] == ',')
            numComma++;
    }
    if (numComma != 1)
        throw (DataBaseRowErrorException());
    
    pos = content.find(',');
    if (pos == content.size() - 1)
        throw (DataBaseRowErrorException());
    date = content.substr(0, pos);
    // validateDate(date);
    
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
