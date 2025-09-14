NAME = converter

SRC = main.cpp ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Werror -Wextra -Wall -std=c++98

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re