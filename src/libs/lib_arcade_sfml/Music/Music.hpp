/*
** EPITECH PROJECT, 2019
** Music.hpp
** File description:
** Music class definition
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <string>

#include "IMusic.hpp"

class Music : public IMusic
{
private: // À changer selon besoin
    sf::Music _music;
public:
    Music(const std::string &);
    ~Music(void) = default;

    void play(void) final;
    void stop(void) final;
    void repeat(void) final;
};

#endif /* MUSIC_HPP_ */
