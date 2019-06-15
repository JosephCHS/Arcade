/*
** EPITECH PROJECT, 2019
** Text.cpp
** File description:
** Text class implementation
*/

#include "Text.hpp"

Text::Text(const std::string &text, Vector2<int> pos, const std::string &font)
{
    _font.loadFromFile(font);
    _text.setFont(_font);
    _text.setString(text);
    _pos = pos;
    _text.setPosition(_pos.x, _pos.y);
    _str = text;
    _text.setCharacterSize(25);
}

void Text::setText(const std::string &text)
{
    _str = text;
    _text.setString(text);
}

const std::string &Text::getText(void) const
{
    return _str;
}

void Text::setSize(int size)
{
    _text.setCharacterSize(size);
}

int Text::getSize(void) const
{
    return _text.getCharacterSize();
}

void Text::setPosition(const Vector2<int> &pos)
{
    _pos = pos;
    _text.setPosition(_pos.x, _pos.y);
}

const Vector2<int> &Text::getPosition(void) const
{
    return _pos;
}

void Text::setColor(Color text, Color back)
{
    switch (text) {
        case BLACK: _text.setFillColor(sf::Color::Black);
	    break;
        case RED: _text.setFillColor(sf::Color::Red);
	    break;
        case GREEN: _text.setFillColor(sf::Color::Green);
	    break;
        case YELLOW: _text.setFillColor(sf::Color::Yellow);
	    break;
        case BLUE: _text.setFillColor(sf::Color::Blue);
	    break;
        case MAGENTA: _text.setFillColor(sf::Color::Magenta);
	    break;
        case CYAN: _text.setFillColor(sf::Color::Cyan);
	    break;
        case WHITE: _text.setFillColor(sf::Color::White);
	    break;
    }
    switch (back) {
        case BLACK: _text.setOutlineColor(sf::Color::Black);
	    break;
        case RED: _text.setOutlineColor(sf::Color::Red);
	    break;
        case GREEN: _text.setOutlineColor(sf::Color::Green);
	    break;
        case YELLOW: _text.setOutlineColor(sf::Color::Yellow);
	    break;
	case BLUE: _text.setOutlineColor(sf::Color::Blue);
	    break;
        case MAGENTA: _text.setOutlineColor(sf::Color::Magenta);
	    break;
        case CYAN: _text.setOutlineColor(sf::Color::Cyan);
	    break;
        case WHITE: _text.setOutlineColor(sf::Color::White);
	    break;
    }
}

sf::Text Text::getTextObject(void) const
{
    return _text;
}
