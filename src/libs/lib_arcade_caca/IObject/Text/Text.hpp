/*
** EPITECH PROJECT, 2019
** Text.hpp
** File description:
** Text class definition
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <string>
#include <utility>
#include <caca.h>
#include "../../Window/Window.hpp"
#include "IText.hpp"

class Text : public IText
{
private: // À changer selon besoin
    Vector2<int> _pos;
    Vector2<int> _pos_caca;
    std::string _text;
    const char *_text_ptr = nullptr;
    caca_canvas_t *_sprite;
    Window *_window;
    uint8_t _color_text;
    uint8_t _color_back;
public:
    Text(const std::string &, Vector2<int>, const std::string &, Window *);
    ~Text(void);

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
    const char *getStr(void) const;
    const Vector2<int> getPositionDraw(void) const;
    caca_canvas_t *getCanva(void) const;
};

#endif /* TEXT_HPP_ */
