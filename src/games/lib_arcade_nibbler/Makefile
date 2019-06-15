##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## lib_arcade_nibbler's Makefile
##

SRC	=	../../utils/Clock/Clock.cpp	\
		./src/Game/Game_Snake.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_nibbler.so

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

.PHONY: all clean fclean re test
