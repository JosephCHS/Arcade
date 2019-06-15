/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Enemy.cpp
*/

#include "Enemy.hpp"

void Enemy::prep_shot()
{
    shot_1 = true;
    shot_2 = true;
    shot_3 = true;
    shot_4 = true;
}

void Enemy::reset_pos()
{
    shot_1_pos = {40, 0};
    shot_2_pos = {0, 40};
    shot_3_pos = {440, 400};
    shot_4_pos = {400, 440};
}