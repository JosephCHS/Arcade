/*
** EPITECH PROJECT, 2018
** Game.cpp
** File description:
** Game Class
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include "Game.hpp"

Game::~Game()
{
    clear_all();
}

void Game::fill_vector()
{
    int nbr = -1;

    _pos_block.push_back({160, 120});
    _pos_block.push_back({160, 160});
    _pos_block.push_back({160, 200});
    _pos_block.push_back({160, 240});
    _pos_block.push_back({160, 280});
    _pos_block.push_back({160, 320});
    _pos_block.push_back({120, 280});
    _pos_block.push_back({200, 280});
    _pos_block.push_back({240, 280});
    _pos_block.push_back({280, 280});
    _pos_block.push_back({280, 320});
    _pos_block.push_back({320, 280});
    _pos_block.push_back({280, 240});
    _pos_block.push_back({280, 200});
    _pos_block.push_back({280, 160});
    _pos_block.push_back({280, 120});
    while (++nbr != 16) {
        _print_block.push_back(true);
    }
}

void Game::clear_all()
{
    _pos_block.clear();
    _print_block.clear();
    _middle = nullptr;
    _wall = nullptr;
    _space = nullptr;
    _shot = nullptr;
    _block = nullptr;
    _eshot = nullptr;
    _espace = nullptr;
    _clock = nullptr;
    _key = nullptr;
    _art = nullptr;
    _score = nullptr;
    _lost = false;
}

void Game::init(SPIFactory factory, SPIWindow window)
{
    this->_factory = factory;
    this->_window = window;
    if (factory == nullptr || window == nullptr) {
        clear_all();
        return;
    }
    _score_nbr = 0;
    Vector2<int> pos = {0, 0};
    std::string middle_string = "#                                           #";
    std::string wall_string = "# # # # # # # # # # # # # # # # # # # # # #";
    this->_score = factory->createText("Score : 0", {0, 480}, "./games/assets_solarfox/font.ttf", *window);
    this->_wall = factory->createSprite("./games/assets_solarfox/wall.png", pos, wall_string, *window);
    this->_art = factory->createSprite("./games/assets_solarfox/solar_fox-art.jpg", {480, 0}, "//SOLAR FOX\\", *window);
    this->_middle = factory->createSprite("./games/assets_solarfox/middle.png", pos, middle_string, *window);
    this->_space = factory->createSprite("./games/assets_solarfox/space.png", {40, 40}, "[]", *window);
    this->_space->setRect({0, 0, 40, 40});
    this->_shot = factory->createSprite("./games/assets_solarfox/shot.png", {120, 120}, "**", *window);
    this->_block = factory->createSprite("./games/assets_solarfox/block.png", pos, "/\\", *window);
    fill_vector();
    this->_espace = factory->createSprite("./games/assets_solarfox/espace.png", pos, "@", *window);
    this->_espace->setRect({0, 0, 40, 40});
    this->_eshot = factory->createSprite("./games/assets_solarfox/eshot.png", pos, "<>", *window);
    this->_clock = factory->createClock();
    this->_key = factory->createText("UP:Z DOWN:S LEFT:Q RIGHT:D A:Boost E:Shoot", {0, 600}, "./games/assets_solarfox/font.ttf", *window);
    _lost = false;
    _move = DOWN;
    return;
}

void Game::show_block()
{
    auto pos_it = _pos_block.begin();
    auto print_it = _print_block.begin();
    int nbr = 0;

    while (pos_it != _pos_block.end()) {
        if (*print_it == true) {
            _block->setPosition(*pos_it);
            nbr++;
            _window->show(*_block);
        }
        pos_it++;
        print_it++;
    }
    if (nbr == 0) {
        _lost = true;
    }
}

Vector2<int> Game::swap_vector2(Vector2<int> to_swap)
{
    int copy = to_swap.x;

    to_swap.x = to_swap.y;
    to_swap.y = copy;
    return to_swap;
}

void Game::move_enemy()
{
    long int move;

    if (_pos_left_enemy.x >= 400 && _pos_right_enemy.y <= 40 && _backward == false) {
        _default_left = {400, 0};
        _default_right = {440, 40};
        less_time_move = _clock->getTime() * -1 / 1250;
        _backward = true;
    }
    if (_pos_left_enemy.x <= 40 && _pos_right_enemy.y >= 400 && _backward == true) {
        less_time_move = _clock->getTime() * -1 / 1250;
        _default_left = {40, 0};
        _default_right = {440, 400};
        _backward = false;
    }
    move = ((_clock->getTime() / 1250) + less_time_move) * -1;
    if (_backward == false) {
        _pos_left_enemy.x = _default_left.x + move;
        _pos_right_enemy.y = _default_right.y - move;
    } else if (_backward == true) {
        _pos_left_enemy.x = _default_left.x - move;
        _pos_right_enemy.y = _default_right.y + move;
    }
    return;
}

void Game::show_enemy()
{
    _espace->setRect({0, 0, 40, 40});
    _espace->setPosition(_pos_left_enemy);
    _pos_left_enemy = swap_vector2(_pos_left_enemy);
    _window->show(*_espace);
    _espace->setRect({80, 0, 40, 40});
    _espace->setPosition(_pos_left_enemy);
    _window->show(*_espace);
    _pos_left_enemy = swap_vector2(_pos_left_enemy);

    _espace->setRect({40, 0, 40, 40});
    _espace->setPosition(_pos_right_enemy);
    _pos_right_enemy = swap_vector2(_pos_right_enemy);
    _window->show(*_espace);
    _espace->setRect({120, 0, 40, 40});
    _espace->setPosition(_pos_right_enemy);
    _window->show(*_espace);
    _pos_right_enemy = swap_vector2(_pos_right_enemy);
}

void Game::print_map()
{
    int nbr = -1;
    Vector2<int> pos = {0, 0};

    _wall->setPosition(pos);
    _window->show(*_wall);
    while (++nbr != 10) {
        pos.y += 40;
        _middle->setPosition(pos);
        _window->show(*_middle);
    }
    pos.y += 40;
    _wall->setPosition(pos);
    _window->show(*_wall);
    return;
}

void Game::shot_space()
{
    static long int last = _clock->getTime() / 1250 * -1;
    long int advance = _clock->getTime() / 1250 * -1;
    static Vector2<int> pos_shot;
    static bool shot = false;
    static int nbr = 0;
    static Move direction;

    if (_event == E_CASE && shot == false) {
        shot = true;
        pos_shot = _space->getPosition();
        direction = _move;
    }
    if (shot == true) {
        switch (direction)
        {
            case UP:
                pos_shot.y -= advance - last + 8;
                break;
            case RIGHT:
                pos_shot.x += advance - last + 8;
                break;
            case LEFT:
                pos_shot.x -= advance - last + 8;
                break;
            default:
                pos_shot.y += advance - last + 8;
                break;
        }
        nbr += advance - last + 8;
        _shot->setPosition(pos_shot);
        _window->show(*_shot);
    }
    if (nbr >= 80) {
        nbr = 0;
        shot = false;
    }
    last = advance;
}

void Game::move_player()
{
    long int advance = 0;
    static long int last = _clock->getTime() / 1250 * -1;

    switch (_event)
    {
        case Z_CASE:
            if (_move != DOWN && _move != UP) {
                _move = UP;
                _space->setRect({80, 0, 40, 40});
            }
            break;
        case Q_CASE:
            if (_move != RIGHT && _move != LEFT) {
                _move = LEFT;
                _space->setRect({40, 0, 40, 40});
            }
            break;
        case S_CASE:
            if (_move != UP && _move != DOWN) {
                _move = DOWN;
                _space->setRect({0, 0, 40, 40});
            }
            break;
        case D_CASE:
            if (_move != LEFT && _move != RIGHT) {
                _move = RIGHT;
                _space->setRect({120, 0, 40, 40});
            }
            break;
        case A_CASE:
            if (_boost == 4) {
                _boost = 1;
            } else {
                _boost = 4;
            }
            break;
        default:
            break;
    }
    advance = _clock->getTime() / 1250 * -1;
    switch (_move)
    {
        case DOWN:
            pos_player.y += (advance - last + _boost);
        break;
        case UP:
            pos_player.y -= (advance - last + _boost);
        break;
        case RIGHT:
            pos_player.x += (advance - last + _boost);
        break;
        case LEFT:
            pos_player.x -= (advance - last + _boost);
        break;
    }
    last = advance;
    _space->setPosition(pos_player);
}

void Game::shot_next_enemy()
{
    static long int last = _clock->getTime() / 1250 * -1;
    long int advance = _clock->getTime() / 1250 * -1;

    _shot_next_enemy += advance - last;
    if (_shot_next_enemy > 100) {
        _shot_bool.shot_3 = true;
        _shot_bool.shot_4 = true;
        _show_next_enemy = true;
        _shot_next_enemy = 0;
        pos_shot_next_enemy = _pos_right_enemy;
    }
    if (_show_next_enemy == true) {
        pos_shot_next_enemy.x -= advance - last + 2;
        if (_shot_bool.shot_3 == true) {
            _eshot->setPosition(pos_shot_next_enemy);
            _shot_bool.shot_3_pos = pos_shot_next_enemy;
            _window->show(*_eshot);
        } else {
            _shot_bool.shot_3_pos = {440, 400};
        }
        if (_shot_bool.shot_4 == true) {
            pos_shot_next_enemy = swap_vector2(pos_shot_next_enemy);
            _eshot->setPosition(pos_shot_next_enemy);
            _window->show(*_eshot);
            _shot_bool.shot_4_pos = pos_shot_next_enemy;
            pos_shot_next_enemy = swap_vector2(pos_shot_next_enemy);
        } else {
            _shot_bool.shot_4_pos = {400, 440};
        }
    }
    if (pos_shot_next_enemy.x <= 200) {
        _show_next_enemy = false;
        _shot_bool.shot_3 = false;
        _shot_bool.shot_4 = false;
        _shot_bool.shot_3_pos = {440, 400};
        _shot_bool.shot_4_pos = {400, 440};
    }
    last = advance;
}

void Game::shot_enemy()
{
    static long int last = _clock->getTime() / 1250 * -1;
    long int advance = _clock->getTime() / 1250 * -1;

    _shot_enemy += advance - last;
    if (_shot_enemy > 100) {
        _shot_bool.shot_1 = true;
        _shot_bool.shot_2 = true;
        _show_enemy = true;
        _shot_enemy = 0;
        pos_shot_enemy = _pos_left_enemy;
    }
    if (_show_enemy == true) {
        pos_shot_enemy.y += advance - last + 2;
        if (_shot_bool.shot_1 == true) {
            _eshot->setPosition(pos_shot_enemy);
            _shot_bool.shot_1_pos = pos_shot_enemy;
            _window->show(*_eshot);
        } else {
            _shot_bool.shot_1_pos = {40, 0};
        }
        if (_shot_bool.shot_2 == true) {
            pos_shot_enemy = swap_vector2(pos_shot_enemy);
            _eshot->setPosition(pos_shot_enemy);
            _window->show(*_eshot);
            _shot_bool.shot_2_pos = pos_shot_enemy;
            pos_shot_enemy = swap_vector2(pos_shot_enemy);
        } else {
            _shot_bool.shot_2_pos = {0, 40};
        }
    }
    if (pos_shot_enemy.y >= 250) {
        _shot_bool.shot_1 = false;
        _shot_bool.shot_2 = false;
        _shot_bool.shot_1_pos = {40, 0};
        _shot_bool.shot_2_pos = {0, 40};
        _show_enemy = false;
    }
    last = advance;
    shot_next_enemy();
}

void Game::check_block_colision()
{
    auto pos_it = _pos_block.begin();
    auto print_it = _print_block.begin();
    Vector2<int> block;
    Vector2<int> space = _space->getPosition();
    Vector2<int> shot = _shot->getPosition();

    while (pos_it != _pos_block.end()) {
        block = *pos_it;
        if (space.x + 10 < block.x + 40
        && space.x + 30 > block.x 
        && space.y + 10 < block.y + 40 
        && 30 + space.y > block.y) {
            *print_it = false;
        }
        if (shot.x + 10 < block.x + 40
        && shot.x + 30 > block.x 
        && shot.y + 10 < block.y + 40 
        && 30 + shot.y > block.y) {
            *print_it = false;
        }
        pos_it++;
        print_it++;
    }
}

void Game::show_score()
{
    static long int last = _clock->getTime() / 1250 * -1;
    long int advance = _clock->getTime() / 1250 * -1;
    auto print_it = _print_block.begin();
    int score = 0;
    std::string score_string = "Score : ";

    time_less += (advance - last) / 100;
    while (print_it != _print_block.end()) {
        if (*print_it == false) {
            score += 500;
        }
        print_it++;
    }
    _score_nbr = score - time_less;
    if (_score_nbr < 0) {
        _score_nbr = 0;
    }
    score_string += std::to_string(_score_nbr);
    _score->setText(score_string);
    _window->show(*_score);
}

int Game::run(EventCase e)
{
    _event = e;
    print_map();
    check_block_colision();
    show_block();
    move_enemy();
    show_enemy();
    shot_enemy();
    move_player();
    shot_space();
    check_shot();
    _window->show(*_space);
    _window->show(*_art);
    _window->show(*_key);
    show_score();
    return _score_nbr;
}

void Game::reset()
{
    _space->setPosition({40, 40});
    _space->setRect({0, 0, 40, 40});
    _shot->setPosition({0, 0});
    _eshot->setPosition({0, 0});
    _espace->setPosition({0, 40});
    _pos_block.clear();
    _print_block.clear();
    pos_player = {40, 40};
    _show_next_enemy = false;
    _show_enemy = false;
    _boost = 1;
    fill_vector();
    less_time_move = _clock->getTime() * -1 / 1250;
    _pos_left_enemy = {40, 0};
    _pos_right_enemy = {440, 400};
    pos_shot_enemy = {0, 0};
    pos_shot_next_enemy = {0, 0};
    _shot_bool.prep_shot();
    _shot_bool.reset_pos();
    _default_left = {40, 0};
    _default_right = {440, 400};
    _backward = false;
    _move = DOWN;
    _score->setText("Score : 0");
    _lost = false;
    _score_nbr = 0;
    _shot_enemy = 0;
    _shot_next_enemy = 0;
    time_less = 0;
}

static bool check_shot_collision(Vector2<int> pos, Vector2<int> space_pos)
{
    if (space_pos.x + 10 < pos.x + 40
        && space_pos.x + 30 > pos.x 
        && space_pos.y + 10 < pos.y + 40 
        && 30 + space_pos.y > pos.y) {
            return true;
    }
    return false;
}

static bool check_shot_to_shot_collision(Vector2<int> pos, Vector2<int> space_pos)
{
    if (space_pos.x + 10 < pos.x + 40
        && space_pos.x + 30 > pos.x 
        && space_pos.y + 10 < pos.y + 40 
        && 30 + space_pos.y > pos.y) {
            return false;
    }
    return true;
}

void Game::check_shot()
{
    Vector2<int> space_pos = _space->getPosition();

    if (_shot_bool.shot_1 == true) {
        _shot_bool.shot_1 = check_shot_to_shot_collision(_shot_bool.shot_1_pos, _shot->getPosition());
    }
    if (_shot_bool.shot_2 == true) {
        _shot_bool.shot_2 = check_shot_to_shot_collision(_shot_bool.shot_2_pos, _shot->getPosition());
    }
    if (_shot_bool.shot_3 == true) {
        _shot_bool.shot_3 = check_shot_to_shot_collision(_shot_bool.shot_3_pos, _shot->getPosition());
    }
    if (_shot_bool.shot_4 == true) {
        _shot_bool.shot_4 = check_shot_to_shot_collision(_shot_bool.shot_4_pos, _shot->getPosition());
    }

    if (check_shot_collision(_shot_bool.shot_1_pos, space_pos)
    || check_shot_collision(_shot_bool.shot_2_pos, space_pos)
    || check_shot_collision(_shot_bool.shot_3_pos, space_pos)
    || check_shot_collision(_shot_bool.shot_4_pos, space_pos))
        _lost = true;
}

bool Game::gameOver() const
{
    Vector2<int> space_pos = _space->getPosition();

    if (space_pos.x <= 30 || space_pos.x >= 405
    || space_pos.y <= 30 || space_pos.y >= 405) {
        return true;
    }
    return _lost;
}
