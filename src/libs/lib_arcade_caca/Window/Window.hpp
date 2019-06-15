/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window class definition
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "caca.h"

#include <utility>
#include <string>
#include <tuple>
#include <map>
#include <vector>

#include "IWindow.hpp"
#include "../IObject/Sprite/Sprite.hpp"
#include "../IObject/Text/Text.hpp"
#include "Event.hpp"

class Window : public IWindow
{
private: // À changer selon besoin
    std::map<caca_key, EventCase> _EventMap;
    caca_display_t *_dp;
    caca_canvas_t *_cv;
    caca_event_t _event;
    Vector2<int> _size;
public:
    Window(Vector2<int>, const std::string &);
    ~Window(void);

    const Vector2<int> &getSize(void) const final;
    EventCase getLastEvent(void) final;
    void close(void) final;
    void clear(const Vector4<int> &) final;
    void display(void) final;
    void correctFrameRate(void) final;

    void show(IText &) final;
    void show(ISprite &) final;
    caca_canvas_t *getCanva(void);
};

#endif /* WINDOW_HPP_ */
