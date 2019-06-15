/*
** EPITECH PROJECT, 2019
** HighScore.hpp
** File description:
** HighScore class definition
*/

#ifndef HIGHSCORE_HPP_
#define HIGHSCORE_HPP_

#include <vector>
#include <map>
#include <filesystem>

#include "Exception/CoreException.hpp"
#include "IFactory.hpp"

class HighScore
{
private:
    std::vector<std::string> _games;
    std::map<std::string, std::vector<int>> _scores;
    std::map<std::string, std::vector<std::string>> _names;
    int _games_nbr = 0;
    int _games_idx = 0;
    UPIText _title = nullptr;
    UPIText _game = nullptr;
    UPIText _name1 = nullptr;
    UPIText _name2 = nullptr;
    UPIText _name3 = nullptr;
    UPIText _score1 = nullptr;
    UPIText _score2 = nullptr;
    UPIText _score3 = nullptr;

    void loadGames();
public:
    HighScore();
    ~HighScore();

    void clean();
    void init(SPIFactory &, SPIWindow &);
    void draw(SPIWindow &);
    void nextScore();
    void prevScore();
    void addScore(const std::string &, int);
};

#endif
