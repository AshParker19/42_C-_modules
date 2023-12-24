#ifndef MY_AWESOME_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_HPP

/* system includes */
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <stdlib.h>

/* utils */
bool    validate_input(std::string &input);
bool    is_numeric(std::string &input);
std::string truncate_space(std::string &input);

#endif
