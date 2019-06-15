/*
** EPITECH PROJECT, 2019
** LibSelector.cpp
** File description:
** LibSelector class implementation
*/

#include <iostream>

#include "LibSelector.hpp"

LibSelector::LibSelector(const std::string &path)
{
    this->loadLibs(path);
    if (_libs_nbr == 0)
	throw CoreException("no libs");
}

void LibSelector::init(SPIFactory &factory, SPIWindow &win)
{
    _next = factory->createSprite("./assets/nextLib.png", Vector2<int>(550, 220), " ->\nnext\nlib", *win);
    _prev = factory->createSprite("./assets/prevLib.png", Vector2<int>(70, 220), "   <-\nprevious\n  lib", *win);
    _title = factory->createText("Library selected:", Vector2<int>(200, 200), "./assets/font.ttf", *win);
    _name = factory->createText(_names[_libs_idx], Vector2<int>(200, 240), "./assets/font.ttf", *win);
    if (_next == nullptr || _prev == nullptr || _title == nullptr || _name == nullptr)
	throw CoreException("error lib selector init");
}

LibSelector::~LibSelector()
{
    _next = nullptr;
    _prev = nullptr;
    _title = nullptr;
    _name = nullptr;
    _names.clear();
    _libs.clear();
    _creator = nullptr;
    dlclose(_handle);
}

IFactory *LibSelector::getLib(void)
{
    return _creator();
}

void LibSelector::loadLibs(const std::string &path)
{
    std::string file;

    for(auto& p : std::filesystem::directory_iterator("lib")) {
	file = p.path().filename().string();
	if (file.find("lib_arcade_") != std::string::npos
	    && file.find(".so") != std::string::npos) {
	    _names.push_back(file);
	    _libs.push_back(p.path().string());
	    if (p.path().string() == path)
		_libs_idx = _libs_nbr;
	    ++_libs_nbr;
	}
    }
    _handle = dlopen(path.c_str(), RTLD_LAZY);
    if (_handle == nullptr) {
	throw CoreException("bad lib");
    }
    _creator = (IFactory *(*)(void))dlsym(_handle, "createFactory");
    if (_creator  == nullptr) {
	throw CoreException("bas sym");
    }
}

void LibSelector::draw(SPIWindow &win)
{
    _name->setText(_names[_libs_idx]);
    win->show(*_next);
    win->show(*_prev);
    win->show(*_title);
    win->show(*_name);
}

bool LibSelector::canNext()
{
    return (_libs_idx < (_libs_nbr - 1));
}

bool LibSelector::canPrev()
{
    return (_libs_idx > 0);
}

void LibSelector::nextLib()
{
    ++_libs_idx;
    _next = nullptr;
    _prev = nullptr;
    _title = nullptr;
    _name = nullptr;
    dlclose(_handle);
    _handle = dlopen(_libs[_libs_idx].c_str(), RTLD_LAZY);
    if (_handle == nullptr)
	throw CoreException("bad lib");
    _creator = (IFactory *(*)(void))dlsym(_handle, "createFactory");
    if (_creator == nullptr)
	throw CoreException("bad sym");
}

void LibSelector::prevLib()
{
    --_libs_idx;
    _next = nullptr;
    _prev = nullptr;
    _title = nullptr;
    _name = nullptr;
    dlclose(_handle);
    _handle = dlopen(_libs[_libs_idx].c_str(), RTLD_LAZY);
    if (_handle == nullptr)
	throw CoreException("bad lib");
    _creator = (IFactory *(*)(void))dlsym(_handle, "createFactory");
    if (_creator == nullptr)
	throw CoreException("bad sym");
}
