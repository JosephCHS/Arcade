/*
** EPITECH PROJECT, 2019
** GameSelector.hpp
** File description:
** GameSelector class definition
*/

#ifndef GAMESELECTOR_HPP_
#define GAMESELECTOR_HPP_

#include <dlfcn.h>
#include <filesystem>

#include "Exception/CoreException.hpp"
#include "IGame.hpp"

class GameSelector
{
private:
    std::vector<std::string> _games;
    std::vector<std::string> _names;
    void * _handle;
    SPIGame (*_entry)(void);
    int _games_nbr = 0;
    int _games_idx = 0;
    UPISprite _next = nullptr;
    UPISprite _prev = nullptr;
    UPIText _title = nullptr;
    UPIText _name = nullptr;

    void loadGames(void);
public:
    GameSelector(void);
    ~GameSelector();

    void init(SPIFactory &, SPIWindow &);
    void reset(void);
    void clean(void);
    void draw(SPIWindow &);
    void nextGame(void);
    void prevGame(void);
    SPIGame game(void);
};

#endif /* GAMESELECTOR_HPP_ */
