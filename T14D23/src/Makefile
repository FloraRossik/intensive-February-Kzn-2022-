SRC1 = state_sort.c
SRC2 = state_search.c
SRC3 = clear_state.c

BUILDF = ../build

OBJ1 = $(SRC1:%.c=$(BUILDF)/%.o)
OBJ2 = $(SRC2:%.c=$(BUILDF)/%.o)
OBJ3 = $(SRC3:%.c=$(BUILDF)/%.o)

QUESTNAME1 = state_sort
QUESTNAME2 = state_search
QUESTNAME3 = clear_state

NAME1 = $(BUILDF)/$(QUESTNAME1)
NAME2 = $(BUILDF)/$(QUESTNAME2)
NAME3 = $(BUILDF)/$(QUESTNAME3)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

$(BUILDF)/%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all: quest1 quest2 quest3


quest1 : NAME1
quest2 : NAME2
quest3 : NAME3



NAME1 : $(OBJ1)
	$(CC) $(FLAGS) $(OBJ1) -o $(NAME1)
NAME2 : $(OBJ2)
	$(CC) $(FLAGS) $(OBJ2) -o $(NAME2)
NAME3 : $(OBJ3)
	$(CC) $(FLAGS) $(OBJ3) -o $(NAME3)

clean :
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	rm -f $(OBJ3)

fclean: clean
	  rm -f $(QUESTNAME1)
		rm -f $(QUESTNAME2)
		rm -f $(QUESTNAME3)

re: fclean all

style: $(SRC)
	python3 ../materials/linters/cpplint.py --extensions=c $(SRC1) $(SRC2) $(SRC3)

cppckeck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC1) $(SRC2) $(SRC3)

.PHONY: all re clean fclean style cppckeck quest1 quest2 quest3
