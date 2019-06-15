/*
** EPITECH PROJECT, 2019
** Text.hpp
** File description:
** Text class definition
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <string>
#include <utility>

#include "IText.hpp"

class Text : public IText
{
private: // À changer selon besoin
    sf::Font _font;
    sf::Text _text;
    Vector2<int> _pos;
    std::string _str;
public:
    Text(const std::string &, Vector2<int>, const std::string &);
    ~Text(void) = default;

    //IObject
    void setPosition(const Vector2<int> &) final;
    const Vector2<int> &getPosition(void) const final;
    void setColor(Color text, Color back) final;

    //IText
    void setText(const std::string &) final;
    const std::string &getText(void) const final;
    void setSize(int) final;
    int getSize(void) const final;

    //Tricks
    sf::Text getTextObject(void) const;
};

#endif /* TEXT_HPP_ */
