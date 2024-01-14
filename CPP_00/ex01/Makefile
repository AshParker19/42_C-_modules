# Name
NAME = my_awesome_phonebook

# Compiler
CXX = c++

# Flags
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Sources
SRC = 	my_awesome_phonebook.cpp	\
		utils.cpp					\
		Contact.cpp					\
		PhoneBook.cpp				\

# Objects
OBJ = $(SRC:%.cpp=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "\"$(NAME)\" is compiled!"

obj/%.o: %.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
