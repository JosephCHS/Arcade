/*
** EPITECH PROJECT, 2019
** Clock.cpp
** File description:
** Clock class definition
*/
#include "Clock.hpp"

Clock::Clock() :
    _clock(std::clock()), _clockStop(std::clock()), _break(false) {}

void Clock::resume()
{
    if (_break) {
        _clockStop = clock();
        _clock = _clock - (_clockBreak - _clockStop);
    }
}

void Clock::pause()
{
    if (!_break) {
        _clockBreak = clock();
        _break = true;
    }
}

clock_t Clock::getTime()
{
    if (_break) {
        _clockStop = _clockBreak;
    }
    else {
        _clockStop = std::clock();
    }
    return (_clock - _clockStop);
}

