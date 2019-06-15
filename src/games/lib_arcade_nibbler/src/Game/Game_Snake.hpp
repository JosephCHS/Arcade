/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Game.hpp
*/

#ifndef GAME_SNAKE_HPP_
#define GAME_SNAKE_HPP_

/*!
 * \file Game_Snake.hpp
 * \brief Snake for the arcade project
 * \author joseph.chartois@epitech.eu
 * \version 1.0
 */

#include <vector>
#include <dlfcn.h>
#include <iostream>
#include <random>
#include <fstream>

#include "IGame.hpp"
#include "ISprite.hpp"
#include "IText.hpp"
#include "Event.hpp"
#include "IFactory.hpp"
#include "IWindow.hpp"
#include "Vector.hpp"

/*! \class Game_Snake
 * \brief Snake Class
 *
 *  This class handle snake's movement, score and reset
 */
class Game_Snake : public IGame
{
private:
    UPIText _score_dynamic; /*!< Score to be display*/
    UPIClock _clock; /*!< Clock using to display properly the sprite*/
    UPISprite _spr_map_static; /*!< Object sprite with the full map stored, no animated*/
    UPISprite _spr_fruit_dynamic; /*!< Object sprite with the fruit's sprite*/
    std::vector<UPISprite> _snake_dynamic; /*!< Vector of shared ptr (to sprite) with at the begining the head and three body part of the snake, after that handle the others body parts*/
    std::vector<Vector2<int>> _snake_pos_init; /*!< Vector of the first position of the snake*/
    Vector2<int> _fruit_pos; /*!< Vector with the fruit's position*/
    SPIFactory _factory = nullptr; /*!< Shared ptr => factory*/
    SPIWindow _win = nullptr; /*!< Shared ptr => window*/
    int _score_int; /*!< store the score inside an int before renderer it trought a string*/
    bool _gameOver; /*!< game over : true, leave or false, continue*/
    Vector2<int> _direct;/*!< vector to store the direction taked by the snake*/

    void initMap();
    void update_score();
    void updateSnake(EventCase ev);
    void clearAll();
    void resetToReplay();
    void isGameOver();
    void writeTopScore();
    void randomFruit();
public:
    Game_Snake();
    ~Game_Snake();
    void init(SPIFactory factory, SPIWindow window) final;
    void reset() final;
    int run(EventCase e) final;
    bool gameOver() const final;
};

#endif // GAME_SNAKE_HPP