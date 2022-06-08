SRC = s21_string.c s21_string_test.c

NAME = string_tests

BUILDF = ../build

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) $(SRC) -o $(BUILDF)/$(NAME)

clean :

fclean : clean
	rm -f $(BUILDF)/$(NAME)

re : fclean all

.PHONY: all re clean fclean
