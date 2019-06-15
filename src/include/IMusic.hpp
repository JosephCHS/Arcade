/*
** EPITECH PROJECT, 2019
** Music.hpp
** File description:
** Music class Interface
*/

#ifndef ARCADE_INTEFACE_IMUSIC_HPP
#define ARCADE_INTEFACE_IMUSIC_HPP

#include <string>

class IMusic
{
public:
    virtual ~IMusic() = default;

    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void repeat() = 0;
};

#endif //ARCADE_INTEFACE_IMUSIC_HPP
