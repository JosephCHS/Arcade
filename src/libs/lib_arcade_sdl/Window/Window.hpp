/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window class definition
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <utility>
#include <string>
#include <tuple>
#include <map>

#include "IWindow.hpp"
#include "../IObject/Sprite/Sprite.hpp"
#include "../IObject/Text/Text.hpp"

class Window : public IWindow
{
private: // À changer selon besoin
    SDL_Window *_window = nullptr;
    SDL_Event _EventCase;
    SDL_Renderer *_renderer = nullptr;
    std::map<SDL_Keycode, EventCase> _EventMap;
    Vector2<int> *_window_size;
public:
    Window(Vector2<int>, const std::string &);
    ~Window(void);

    const Vector2<int> &getSize(void) const final;
    EventCase getLastEvent(void) final;
    void close(void) final;
    SDL_Renderer &getRenderer(void);
    void clear(const Vector4<int> &) final;
    void display(void) final;
    void correctFrameRate(void) final;

    void show(IText &) final;
    void show(ISprite &) final;
};

#endif /* WINDOW_HPP_ */
