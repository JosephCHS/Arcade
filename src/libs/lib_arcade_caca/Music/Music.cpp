/*
** EPITECH PROJECT, 2019
** Music.cpp
** File description:
** Music class implementation
*/

#include "Music.hpp"

Music::Music(const std::string &music)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL can't be initialized\n");
    }
    if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3) {
        fprintf(stderr, "Mix_mp3 can't be initialized\n");
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) != 0) {
        fprintf(stderr, "Mix_audio can't be initialized\n");
    }
    Mix_AllocateChannels(1);
    _music = Mix_LoadMUS(music.c_str());
}

Music::~Music(void)
{
    Mix_HaltMusic();
    Mix_FreeMusic(_music);
    Mix_CloseAudio();
    Mix_Quit();
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