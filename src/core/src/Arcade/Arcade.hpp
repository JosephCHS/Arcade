/*
** EPITECH PROJECT, 2019
** Arcade.hpp
** File description:
** Arcade class implementation
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include <dlfcn.h>
#include <filesystem>
#include <map>

#include "Vector.hpp"
#include "Event.hpp"
#include "IGame.hpp"
#include "IWindow.hpp"
#include "GameSelector/GameSelector.hpp"
#include "LibSelector/LibSelector.hpp"
#include "Input/Input.hpp"
#include "HighScore/HighScore.hpp"

class Arcade
{
private:
    SPIWindow _win = nullptr;
    SPIFactory _factory = nullptr;
    SPIGame _game = nullptr;
    UPIText _title = nullptr;
    UPISprite _play = nullptr;
    UPISprite _bind = nullptr;
    GameSelector _games;
    LibSelector _libs;
    Input _input;
    HighScore _highscore;
    std::string _user;
    int _score;

    void checkEventCases(EventCase &now);
    void displayMenu(void);
    void prepareChange(void);
    void changeLib(void);
    std::string file2string(const std::string &);
public:
    Arcade(const std::string &path);
    ~Arcade(void);

    int start(void);
};

#endif /* ARCADE_HPP_ */
