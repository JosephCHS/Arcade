/*
** EPITECH PROJECT, 2019
** Sprite.hpp
** File description:
** Sprite class definition
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <string>
#include <utility>
#include <caca.h>
#include "ISprite.hpp"

class Window;

class Sprite : public ISprite
{
private:
    Vector2<int> _pos;
    Vector2<int> _pos_caca;
    Vector2<int> _size;
    Vector4<int> _rect;
    std::string _text;
    const char *_text_ptr = nullptr;
    caca_canvas_t *_sprite;
    Window *_window;
    uint8_t _color_text;
    uint8_t _color_back;
    
public:
    Sprite(const std::string &, Vector2<int>, Window *);
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
    const char *getStr(void) const;
    const Vector2<int> getPositionDraw(void) const;
    caca_canvas_t *getCanva(void) const;
};

#endif /* SPRITE_HPP_ */
