
/*
    1) parse the data base file
        1.check if such a file exists
        2.check if its extension is .csv
    2) read and parse the content of db file
        1.check if date is in Year-Month-Day format
        2.check if the date is valid, if it's not future, if the month and day are correct. CHECK FOR A LEAP YEAR!!!!
        3. check prices for overflow
    3) parse the content of a testfile
        1. check the data | value format
        2. check the data format, it suppose to be in Year-Month-Day format
        3. check is a value is either a float or a positive integer, between 0 and 1000.
    4) read the 
*/

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{    
    try 
    {
        if (ac != 2)
            throw (BitcoinExchange::CouldNotOpenFileException());

        BitcoinExchange btc;

        btc.validateInputFile(av[1]);
        btc.validateFileDB();
        btc.readStoreDB();
        std::cout << "==================\n";
        btc.proceedInputFile();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}