/*
** EPITECH PROJECT, 2019
** Text.hpp
** File description:
** Text class definition
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <utility>
#include "IText.hpp"

class Window;

class Text : public IText
{
private: // À changer selon besoin
    TTF_Font *_police;
    SDL_Texture *_texture = nullptr;
    SDL_Renderer *_renderer = nullptr;
    SDL_Surface *_sprite = nullptr;
    Vector2<int> _pos;
    std::string _text;
    std::string _font;
    int _size = 30;
    Vector2<int> _size_vec;
    SDL_Color _color = {255, 255, 255, 255};
public:
    Text(const std::string &, Vector2<int>, const std::string &, Window &);
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
    SDL_Texture &getTextObject(void);
    const Vector2<int> &get_Size(void) const;
};

#endif /* TEXT_HPP_ */
