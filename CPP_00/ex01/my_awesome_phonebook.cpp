#include <iostream>
#include "PhoneBook.hpp"

void    add(PhoneBook &phone_book);
void    search(PhoneBook phone_book);

int main()
{
    PhoneBook   phone_book;
    std::string choice;

    std::cout << "Welcome to PhoneBook v.42!!!\n"; // add colors
    while (1)
    {
        std::cout   << "Options: \n"
                    << "   ADD --> save a new contact\n"
                    << "SEARCH --> display specific contact\n"
                    << "  EXIT --> quit PhoneBook\n"
                    << "Enter your choice: ";
        std::cin >> choice;
        if (choice == "ADD")
            add(phone_book);
        else if (choice == "SEARCH")
            search(phone_book);
        else if (choice == "EXIT")
            exit(0);
        else
        {
            std::cout << "WRONG OPTION!!!\n";
            std::cout << "Please select one from the list!\n";
        }
    }
}
