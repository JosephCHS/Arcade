/*
** EPITECH PROJECT, 2019
** Factory.hpp
** File description:
** Factory class Interface
*/

#ifndef FACTORY_
#define FACTORY_

#include "IFactory.hpp"

class Factory : public IFactory
{
public:
    Factory() = default;
    ~Factory() = default;
    SPIWindow    createWindow(const Vector2<int> &size, const std::string &name);
    UPIText      createText(const std::string &, const Vector2<int> &, const std::string &, IWindow &);
    UPISprite    createSprite(const std::string &, const Vector2<int> &, const std::string &, IWindow &);
    UPIMusic     createMusic(const std::string &);
    UPIClock     createClock();
};

#endif // FACTORY_
