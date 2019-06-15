/*
** EPITECH PROJECT, 2018
** Enemy.hpp
** OOP_arcade_2018
** Enemy Class
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <Vector.hpp>

class Enemy
{
    public:
        bool shot_1 = true;
        bool shot_2 = true;
        bool shot_3 = true;
        bool shot_4 = true;
        Vector2<int> shot_1_pos = {40, 0};
        Vector2<int> shot_2_pos = {0, 40};
        Vector2<int> shot_3_pos = {440, 400};
        Vector2<int> shot_4_pos = {400, 440};
        void prep_shot();
        void reset_pos();
};

#endif /* ENEMY_HPP_ */