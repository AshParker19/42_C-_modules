#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
    (void)initial_deposit;
}

Account::Account( void )
{
    std::cout << "created\n";
}

Account::~Account( void )
{
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

}