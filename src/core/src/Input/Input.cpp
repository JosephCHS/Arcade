/*
** EPITECH PROJECT, 2019
** Input.cpp
** File description:
** Input class implementation
*/

#include "Input.hpp"

Input::Input()
{
    _keyboard[A_CASE] = 'a';
    _keyboard[B_CASE] = 'b';
    _keyboard[C_CASE] = 'c';
    _keyboard[D_CASE] = 'd';
    _keyboard[E_CASE] = 'e';
    _keyboard[F_CASE] = 'f';
    _keyboard[G_CASE] = 'g';
    _keyboard[H_CASE] = 'h';
    _keyboard[I_CASE] = 'i';
    _keyboard[J_CASE] = 'j';
    _keyboard[K_CASE] = 'k';
    _keyboard[L_CASE] = 'l';
    _keyboard[M_CASE] = 'm';
    _keyboard[N_CASE] = 'n';
    _keyboard[O_CASE] = 'o';
    _keyboard[P_CASE] = 'p';
    _keyboard[Q_CASE] = 'q';
    _keyboard[R_CASE] = 'r';
    _keyboard[S_CASE] = 's';
    _keyboard[T_CASE] = 't';
    _keyboard[U_CASE] = 'u';
    _keyboard[V_CASE] = 'v';
    _keyboard[W_CASE] = 'w';
    _keyboard[X_CASE] = 'x';
    _keyboard[Y_CASE] = 'y';
    _keyboard[Z_CASE] = 'z';
}

Input::~Input()
{
    _name.reset();
    _input.reset();
    _keyboard.clear();
}

void Input::clean()
{
    _name.reset(nullptr);
    _input.reset(nullptr);
}

void Input::init(SPIFactory &factory, SPIWindow &win)
{
    _name = factory->createText("Name :", Vector2<int>(800, 200), "./assets/font.ttf", *win);
    _input = factory->createText(_text, Vector2<int>(800, 240), "./assets/font.ttf", *win);
}

void Input::enterName(EventCase event)
{
    if (_text.length() < 4 && _keyboard.find(event) != _keyboard.end())
	_text += _keyboard[event];
    if (_text.length() > 0 && event == BACK_CASE)
	_text.pop_back();
}

std::string Input::getName() const
{
    return _text;
}

void Input::draw(SPIWindow &win)
{
    _input->setText(_text);
    win->show(*_name);
    win->show(*_input);
}
