/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window class definition
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <utility>
#include <string>
#include <tuple>

#include "IWindow.hpp"
#include "../IObject/Sprite/Sprite.hpp"
#include "../IObject/Text/Text.hpp"

class Window : public IWindow
{
private: // À changer selon besoin
    sf::RenderWindow _window;
    sf::Event _event;
    std::map<sf::Keyboard::Key, EventCase> _EventMap;
    Vector2<int> _size;
public:
    Window(Vector2<int>, const std::string &);
    ~Window(void) = default;

    const Vector2<int> &getSize(void) const final;
    EventCase getLastEvent(void) final;
    void close(void) final;
    void clear(const Vector4<int> &) final;
    void display(void) final;
    void correctFrameRate(void) final;

    void show(IText &) final;
    void show(ISprite &) final;
};

#endif /* WINDOW_HPP_ */
