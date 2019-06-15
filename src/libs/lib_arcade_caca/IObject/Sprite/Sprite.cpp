/*
** EPITECH PROJECT, 2019
** Sprite.cpp
** File description:
** Sprite class implementation
*/

#include "Sprite.hpp"
#include "../../Window/Window.hpp"
#include <string.h>

Sprite::~Sprite()
{
    caca_free_canvas(_sprite);
}

Sprite::Sprite(const std::string &str_to_draw, Vector2<int> pos, Window *window)
{
    if (str_to_draw.find(".cacatxt") != std::string::npos) {
        if (caca_import_canvas_from_file(window->getCanva(), str_to_draw.c_str(), "text") != -1) {
            return;
        }
    }
    _text = str_to_draw;
    _text_ptr = _text.c_str();
    _sprite = caca_create_canvas(0, 0);
    caca_import_canvas_from_memory(_sprite, _text_ptr, strlen(_text_ptr), "");
    _pos.x = pos.x;
    _pos.y = pos.y;
    _pos_caca.x = (float)pos.x / 1920.0 * 192.0;
    _pos_caca.y = (float)pos.y / 1080.0 * 48.0;
    _size.x = caca_get_canvas_width(_sprite) * 1920.0 / 192.0;
    _size.y = caca_get_canvas_height(_sprite) * 1080.0 / 48.0;
    _window = window;
}

void Sprite::setPosition(const Vector2<int> &pos)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
    _pos_caca.x = (float)pos.x / 1920.0 * 192.0;
    _pos_caca.y = (float)pos.y / 1080.0 * 48.0;
}

const Vector2<int> &Sprite::getPosition(void) const
{
    return _pos;
}

void Sprite::setColor(Color text, Color back)
{
    switch (text) {
        case BLACK: _color_text = CACA_BLACK;
	    break;
        case RED: _color_text = CACA_RED;
	    break;
        case GREEN: _color_text = CACA_GREEN;
	    break;
        case YELLOW: _color_text = CACA_YELLOW;
	    break;
        case BLUE: _color_text = CACA_BLUE;
	    break;
        case MAGENTA: _color_text = CACA_MAGENTA;
	    break;
        case CYAN: _color_text = CACA_CYAN;
	    break;
        case WHITE: _color_text = CACA_WHITE;
	    break;
    }
    switch (back) {
        case BLACK: _color_back = CACA_BLACK;
	    break;
        case RED: _color_back = CACA_RED;
	    break;
        case GREEN: _color_back = CACA_GREEN;
	    break;
        case YELLOW: _color_back = CACA_YELLOW;
	    break;
        case BLUE: _color_back = CACA_BLUE;
	    break;
        case MAGENTA: _color_back = CACA_MAGENTA;
	    break;
        case CYAN: _color_back = CACA_CYAN;
	    break;
        case WHITE: _color_back = CACA_WHITE;
	    break;
    }
    caca_set_color_ansi(_sprite, _color_text, _color_back);
}

void Sprite::reverse(void)
{
}

void Sprite::setRect([[maybe_unused]]const Vector4<int> &rect)
{
}

const Vector4<int> &Sprite::getRect(void) const
{
    return _rect;
}

void Sprite::setSize(const Vector2<int> &size)
{
    (void)size;
}

const Vector2<int> &Sprite::getSize(void) const
{
    return _size;
}

const char *Sprite::getStr(void) const
{
    return _text_ptr;
}

const Vector2<int> Sprite::getPositionDraw(void) const
{
    return _pos_caca;
}

caca_canvas_t *Sprite::getCanva(void) const
{
    return _sprite;
}
