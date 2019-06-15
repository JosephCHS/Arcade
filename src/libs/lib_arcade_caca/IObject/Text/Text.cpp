/*
** EPITECH PROJECT, 2019
** Text.cpp
** File description:
** Text class implementation
*/

#include "Text.hpp"
#include "../../Window/Window.hpp"
#include <string.h>

Text::Text(const std::string &text, Vector2<int> pos, [[maybe_unused]] const std::string &font, Window *window)
{
    _text = text;
    _text_ptr = text.c_str();
    _sprite = caca_create_canvas(0, 0);
    caca_import_canvas_from_memory(_sprite, _text_ptr, strlen(_text_ptr), "text");

    _pos.x = pos.x;
    _pos.y = pos.y;
    _pos_caca.x = (float)pos.x / 1920.0 * 192.0;
    _pos_caca.y = (float)pos.y / 1080.0 * 48.0;
    _window = window;
}

Text::~Text(void)
{
    caca_free_canvas(_sprite);
}

void Text::setText(const std::string &text)
{
    _text = text;
    _text_ptr = text.c_str();
    caca_import_canvas_from_memory(_sprite, _text_ptr, strlen(_text_ptr), "text");
}

const std::string &Text::getText(void) const
{
    return _text;
}

void Text::setSize([[maybe_unused]] int size)
{
}

int Text::getSize(void) const
{
    return -1;
}

void Text::setPosition(const Vector2<int> &pos)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
    _pos_caca.x = (float)pos.x / 1920.0 * 192.0;
    _pos_caca.y = (float)pos.y / 1080.0 * 48.0;
}

const Vector2<int> &Text::getPosition(void) const
{
    return _pos;
}

void Text::setColor(Color text, Color back)
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

const char *Text::getStr(void) const
{
    return _text_ptr;
}

const Vector2<int> Text::getPositionDraw(void) const
{
    return _pos_caca;
}

caca_canvas_t *Text::getCanva(void) const
{
    return _sprite;
}
