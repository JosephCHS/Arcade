/*
** EPITECH PROJECT, 2019
** Input.hpp
** File description:
** Input class définition
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <map>
#include "IFactory.hpp"

class Input
{
private:
    UPIText _name = nullptr;
    UPIText _input = nullptr;
    std::string _text;
    std::map<EventCase, char> _keyboard;
public:
    Input();
    ~Input();

    void clean();
    void init(SPIFactory &, SPIWindow &);
    void enterName(EventCase);
    void draw(SPIWindow &);
    std::string getName() const;
};

#endif
