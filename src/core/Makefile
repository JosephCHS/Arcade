##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## arcade's makefile
##

SRC	=	./src/main.cpp	\
		./src/Arcade/Arcade.cpp	\
		./src/LibSelector/LibSelector.cpp	\
		./src/GameSelector/GameSelector.cpp	\
		./src/Input/Input.cpp	\
		./src/Exception/CoreException.cpp	\
		./src/HighScore/HighScore.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Wall -std=c++17 -Isrc -I../include -I./src

NAME	=	arcade

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -ldl -lstdc++fs

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
