#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _displayTimestamp();
    _totalAmount += initial_deposit;
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << initial_deposit << ";";
    std::cout << "created\n";
}

Account::~Account( void )
{
    _displayTimestamp();

    
    std::cout << "closed\n";
}

// getters
int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout   << "accounts:" << _nbAccounts << ";"
                << "total:" << _totalAmount << ";"
                << "deposits:" << _totalNbDeposits << ";"
                << "withdrawals:" << _totalNbWithdrawals << ";\n";
}

void	Account::makeDeposit( int deposit )
{
    // _totalAmount = deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "deposit:" << deposit << ";"
                << "amount:" << _amount + deposit << ";"
                << "nb_deposits:" << _nbDeposits << "\n";
}
bool	Account::makeWithdrawal( int withdrawal )
{
    _totalNbWithdrawals++;
    (void)withdrawal;
    return (true);
}
int		Account::checkAmount( void ) const
{
    return (42);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals << ";\n";
}

void	Account::_displayTimestamp()
{
    std::time_t         cur_time = std::time(0);
    std::tm             *local_time = std::localtime(&cur_time);
    std::ostringstream  inp;
    
    inp << std::setfill('0')
        << (1900 + local_time->tm_year)
        << std::setw(2) << (1 + local_time->tm_mon)
        << std::setw(2) << local_time->tm_mday
        << "_"
        << std::setw(2) << local_time->tm_hour
        << std::setw(2) << local_time->tm_min
        << std::setw(2) << local_time->tm_sec;
    std::cout << "[" << inp.str() << "] ";
} // ask waht re streeams are