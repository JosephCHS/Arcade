/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Game.hpp
*/
#include <iostream>

const char *map_termi =
    "   .-'''-. ,---.   .--.   ____    .--.   .--.      .-''-.   \n"
    "  / _     \\|    \\  |  | .'  __ `. |  | _/  /     .'_ _   \\                                                                                            SCORE\n"
    " (`' )/`--'|  ,  \\ |  |/   '  \\  \\| (`' ) /     / ( ` )   ' \n"
    "(_ o _).   |  |\\_ \\|  ||___|  /  ||(_ ()_)     . (_ o _)  |            Z: up S: down Q: left D: right A: accelerate E: decelerate\n"
    " (_,_). '. |  _( )_\\  |   _.-`   || (_,_)   __ |  (_,_)___|\n"
    ".---.  \\  :| (_ o _)  |.'   _    ||  |\\ \\  |  |'  \\   .---. \n"
    "\\    `-'  ||  (_,_)\\  ||  _( )_  ||  | \\ `'   / \\  `-'    / \n"
    " \\       / |  |    |  |\\ (_ o _) /|  |  \\    /   \\       /  \n"
    "  `-...-'  '--'    '--' '.(_,_).' `--'   `'-'     `'-..-'   \n"
    "___________________________________________________________________________________________________________________________________________________________________________________\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "|                                                                                                                                                                                 |\n"
    "__________________________________________________________________________________________________________________________________________________________________________________|\n";

#include "Game_Snake.hpp"

Game_Snake::Game_Snake()
{
}

Game_Snake::~Game_Snake(void)
{
    clearAll();
}

// Init, snake's head and tree parts of him and the map
// Random position for the fruit
void Game_Snake::init(SPIFactory factory, SPIWindow window)
{
    _factory = factory;
    _win = window;
    if (_factory == NULL || _win == nullptr) {
        clearAll();
        return;
    }
    _clock = _factory->createClock();
    _score_int = 0;
    std::string score = std::to_string(_score_int);
    _score_dynamic = _factory->createText(score, Vector2<int>(1650, 40), "./assets/font.ttf", *_win);
    _gameOver = false;
    _direct.x = 1;
    _direct.y = 0;

    randomFruit();
    initMap();
    _snake_pos_init.push_back({int(100.0 * 10.0), int(25.0 * 22.5)});
    _snake_pos_init.push_back({int(101.0 * 10.0), int(25.0 * 22.5)});
    _snake_pos_init.push_back({int(102.0 * 10.0), int(25.0 * 22.5)});
    _snake_pos_init.push_back({int(103.0 * 10.0), int(25.0 * 22.5)});

    int idx = 1;
    _snake_dynamic.push_back(_factory->createSprite("./games/assets_nibbler/head_snake.png", _snake_pos_init.at(0), "X", *_win));
    if (_snake_dynamic.at(0) == nullptr) {
        throw std::runtime_error("no snake to draw");
    }
    while (idx != 4) {
        _snake_dynamic.push_back(_factory->createSprite("./games/assets_nibbler/body_snake.png", _snake_pos_init.at(idx), "0", *_win));
        ++idx;
    }
}

int Game_Snake::run(EventCase ev)
{
    update_score();
    if (_spr_map_static != nullptr)
        _win->show(*_spr_map_static);
    while (_clock->getTime() >= _clock->getTime() + 100) {}
    updateSnake(ev);
    isGameOver();
    return _score_int;
}

// Init the map for the terminal game and graph game
void Game_Snake::initMap()
{
    _spr_map_static = _factory->createSprite("./games/assets_nibbler/map_graph.png", {0, 0}, map_termi, *_win);
    if (_spr_map_static == nullptr) {
        throw std::runtime_error("no map to draw");
    }
    _spr_fruit_dynamic = _factory->createSprite("./games/assets_nibbler/food_snake.png", _fruit_pos, "!", *_win);
    if (_spr_fruit_dynamic == nullptr) {
        throw std::runtime_error("no fruit to draw");
    }
}

void Game_Snake::reset()
{
    _snake_pos_init.clear();
    _snake_dynamic.clear();
    init(_factory, _win);
}

// Check if the head of the snake hit the wall and after that if the head hit the body
void Game_Snake::isGameOver()
{
    if (_snake_dynamic.begin() == _snake_dynamic.end()) {
        return;
    }
    if ((_snake_dynamic[0]->getPosition().y <= 215) ||
    (_snake_dynamic[0]->getPosition().y >= 980) ||
    (_snake_dynamic[0]->getPosition().x <= 20) ||
    (_snake_dynamic[0]->getPosition().x >= 1758)) {
        _gameOver = true;
        return;
    }
    int i = 2;
    for (auto iter = _snake_dynamic.begin() + 2; iter != _snake_dynamic.end(); iter++, i++) {
        if ((_snake_dynamic.at(0)->getPosition().x == _snake_dynamic.at(i)->getPosition().x)
        && (_snake_dynamic.at(0)->getPosition().y == _snake_dynamic.at(i)->getPosition().y)) {
            _gameOver = true;
            return;
        }

    }
    _gameOver = false;
    return;
}

