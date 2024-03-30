#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{    
    try 
    {
        if (ac != 2)
            throw (BitcoinExchange::CouldNotOpenFileException());

        BitcoinExchange btc;

        btc.validateFile(av[1]);
        btc.validateFile();
        btc.readStoreDB();
        btc.proceedInputFile();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}