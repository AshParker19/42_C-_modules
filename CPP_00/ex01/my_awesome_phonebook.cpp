#include <iostream>
#include <string>
#include "Contact.hpp"

void    add(void)
{

}
void    search(void)
{

}
void    exit(void)
{

}

int main()
{
    std::string choice;

    std::cout << "Welcome to PhoneBook v.42!!!\n"; // add colors
    while (1)
    {
        std::cout << "Options: \n";
        std::cout << "   ADD --> save a new contact\n";
        std::cout << "SEARCH --> display specific contact\n";
        std::cout << "  EXIT --> quit PhoneBook\n";
        
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice == "ADD")
            add();
        else if (choice == "SEARCH")
            search();
        else if (choice == "EXIT")
            exit();
        else
        {
            std::cout << "WRONG OPTION!!!\n";
            std::cout << "Please select one from the list!\n";
        }
    }
}

//1 print menu with all the commands to chose