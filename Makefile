##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CFLAGS = -W -Wall -Wextra -Iinclude/
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

SRC	 = 	$(wildcard *.c)\
		$(wildcard sources/*.c)\
		$(wildcard sources/objects/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_defender

all: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo "\033[1;33mletssss gooooo!\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;31mSegmentation fault (core dumped)\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;35mnettoyage terminé.\033[0m"

re: fclean \
	all