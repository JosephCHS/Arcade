/*
** EPITECH PROJECT, 2019
** GameSelector.cpp
** File description:
** GameSelector class implementation
*/

#include "GameSelector.hpp"

GameSelector::GameSelector(void)
{
    this->loadGames();
}

void GameSelector::init(SPIFactory &factory, SPIWindow &win)
{
    _next = factory->createSprite("./assets/nextGame.png", Vector2<int>(550, 420), " |\n V\nnext\ngame", *win);
    _prev = factory->createSprite("./assets/prevGame.png", Vector2<int>(70, 420), "   ^\n   |\nprevious\n  game", *win);
    _title = factory->createText("Game selected:", Vector2<int>(230, 400), "./assets/font.ttf", *win);
    _name = factory->createText(_names[_games_idx], Vector2<int>(200, 440), "./assets/font.ttf", *win);
    if (_next == nullptr || _prev == nullptr || _title == nullptr || _name == nullptr)
	throw CoreException("error init game selector");
}

GameSelector::~GameSelector()
{
    _next.reset(nullptr);
    _prev.reset(nullptr);
    _title.reset(nullptr);
    _name.reset(nullptr);
    _games.clear();
    _names.clear();
    dlclose(_handle);
    _entry = nullptr;
}

void GameSelector::clean(void)
{
    _next.reset(nullptr);
    _prev.reset(nullptr);
    _title.reset(nullptr);
    _name.reset(nullptr);
}

void GameSelector::loadGames(void)
{
    std::string file;

    for(auto& p : std::filesystem::directory_iterator("games")) {
        file = p.path().filename().string();
        if (file.find("lib_arcade_") != std::string::npos
	    && file.find(".so") != std::string::npos) {
            _names.push_back(file);
	    _games.push_back(p.path().string());
	    ++_games_nbr;
	}
    }
    if (_games_nbr == 0)
	throw CoreException("no games");
    _handle = dlopen(_games[0].c_str(), RTLD_LAZY);
    if (_handle == nullptr)
	throw CoreException("bad game");
    _entry = (SPIGame (*)(void))dlsym(_handle, "createGame");
    if (_entry == nullptr)
	throw CoreException("bad sym");
}

void GameSelector::draw(SPIWindow &win)
{
    _name->setText(_names[_games_idx]);
    win->show(*_next);
    win->show(*_prev);
    win->show(*_title);
    win->show(*_name);
}

void GameSelector::nextGame(void)
{
    if (_games_idx < (_games_nbr - 1)) {
	++_games_idx;
	dlclose(_handle);
	_handle = dlopen(_games[_games_idx].c_str(), RTLD_LAZY);
	if (_handle == nullptr)
	    throw CoreException("bad game");
	_entry = (SPIGame (*)(void))dlsym(_handle, "createGame");
	if (_entry == nullptr)
	    throw CoreException("bad sym");
    }
}

void GameSelector::reset(void)
{
    dlclose(_handle);
    _handle = dlopen(_games[_games_idx].c_str(), RTLD_LAZY);
    if (_handle == nullptr)
	throw CoreException("bad game");
    _entry = (SPIGame (*)(void))dlsym(_handle, "createGame");
    if (_entry == nullptr)
	throw CoreException("bad sym");
}

void GameSelector::prevGame(void)
{
    if (_games_idx > 0) {
	--_games_idx;
	dlclose(_handle);
	_handle = dlopen(_games[_games_idx].c_str(), RTLD_LAZY);
	if (_handle == nullptr)
	    throw CoreException("bad game");
	_entry = (SPIGame (*)(void))dlsym(_handle, "createGame");
	if (_entry == nullptr)
	    throw CoreException("bad sym");
    }
}

SPIGame GameSelector::game(void)
{
    return _entry();
}
