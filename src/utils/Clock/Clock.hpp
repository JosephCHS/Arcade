/*
** EPITECH PROJECT, 2019
** Clock.hpp
** File description:
** Clock class definition
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <cstdint>
#include <ctime>
#include "IClock.hpp"

class Clock : public IClock
{
public:
    Clock();
    ~Clock() override = default;

    void resume() override;
    void pause() override;
    clock_t getTime() override;
private:
    clock_t _clock;
    clock_t _clockBreak;
    clock_t _clockStop;
    bool _break;
};

#endif /* CLOCK_HPP_ */
