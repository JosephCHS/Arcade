##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## entire project's makefile
##

PATH_ARCADE	=	./src/core

ARCADE	=	arcade

PATH_CACA	=	./src/libs/lib_arcade_caca

PATH_SFML	=	./src/libs/lib_arcade_sfml

PATH_SDL	=	./src/libs/lib_arcade_sdl

SO_CACA	=	lib_arcade_caca.so

SO_SFML	=	lib_arcade_sfml.so

SO_SDL	=	lib_arcade_sdl2.so

PATH_SOLARFOX	=	./src/games/lib_arcade_solarfox

PATH_NIBBLER	=	./src/games/lib_arcade_nibbler

SOLARFOX	=	lib_arcade_solarfox.so

NIBBLER	=	lib_arcade_nibbler.so

all:	core graphicals games

core:
	make -C $(PATH_ARCADE)
	cp $(PATH_ARCADE)/$(ARCADE) .
	cp -r $(PATH_ARCADE)/assets .

graphicals:
	make -C $(PATH_CACA)
	make -C $(PATH_SFML)
	make -C $(PATH_SDL)
	cp $(PATH_CACA)/$(SO_CACA) ./lib/
	cp $(PATH_SFML)/$(SO_SFML) ./lib/
	cp $(PATH_SDL)/$(SO_SDL) ./lib/

games:
	make -C $(PATH_SOLARFOX)
	make -C $(PATH_NIBBLER)
	cp $(PATH_SOLARFOX)/$(SOLARFOX) ./games/
	cp $(PATH_NIBBLER)/$(NIBBLER) ./games/
	cp -r $(PATH_SOLARFOX)/assets_solarfox ./games/
	cp -r $(PATH_NIBBLER)/assets_nibbler ./games/

clean:
	make -C $(PATH_ARCADE) clean
	make -C $(PATH_CACA) clean
	make -C $(PATH_SFML) clean
	make -C $(PATH_SDL) clean
	make -C $(PATH_SOLARFOX) clean
	make -C $(PATH_NIBBLER) clean

fclean:	clean
	make -C $(PATH_ARCADE) fclean
	make -C $(PATH_CACA) fclean
	make -C $(PATH_SFML) fclean
	make -C $(PATH_SDL) fclean
	make -C $(PATH_SOLARFOX) fclean
	make -C $(PATH_NIBBLER) fclean
	rm -rf $(ARCADE)
	rm -rf ./assets
	rm -rf ./lib/$(SO_CACA)
	rm -rf ./lib/$(SO_SFML)
	rm -rf ./lib/$(SO_SDL)
	rm -rf ./games/$(SOLARFOX)
	rm -rf ./games/$(NIBBLER)
	rm -rf ./games/assets_solarfox
	rm -rf ./games/assets_nibbler

re:	fclean all

.PHONY:	games all graphicals fclean clean core
