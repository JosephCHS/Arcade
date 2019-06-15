/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** start_game.cpp
*/

#include "Game.hpp"

extern "C" SPIGame createGame()
{
    return std::make_shared<Game>();
}