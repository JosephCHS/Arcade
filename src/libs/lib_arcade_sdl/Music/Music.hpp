/*
** EPITECH PROJECT, 2019
** Music.hpp
** File description:
** Music class definition
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <string>

#include "IMusic.hpp"

class Music : public IMusic
{
private: // À changer selon besoin
    Mix_Music *_music = nullptr;
public:
    Music(const std::string &);
    ~Music(void);

    void play(void) final;
    void stop(void) final;
    void repeat(void) final;
};

#endif /* MUSIC_HPP_ */
