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

NAME	=	lib_arcade_sdl2.so

EXTRA	=	-Wall -Wextra

SDL2	=	-lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

CPPFLAGS	=	-fPIC -IEventCase -I../../include $(EXTRA) 

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(SDL2) -shared

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:    	fclean all

.PHONY: all clean fclean re test
