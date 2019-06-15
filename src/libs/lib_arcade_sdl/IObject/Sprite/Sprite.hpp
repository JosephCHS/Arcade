/*
** EPITECH PROJECT, 2019
** Sprite.hpp
** File description:
** Sprite class definition
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SDL2/SDL.h>

#include <string>
#include <utility>
#include "ISprite.hpp"

class Window;

class Sprite : public ISprite
{
private: // À changer selon besoin
    SDL_Texture *_texture = nullptr;
    SDL_Renderer *_renderer = nullptr;
    SDL_Surface *_sprite = nullptr;
    Vector2<int> _pos;
    Vector2<int> _size;
    Vector4<int> _rect;
public:
    Sprite(const std::string &, Vector2<int>, Window &);
    ~Sprite(void);

    //IObject methods
    void setPosition(const Vector2<int> &) final;
    const Vector2<int> &getPosition(void) const final;
    void setColor(Color text, Color back) final;

    //ISprite methods
    void reverse(void) final;
    void setRect(const Vector4<int> &) final;
    const Vector4<int> &getRect(void) const final;
    void setSize(const Vector2<int> &) final;
    const Vector2<int> &getSize(void) const final;

    //Tricks
    SDL_Texture &getSprite(void);
};

#endif /* SPRITE_HPP_ */
