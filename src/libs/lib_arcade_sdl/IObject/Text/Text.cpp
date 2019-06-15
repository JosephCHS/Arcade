/*
** EPITECH PROJECT, 2019
** Text.cpp
** File description:
** Text class implementation
*/

#include <iostream>
#include "../../Window/Window.hpp"
#include "Text.hpp"

Text::Text(const std::string &text, Vector2<int> pos, const std::string &font, Window &win)
{
    this->_renderer = &win.getRenderer();
    this->_text = text;
    if (text == "") {
        this->_text = " ";
    }
    _font = font;
    this->_color = {255, 255, 255, 255};
    this->_pos = Vector2<int>(pos.x, pos.y);
    this->_police = TTF_OpenFont(_font.c_str(), this->_size);
    if (_police == nullptr) {
        throw std::runtime_error("Can't find : " + font);
    }
    this->_sprite = TTF_RenderText_Solid(this->_police, this->_text.c_str(), this->_color);
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_sprite);
    _size_vec.x = text.length() * 15;
    SDL_FreeSurface(this->_sprite);
}

Text::~Text(void)
{
    SDL_DestroyTexture(this->_texture);
}

void Text::setText(const std::string &text)
{
    this->_text = text;
    if (text == "")
        this->_text = " ";
    _size_vec.x = text.length() * 15;
    this->_sprite = TTF_RenderText_Solid(this->_police, this->_text.c_str(), this->_color);
    SDL_DestroyTexture(this->_texture);
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_sprite);
    SDL_FreeSurface(this->_sprite);
}

const Vector2<int> &Text::get_Size() const
{
    return _size_vec;
}

const std::string &Text::getText(void) const
{
    return this->_text;
}

void Text::setSize(int size)
{
    this->_size = size;
    this->_police = TTF_OpenFont(_font.c_str(), this->_size);
    this->_sprite = TTF_RenderText_Solid(this->_police, this->_text.c_str(), this->_color);
    SDL_DestroyTexture(this->_texture);
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_sprite);
    SDL_FreeSurface(this->_sprite);
}

int Text::getSize(void) const
{
    return this->_size;
}

void Text::setPosition(const Vector2<int> &pos)
{
    this->_pos = Vector2<int>(pos.x, pos.y);
}

const Vector2<int> &Text::getPosition(void) const
{
    return this->_pos;
}

void Text::setColor(Color text, Color back)
{
    switch (text) {
        case BLACK: this->_color = {0, 0, 0, 255};
	    break;
        case RED: this->_color = {255, 0, 0, 255};
	    break;
        case GREEN: this->_color = {0, 255, 0, 255};
	    break;
        case YELLOW: this->_color = {255, 255, 0, 255};
	    break;
        case BLUE: this->_color = {0, 0, 255, 255};
	    break;
        case MAGENTA: this->_color = {255, 0, 255, 255};
	    break;
        case CYAN: this->_color = {0, 255, 255, 255};
	    break;
        case WHITE: this->_color = {255, 255, 255, 255};
	    break;
    }
    (void)back;
    this->_sprite = TTF_RenderText_Solid(this->_police, this->_text.c_str(), this->_color);
    SDL_DestroyTexture(this->_texture);
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_sprite);
    SDL_FreeSurface(this->_sprite);
}

SDL_Texture &Text::getTextObject(void)
{
    return (*this->_texture);
}
