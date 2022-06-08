SRC = dmanager_module.c

NAME = Quest_1
	 
BUILDF = ../build

CC = gcc

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME) :
	      $(CC) $(FLAGS) $(SRC) -o $(BUILDF)/$(NAME)
clean:

fclean: clean
	      rm -f $(BUILDF)/$(NAME)

re: fclean all

.PHONY: all re clean fclean