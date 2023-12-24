#ifndef MY_AWESOME_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_HPP

/* system includes */
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>

/* colors */
#define GREEN 	"\033[32m"
#define BLUE    "\033[34m"
#define RED 	"\033[31m"
#define YELLOW 	"\x1b[33m"
#define CYAN 	"\x1b[36m"
#define PURPLE 	"\x1b[35m"
#define RESET 	"\033[0m"

/* utils */
bool        validate_input(std::string &input);
bool        is_numeric(std::string &input);
std::string truncate_space(std::string &input);
void        put_line(int type);
int         visible_length(const std::string& str);
void        put_text_center(std::string text, std::string color, bool sides);

#endif
