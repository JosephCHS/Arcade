/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** game.hpp
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "IGame.hpp"
#include "Enemy.hpp"

enum Move {
        UP,
        RIGHT,
        LEFT,
        DOWN
};

class Game : public IGame
{
    private:
        SPIFactory _factory;
        SPIWindow _window;
        std::unique_ptr<ISprite> _middle = nullptr;
        std::unique_ptr<ISprite> _wall = nullptr;
        std::unique_ptr<ISprite> _space = nullptr;
        std::unique_ptr<ISprite> _shot = nullptr;
        std::unique_ptr<ISprite> _block = nullptr;
        std::unique_ptr<ISprite> _eshot = nullptr;
        std::unique_ptr<ISprite> _espace = nullptr;
        std::unique_ptr<ISprite> _art = nullptr;
        std::unique_ptr<IText> _score = nullptr;
        std::unique_ptr<IText> _key = nullptr;
        UPIClock _clock = nullptr;
        std::vector<bool> _print_block;
        std::vector<Vector2<int>> _pos_block;
        Vector2<int> _pos_left_enemy = {40, 0};
        Vector2<int> _pos_right_enemy = {440, 400};
        Move _move = DOWN;
        EventCase _event;
        bool _lost = false;
        Enemy _shot_bool;
        int _score_nbr = 0;
        bool _show_enemy = false;
        bool _show_next_enemy = false;
        int time_less = 0;
        int _shot_enemy = 0;
        float _boost = 1;
        bool _backward = false;
        long int less_time_move = 0;
        int _shot_next_enemy = 0;
        Vector2<int> pos_player = {40, 40};
        Vector2<int> pos_shot_enemy = {0, 0};
        Vector2<int> pos_shot_next_enemy = {0, 0};
        Vector2<int> _default_left = {40, 0};
        Vector2<int> _default_right = {440, 400};

        void show_shot();
        Vector2<int> swap_vector2(Vector2<int>);
        void show_block();
        void print_map();
        void clear_all();
        void show_enemy();
        void move_enemy();
        void shot_space();
        void check_shot();
        void fill_vector();
        void shot_enemy();
        void show_score();
        void shot_next_enemy();
        void move_player();
        void check_block_colision();
    public:
        Game() {};
        ~Game();
        void init(SPIFactory factory, SPIWindow window) final;
        int run(EventCase e) final;
        void reset() final;
        bool gameOver() const final;
        std::string getfile(std::string);
};

#endif /* GAME_HPP_ */
