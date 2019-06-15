/*
** EPITECH PROJECT, 2019
** Music.cpp
** File description:
** Music class implementation
*/

#include <iostream>
#include "Music.hpp"

Music::Music(const std::string &music)
{
    _music = Mix_LoadMUS(music.c_str());
    if (_music == nullptr)
        throw std::runtime_error("Can't find : " + music);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
}

Music::~Music(void)
{
    //Mix_Quit();
}

void Music::play(void)
{
    if (Mix_PausedMusic() != 0) {
        Mix_ResumeMusic();
    }
}

void Music::stop(void)
{
    if (Mix_PlayingMusic() != 0) {
        Mix_PausedMusic();
    }
}

void Music::repeat(void)
{
    Mix_PlayMusic(_music, -1);
}
