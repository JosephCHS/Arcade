/*
** EPITECH PROJECT, 2019
** Arcade.cpp
** File description:
** Arcade class implementation
*/

#include <sstream>
#include <fstream>
#include <iostream>
#include <exception>

#include "Arcade.hpp"

std::string Arcade::file2string(const std::string &path)
{
    std::ifstream file(path);
    std::stringstream out;

    out << file.rdbuf();
    return out.str();
}

Arcade::Arcade(const std::string &path) : _libs(path)
{
    _factory.reset(_libs.getLib());
    _win = _factory->createWindow(Vector2<int>(1920, 1080), "Arcade");
    _libs.init(_factory, _win);
    _games.init(_factory, _win);
    _input.init(_factory, _win);
    _highscore.init(_factory, _win);
    _title = _factory->createText("ARCADE", Vector2<int>(850, 50), "./assets/font.ttf", *_win);
    _title->setSize(40);
    _play = _factory->createSprite("./assets/button.png", Vector2<int>(200, 700), this->file2string("./assets/button.txt"), *_win);
    _play->setSize(Vector2<int>(250, 200));
    _bind = _factory->createSprite("./assets/bind.png", Vector2<int>(700, 700), this->file2string("./assets/bind.txt"), *_win);
}

Arcade::~Arcade()
{
    _win = nullptr;
    _factory = nullptr;
    _game = nullptr;
    _title = nullptr;
    _play = nullptr;
    _bind = nullptr;
    _games.clean();
    _input.clean();
    _highscore.clean();
}

void Arcade::prepareChange(void)
{
    _win->close();
    _win.reset();
    _factory.reset();
    _games.clean();
    _input.clean();
    _title = nullptr;
    _play = nullptr;
    _bind = nullptr;
    _highscore.clean();
    if (_game != nullptr)
        _game->init(_factory, _win);
}

void Arcade::changeLib(void)
{
    _factory.reset(_libs.getLib());
    _win = _factory->createWindow(Vector2<int>(1920, 1080), "Arcade");
    _libs.init(_factory, _win);
    _games.init(_factory, _win);
    _input.init(_factory, _win);
    _highscore.init(_factory, _win);
    _title = _factory->createText("ARCADE", Vector2<int>(850, 50), "./assets/font.ttf", *_win);
    _title->setSize(40);
    _play = _factory->createSprite("./assets/button.png", Vector2<int>(200, 700), this->file2string("./assets/button.txt"), *_win);
    _play->setSize(Vector2<int>(250, 200));
    _bind = _factory->createSprite("./assets/bind.png", Vector2<int>(700, 700), this->file2string("./assets/bind.txt"), *_win);
    if (_game != nullptr)
	_game->init(_factory, _win);
}

void Arcade::checkEventCases(EventCase &now)
{
    switch (now) {
    case ECHAP_CASE:
	_win->close();
	now = WINDOW_CLOSE;
	break;
    case ARIGHT_CASE:
	if (_libs.canNext() == true) {
	    this->prepareChange();
	    _libs.nextLib();
	    this->changeLib();
	}
	break;
    case ALEFT_CASE:
	if (_libs.canPrev() == true) {
	    this->prepareChange();
	    _libs.prevLib();
	    this->changeLib();
	}
	break;
    case AUP_CASE:
	if (_game == nullptr) {
	    _games.prevGame();
	    _highscore.prevScore();
	}
	break;
    case ADOWN_CASE:
	if (_game == nullptr) {
	    _games.nextGame();
	    _highscore.nextScore();
	}
	break;
    case RETURN_CASE:
	if (_game == nullptr) {
	    _score = 0;
	    _game = _games.game();
	    _game->init(_factory, _win);
	}
	break;
    case BACK_CASE:
	_game.reset();
	break;
    case R_CASE:
	if (_game != nullptr)
	    _game->reset();
        break;
    default: break;
    }
}

void Arcade::displayMenu(void)
{
    _win->show(*_title);
    _win->show(*_play);
    _win->show(*_bind);
    _libs.draw(_win);
    _games.draw(_win);
    _input.draw(_win);
    _highscore.draw(_win);
}

int Arcade::start(void)
{
    EventCase now = NO_EVENT;

    while (now != WINDOW_CLOSE) {
        _win->correctFrameRate();
	_win->clear(Vector4<int>(0,0,0,255));
        now = _win->getLastEvent();
        this->checkEventCases(now);
        if (now == WINDOW_CLOSE)
            continue;
        if (_game != nullptr && _game->gameOver() == true) {
            _game.reset();
	    _games.reset();
	    _highscore.addScore(_input.getName(), _score);
        }
        if (_game != nullptr && _game->gameOver() == false)
            _score = _game->run(now);
        else {
	    _input.enterName(now);
            this->displayMenu();
	}
	_win->display();
    }
    return 0;
}
