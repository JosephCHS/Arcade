/*
** EPITECH PROJECT, 2019
** Sprite.hpp
** File description:
** Sprite class definition
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <string>
#include <utility>
#include "ISprite.hpp"

class Sprite : public ISprite
{
private: // À changer selon besoin
    sf::Texture _texture;
    sf::Sprite _sprite;
    Vector2<int> _pos;
    Vector2<int> _size;
    Vector4<int> _rect;
public:
    Sprite(const std::string &, Vector2<int>);
    ~Sprite(void) = default;

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
    sf::Sprite getSprite(void) const;
};

#endif /* SPRITE_HPP_ */
