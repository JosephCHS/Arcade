##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## lib_sfml's Makefile
##

SRC	=	../../utils/Clock/Clock.cpp	\
		./IObject/Sprite/Sprite.cpp	\
		./IObject/Text/Text.cpp	\
		./Music/Music.cpp	\
		./Window/Window.cpp	\
		./Factory/Factory.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_sfml.so

EXTRA	=	-Wall -Wextra

SFML	=	-lsfml-graphics -lsfml-system -lsfml-audio

CPPFLAGS	=	-fPIC -I../../include $(EXTRA)

$(NAME):	$(OBJ)
	g++ -shared -o $(NAME) $(OBJ) $(SFML)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:    	fclean all

.PHONY: all clean fclean re test
