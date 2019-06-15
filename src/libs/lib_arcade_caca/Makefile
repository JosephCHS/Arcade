##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## lib_caca's Makefile
##

SRC	=	../../utils/Clock/Clock.cpp	\
		./IObject/Sprite/Sprite.cpp	\
		./IObject/Text/Text.cpp	\
		./Window/Window.cpp	\
		./Factory/Factory.cpp	\
		./Music/Music.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_caca.so

EXTRA	=	-Wall -Wextra

SDL2	=	-lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

CACA	=	$(shell pkg-config --libs --cflags caca)

CPPFLAGS	=	-fPIC -I../../include $(EXTRA)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CACA) $(SDL2) -shared

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:    	fclean all

.PHONY: all clean fclean re test
