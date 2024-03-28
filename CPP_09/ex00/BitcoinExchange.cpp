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

std::string BitcoinExchange::validateDate(const std::string &date, int flag)
{
    int yearMonthDay[3];
    
    // check date's structure
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        if (flag == 0)
            throw (WrongDateFormatException());
        return ("bad input => " + date);
    }

    yearMonthDay[0] = std::atoi(date.substr(0, 4).c_str());
    yearMonthDay[1] = std::atoi(date.substr(5, 2).c_str());
    yearMonthDay[2] = std::atoi(date.substr(8, 2).c_str());

    if (yearMonthDay[0] == 2009 && yearMonthDay[1] == 1 && yearMonthDay[2] < 2)
    {
        if (flag == 0)
            throw (BitcoinDidNotExistException());
        return ("Bitcoin was created on 2009-01-02.");
    }
    if (yearMonthDay[0] < 2009 || yearMonthDay[1] < 1 || yearMonthDay[2] < 1 ||
        yearMonthDay[0] > 2024 || yearMonthDay[1] > 12 || yearMonthDay[2] > 31) //TODO: limit it by the date of the evaluation day
    {
        if (flag == 0)
            throw (WrongDateFormatException());
        return ("Wrong date format."); // TODO: write a better error message
    }
    
    tempDate = date;
    return ("");
}

std::string BitcoinExchange::validateAmount(const std::string &amount, int flag)
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
        return (" not a positive number.");
    }
    
    dotPos = amount.find('.');
    if (dotPos == amount.size() - 1)
    {
        if (flag == 0)
            throw (DataBaseRowErrorException());
        return (" not a positive number.");
    }
    tempAmount = std::atof(amount.c_str());
    if (flag == 0 && tempAmount < 0) //TODO: add a limit for BTC ATH at the day of submission
        throw (InvalidPriceException());
    if (flag == 1 && (tempAmount < 0 || tempAmount > 10000))
        return (" not a positive number.");
    return ("");
}

void BitcoinExchange::validateDBLine(const std::string &content)
{
    size_t numSep = 0;
    size_t sepPos;
    size_t amountPos;
    bool onlySpaces = false;

    for (size_t i = 0; i < content.size(); i++)
    {
        if (content[i] == ',')
            numSep++;
    }
    if (numSep != 1)
            throw (DataBaseRowErrorException());

    sepPos = content.find(',');
    if (sepPos == content.size() - 1)
        throw (DataBaseRowErrorException());
    
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
        throw (DataBaseRowErrorException());
    
    validateDate(trim(content.substr(0, sepPos)), 0);
    validateAmount(trim(content.substr(amountPos)), 0);
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
            validateDBLine(content);
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

void BitcoinExchange::validateInputFileLine(const std::string &content)
{
    size_t numSep = 0;
    size_t sepPos;
    size_t amountPos;
    bool onlySpaces = false;
    std::string status;

    for (size_t i = 0; i < content.size(); i++)
    {
        if (content[i] == '|')
            numSep++;
    }
    if (numSep != 1)
    {
        std::cerr << "Error: bad input => " + content << "\n";
        return ;
    }

    sepPos = content.find('|');
    if (sepPos == content.size() - 1)
    {
        std::cerr << "Error: bad input => " + content << "\n";
        return ;
    }
    
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
        std::cerr << "Error: bad input => " + content << "\n";
        return ;
    }
    
    status = validateDate(trim(content.substr(0, sepPos)), 1);
    if (!status.empty())
    {
        std::cerr << "Error:" + status << "\n";
        return ;
    }
    status = validateAmount(trim(content.substr(amountPos)), 1);
    if (!status.empty())
        std::cerr << "Error:" + status << "\n";
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
        validateInputFileLine(content);
        calculateResult();
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

BitcoinExchange::CalculationErrorException::CalculationErrorException() {}

BitcoinExchange::CalculationErrorException::CalculationErrorException(const std::string &msg)
                                                                     : message(msg) {}

BitcoinExchange::CalculationErrorException::~CalculationErrorException() throw() {}

const char *BitcoinExchange::CalculationErrorException::what(void) const throw()
{
    return (message.c_str());
}
