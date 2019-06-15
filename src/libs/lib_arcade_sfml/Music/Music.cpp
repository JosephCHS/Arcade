/*
** EPITECH PROJECT, 2019
** Music.cpp
** File description:
** Music class implementation
*/

#include "Music.hpp"

Music::Music(const std::string &music)
{
    _music.openFromFile(music);
}

void Music::play(void)
{
    _music.play();
}

void Music::stop(void)
{
    _music.stop();
}

void Music::repeat(void)
{
    _music.setLoop(true);
}
