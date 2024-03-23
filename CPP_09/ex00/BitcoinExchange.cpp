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

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::validateInputFile(const std::string &path)
{
    inputFile.open(path);
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

bool BitcoinExchange::validateDate(const std::string &date, int flag)
{
    int yearMonthDay[3];
    
    // check date's structure
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        if (flag == 0)
            throw (WrongDateFormatException());
        else
        {
            return (false);
        }
    }

    yearMonthDay[0] = atoi(date.substr(0, 4).c_str());
    yearMonthDay[1] = atoi(date.substr(5, 2).c_str());
    yearMonthDay[2] = atoi(date.substr(8, 2).c_str());

    if (yearMonthDay[0] == 2009 && yearMonthDay[1] == 1 && yearMonthDay[2] < 2)
    {
        if (flag == 0)
            throw (BitcoinDidNotExistException());
        else
            return (false);
    }
    if (yearMonthDay[0] < 2009 || yearMonthDay[1] < 1 || yearMonthDay[2] < 1 ||
        yearMonthDay[0] > 2024 || yearMonthDay[1] > 12 || yearMonthDay[2] > 31)
    {
        if (flag == 0)
            throw (WrongDateFormatException());
        else
            return (false);
    }
    
    tempDate = date;
    return (true);
}

bool BitcoinExchange::validateAmount(const std::string &amount, int flag)
{
    int dollars;
    int cents;
    int numDot = 0;
    int totalCents;
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
        else
            return (false);
    }
    
    dotPos = amount.find('.');
    if (dotPos == amount.size() - 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        else
            return (false);
    }
    dollars = atoi(amount.substr(0, dotPos).c_str());
    cents = atoi(amount.substr(dotPos + 1).c_str());
    totalCents = dollars * 100 + cents;

    if (flag == 0 && totalCents < 0) //TODO: add a limit for BTC ATH at the day of submission
        throw (InvalidPriceException());
    if (flag == 1 && totalCents > 10000)
        return (false);

    tempAmount = totalCents;
    return (true);
}

/*
    flag 0 = Database
    flag 1 = Inputfile
*/
bool BitcoinExchange::validateLine(const std::string &content, int flag, char sep)
{
    size_t numSep = 0;
    size_t sepPos;
    size_t amountPos;
    bool onlySpaces = false;

    // check if there is only one comma
    for (size_t i = 0; i < content.size(); i++)
    {
        if (content[i] == sep)
            numSep++;
    }
    if (numSep != 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        else
            return (false);
    }

    // check if comma is not the last character in a line
    sepPos = content.find(sep);
    if (sepPos == content.size() - 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        else
            return (false);
    }
    
    /* 
        check if there are any not whitespaces after comma
        find the position of the first not whitespace
    */
    for (size_t i = sepPos + 1; i < content.size(); i++)
    {
        if (!isspace(content[i]))
        {
            onlySpaces = true;
            amountPos = i;
            break;
        }
    }
    if (!onlySpaces)
    {
        if (flag == 0) // TODO: an exception which accepts flag and puts an according meessage
            throw (DataBaseRowErrorException());
        else
            return (false);
    }
    
    if (flag == 0)
    {
        validateDate(trim(content.substr(0, sepPos)), 0);
        validateAmount(trim(content.substr(amountPos)), 0);
    }
    if (flag == 1 && (!validateDate(trim(content.substr(0, sepPos)), 1) || 
        !validateAmount(trim(content.substr(amountPos)), 1)))
    {
        return (false);
    }
    return (true);
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
        fileDB.close();
    }
    catch (const std::exception &e)
    {
        if (fileDB)
            fileDB.close();
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void BitcoinExchange::proceedInputFile()
{
    std::string content;

    try
    {
        std::getline(inputFile, content);
        if (content.empty())
            throw (InputFileRowErrorException());
        if (content != "date | value")
            throw (WrongHeadingException());
        while (std::getline(inputFile, content))
        {
            if (content.empty())
                continue;

            validateLine(content, 1, '|');

            std::cout << "Date --> " << tempDate << " | " << "Amount --> " << tempAmount << "\n";
        }
    }
    catch (const std::exception &e)
    {
        if (inputFile)
            inputFile.close();
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::string BitcoinExchange::trim(const std::string& str)
{
    const std::string whitespace = " \t\n\r\f\v";

    // Find the first character position after excluding leading whitespace characters
    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        return ""; // No non-whitespace characters
    }

    // Find the last character position before excluding trailing whitespace characters
    size_t end = str.find_last_not_of(whitespace);

    // Calculate the range and extract the substring
    return str.substr(start, end - start + 1);
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