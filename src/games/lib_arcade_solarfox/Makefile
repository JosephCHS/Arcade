##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## lib_pacman's Makefile
##

SRC	=	src/start_game.cpp	\
		src/Game.cpp		\
		src/Enemy.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_solarfox.so

EXTRA	=	-Wall -Wextra

CPPFLAGS	=	-fPIC -I../../include $(EXTRA)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -shared

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:    	fclean all

.PHONY: all clean fclean re