bool Game_Snake::gameOver() const
{
    return _gameOver;
}

// Reset the game to its initial state
void Game_Snake::resetToReplay()
{
    _score_int = 0;
    _snake_pos_init.clear();
    _snake_pos_init.push_back({int(100.0 * 10.0), int(25.0 * 22.5)});
    _snake_pos_init.push_back({int(101.0 * 10.0), int(25.0 * 22.5)});
    _snake_pos_init.push_back({int(102.0 * 10.0), int(25.0 * 22.5)});
    _snake_pos_init.push_back({int(103.0 * 10.0), int(25.0 * 22.5)});
    randomFruit();
}

// Write the updated score in the game
void Game_Snake::update_score()
{
    std::string score = std::to_string(_score_int);
    Vector2<int> pos_head_tmp_new_body = _snake_dynamic.at(0)->getPosition();
    _score_dynamic->setText(score);
    if (_score_dynamic == nullptr) {
        throw std::runtime_error("no score to draw");
    }
    if ((_snake_dynamic.at(0)->getPosition().x >= _fruit_pos.x - 13 && _snake_dynamic.at(0)->getPosition().x <= _fruit_pos.x + 13 )
        && (_snake_dynamic.at(0)->getPosition().y >= _fruit_pos.y - 23 && _snake_dynamic.at(0)->getPosition().y <= _fruit_pos.y + 23)) {
        _score_int += 1;
        _snake_dynamic.insert(_snake_dynamic.begin()+1, _factory->createSprite("./games/assets_nibbler/body_snake.png", pos_head_tmp_new_body, "O", *_win));
        *_snake_pos_init.begin() = {pos_head_tmp_new_body.x + _direct.x, pos_head_tmp_new_body.y + _direct.y};
        randomFruit();
        return;
    }
}

// Update the position of the head and the body
void Game_Snake::updateSnake(EventCase ev)
{
    Vector2<int> LEFT = {-10, 0};
    Vector2<int> RIGHT = {10, 0};
    Vector2<int> BOT = {0, 10};
    Vector2<int> TOP = {0, -10};

    switch (ev) {
        case Z_CASE:
            _gameOver = false;
            _direct = TOP;
            break;
        case Q_CASE:
            _gameOver = false;
            _direct = LEFT;
            break;
        case S_CASE:
            _gameOver = false;
            _direct = BOT;
            break;
        case D_CASE:
            _gameOver = false;
            _direct = RIGHT;
            break;
        case A_CASE:
            _direct.x *= 1.5;
            _direct.y *= 1.5;
            break;
        case E_CASE:
            _direct.x *= 0.5;
            _direct.y *= 0.5;
            break;
        default:
            break;
    }
    auto begin_iter = _snake_dynamic.rbegin();
    auto async_iter = _snake_dynamic.rbegin();
    ++async_iter;
    while (async_iter != _snake_dynamic.rend()) {
        (*begin_iter)->setPosition((*async_iter)->getPosition());
        ++async_iter;
	    ++begin_iter;
    }
    Vector2<int> current_pos = _snake_dynamic[0]->getPosition();
    _snake_dynamic[0]->setPosition(Vector2<int>(current_pos.x + _direct.x, current_pos.y + _direct.y));
    for (auto show_iter = _snake_dynamic.begin(); show_iter != _snake_dynamic.end(); ++show_iter) {
        _win->show(**show_iter);
    }
    _win->show(*_spr_fruit_dynamic);
    _win->show(*_score_dynamic);
}

// Clear all to avoid big bang with the others team
void Game_Snake::clearAll()
{
    _win = nullptr;
    _factory = nullptr;
    _score_dynamic = nullptr;
    _spr_map_static = nullptr;
    _spr_fruit_dynamic = nullptr;
    _clock = nullptr;
    _snake_dynamic.clear();
    _snake_pos_init.clear();
}

void Game_Snake::randomFruit()
{
    srand(time(0));
    unsigned int xfruit = 0; 
    unsigned int yfruit = 0;

    while (yfruit <= 250 || yfruit >= 800 || xfruit <= 50 || xfruit >= 1600) {
        xfruit = rand() % 1500;
        yfruit = rand() % 900;
    }
    _fruit_pos.x = xfruit;
    _fruit_pos.y = yfruit;
    if (_spr_fruit_dynamic != nullptr) {
        _spr_fruit_dynamic->setPosition(_fruit_pos);
    }
}

extern "C" SPIGame createGame()
{
    return std::make_shared<Game_Snake>();
}
