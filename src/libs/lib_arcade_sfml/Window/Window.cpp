/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window class implementation
*/

#include "Window.hpp"

Window::Window(Vector2<int> size, const std::string &title)
{
    _window.create(sf::VideoMode(size.x, size.y), title);
    _window.setFramerateLimit(60);
    _EventMap[sf::Keyboard::A] = A_CASE;
    _EventMap[sf::Keyboard::B] = B_CASE;
    _EventMap[sf::Keyboard::C] = C_CASE;
    _EventMap[sf::Keyboard::D] = D_CASE;
    _EventMap[sf::Keyboard::E] = E_CASE;
    _EventMap[sf::Keyboard::F] = F_CASE;
    _EventMap[sf::Keyboard::G] = G_CASE;
    _EventMap[sf::Keyboard::H] = H_CASE;
    _EventMap[sf::Keyboard::I] = I_CASE;
    _EventMap[sf::Keyboard::J] = J_CASE;
    _EventMap[sf::Keyboard::K] = K_CASE;
    _EventMap[sf::Keyboard::L] = L_CASE;
    _EventMap[sf::Keyboard::M] = M_CASE;
    _EventMap[sf::Keyboard::N] = N_CASE;
    _EventMap[sf::Keyboard::O] = O_CASE;
    _EventMap[sf::Keyboard::P] = P_CASE;
    _EventMap[sf::Keyboard::Q] = Q_CASE;
    _EventMap[sf::Keyboard::R] = R_CASE;
    _EventMap[sf::Keyboard::S] = S_CASE;
    _EventMap[sf::Keyboard::T] = T_CASE;
    _EventMap[sf::Keyboard::U] = U_CASE;
    _EventMap[sf::Keyboard::V] = V_CASE;
    _EventMap[sf::Keyboard::W] = W_CASE;
    _EventMap[sf::Keyboard::X] = X_CASE;
    _EventMap[sf::Keyboard::Y] = Y_CASE;
    _EventMap[sf::Keyboard::Z] = Z_CASE;
    _EventMap[sf::Keyboard::Escape] = ECHAP_CASE;
    _EventMap[sf::Keyboard::Tab] = TAB_CASE;
    _EventMap[sf::Keyboard::Backspace] = BACK_CASE;
    _EventMap[sf::Keyboard::Return] = RETURN_CASE;
    _EventMap[sf::Keyboard::Space] = SPACE_CASE;
    _EventMap[sf::Keyboard::Right] = ARIGHT_CASE;
    _EventMap[sf::Keyboard::Up] = AUP_CASE;
    _EventMap[sf::Keyboard::Down] = ADOWN_CASE;
    _EventMap[sf::Keyboard::Left] = ALEFT_CASE;
    _EventMap[sf::Keyboard::PageUp] = PAGE_UP;
    _EventMap[sf::Keyboard::PageDown] = PAGE_DOWN;
    _EventMap[sf::Keyboard::F1] = F1_CASE;
    _EventMap[sf::Keyboard::F2] = F2_CASE;
    _size = size;
}

const Vector2<int> &Window::getSize(void) const
{
    return _size;
}

EventCase Window::getLastEvent(void)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return WINDOW_CLOSE;
    if (_event.type == sf::Event::KeyPressed)
       return _EventMap[_event.key.code];
    }
    return NO_EVENT;
}

void Window::close(void)
{
    _window.close();
}

void Window::clear(const Vector4<int> &color)
{
    _window.clear(sf::Color(color.x, color.y, color.w, color.h));
}

void Window::display(void)
{
    _window.display();
}

void Window::correctFrameRate(void)
{
    //nothing need to be done here ;) thx sfml
}

void Window::show(ISprite &object)
{
    Sprite *real = static_cast<Sprite *>(&object);
    _window.draw(real->getSprite());
}

void Window::show(IText &object)
{
    Text *real = static_cast<Text *>(&object);
    _window.draw(real->getTextObject());
}
