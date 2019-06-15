/*
** EPITECH PROJECT, 2019
** Sprite.cpp
** File description:
** Sprite class implementation
*/

#include "Sprite.hpp"

Sprite::Sprite(const std::string &path, Vector2<int> pos)
{
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _pos = pos;
    _sprite.setPosition(_pos.x, _pos.y);
}

void Sprite::setPosition(const Vector2<int> &pos)
{
    _pos = pos;
    _sprite.setPosition(_pos.x, _pos.y);
}

const Vector2<int> &Sprite::getPosition(void) const
{
    return _pos;
}

void Sprite::setColor(Color text, Color black)
{
    (void)black;
    switch (text) {
    case BLACK: _sprite.setColor(sf::Color::Black);
	break;
    case RED: _sprite.setColor(sf::Color::Red);
	break;
    case GREEN: _sprite.setColor(sf::Color::Green);
	break;
    case YELLOW: _sprite.setColor(sf::Color::Yellow);
	break;
    case BLUE: _sprite.setColor(sf::Color::Blue);
	break;
    case MAGENTA: _sprite.setColor(sf::Color::Magenta);
	break;
    case CYAN: _sprite.setColor(sf::Color::Cyan);
	break;
    case WHITE: _sprite.setColor(sf::Color::White);
	break;
    }
}

void Sprite::reverse(void)
{
    _sprite.scale(-1, 1);
}

void Sprite::setRect(const Vector4<int> &rect)
{
    _rect = rect;
    _sprite.setTextureRect(sf::Rect<int>(_rect.x, _rect.y, _rect.w, _rect.h));
}

const Vector4<int> &Sprite::getRect(void) const
{
    return _rect;
}

void Sprite::setSize(const Vector2<int> &size)
{
    sf::Rect<float> rect = _sprite.getLocalBounds();
    _size = size;
    _sprite.scale(sf::Vector2<float>(_size.x / rect.width, _size.y / rect.height));
}

const Vector2<int> &Sprite::getSize(void) const
{
    return _size;
}

sf::Sprite Sprite::getSprite(void) const
{
    return _sprite;
}
