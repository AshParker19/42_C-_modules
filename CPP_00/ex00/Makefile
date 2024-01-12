# Name
NAME = megaphone

# Compiler
CXX = c++

# Flags
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Sources
SRC = megaphone.cpp

# Objects
OBJ = $(SRC:%.cpp=obj/%.o)

# Colors
CYAN   = \033[0;36m
RED    = \033[0;31m
GREEN  = \033[0;32m
ORANGE = \033[0;33m
BLUE   = \033[34m
PURPLE = \033[35m
DEF    = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^

obj/%.o: %.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
