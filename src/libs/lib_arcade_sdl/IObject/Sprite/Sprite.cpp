/*
** EPITECH PROJECT, 2019
** Sprite.cpp
** File description:
** Sprite class implementation
*/

#include <iostream>
#include "../../Window/Window.hpp"
#include "Sprite.hpp"

Sprite::Sprite(const std::string &path, Vector2<int> pos, Window &window)
{
    _renderer = &window.getRenderer();
    _sprite = IMG_Load(path.c_str());
    if (_sprite == nullptr) {
        throw std::runtime_error("Can't find : " + path);
    }
    _size.x = _sprite->w;
    _size.y = _sprite->h;
    _texture = SDL_CreateTextureFromSurface(_renderer, _sprite);
    _pos = pos;
}

Sprite::~Sprite(void)
{
    SDL_FreeSurface(_sprite);
    SDL_DestroyTexture(_texture);
}

void Sprite::setPosition(const Vector2<int> &pos)
{
    _pos = pos;
}

const Vector2<int> &Sprite::getPosition(void) const
{
    return _pos;
}

void Sprite::setColor(Color text, Color black)
{
    (void)text;
    (void)black;
    // text ou back
}

void Sprite::reverse(void)
{
    SDL_RenderCopyEx(_renderer, _texture, NULL, NULL, 0, NULL, SDL_FLIP_HORIZONTAL);
}

void Sprite::setRect(const Vector4<int> &rect)
{
    _rect = rect;
}

const Vector4<int> &Sprite::getRect(void) const
{
    return _rect;
}

void Sprite::setSize(const Vector2<int> &size)
{
    _size = size;
}

const Vector2<int> &Sprite::getSize(void) const
{
    return _size;
}

SDL_Texture &Sprite::getSprite(void)
{
    return (*this->_texture);
}
