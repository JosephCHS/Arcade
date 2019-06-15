/*
** EPITECH PROJECT, 2019
** Factory.cpp
** File description:
** Factory implementation
*/

#include "Factory.hpp"
#include "../Window/Window.hpp"
#include "../IObject/Text/Text.hpp"
#include "../IObject/Sprite/Sprite.hpp"
#include "../Music/Music.hpp"
#include "../../../utils/Clock/Clock.hpp"

SPIWindow Factory::createWindow(const Vector2<int> &size, const std::string &name)
{
    return std::make_shared<Window>(size, name);
}

UPIText Factory::createText(const std::string &text, const Vector2<int> &pos,
		   const std::string &font, IWindow &win)
{
    (void)win;
    return std::make_unique<Text>(text, pos, font);
}

UPISprite Factory::createSprite(const std::string &path, const Vector2<int> &pos,
		       const std::string &text, IWindow &win)
{
    (void)text;
    (void)win;
    return std::make_unique<Sprite>(path, pos);
}

UPIMusic Factory::createMusic(const std::string &path)
{
    return std::make_unique<Music>(path);
}

UPIClock Factory::createClock()
{
    return std::make_unique<Clock>();
}

extern "C"
{
    IFactory *createFactory()
    {
	return new Factory();
    }
}
