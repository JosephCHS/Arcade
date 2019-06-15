/*
** EPITECH PROJECT, 2019
** HighScore.cpp
** File description:
** HighScore class definition
*/

#include "HighScore.hpp"

HighScore::HighScore()
{
    this->loadGames();
}

HighScore::~HighScore()
{
    _title = nullptr;
    _game = nullptr;
    _name1 = nullptr;
    _name2 = nullptr;
    _name3 = nullptr;
    _score1 = nullptr;
    _score2 = nullptr;
    _score3 = nullptr;
    _games.clear();
    _scores.clear();
    _names.clear();
}

void HighScore::loadGames(void)
{
    std::string file;

    for(auto& p : std::filesystem::directory_iterator("games")) {
        file = p.path().filename().string();
        if (file.find("lib_arcade_") != std::string::npos
	    && file.find(".so") != std::string::npos) {
            _games.push_back(file);
	    ++_games_nbr;
	}
    }
    if (_games_nbr == 0)
	throw CoreException("no games");
}

void HighScore::clean(void)
{
    _title = nullptr;
    _game = nullptr;
    _name1 = nullptr;
    _name2 = nullptr;
    _name3 = nullptr;
    _score1 = nullptr;
    _score2 = nullptr;
    _score3 = nullptr;
}

void HighScore::init(SPIFactory &factory, SPIWindow &win)
{
    auto it = _games.begin();

    while (it != _games.end()) {
	_scores[*it].push_back(0);
	_scores[*it].push_back(0);
	_scores[*it].push_back(0);
	_names[*it].push_back("Name");
	_names[*it].push_back("Name");
	_names[*it].push_back("Name");
	++it;
    }
    _title = factory->createText("HighScore : ", Vector2<int>(1200, 200), "./assets/font.ttf", *win);
    _game = factory->createText(_games[_games_idx], Vector2<int>(1400, 200), "./assets/font.ttf", *win);
    _name1 = factory->createText(_names[_games[_games_idx]][0], Vector2<int>(1200, 300), "./assets/font.ttf", *win);
    _name2 = factory->createText(_names[_games[_games_idx]][1], Vector2<int>(1200, 400), "./assets/font.ttf", *win);
    _name3 = factory->createText(_names[_games[_games_idx]][2], Vector2<int>(1200, 500), "./assets/font.ttf", *win);
    _score1 = factory->createText(std::to_string(_scores[_games[_games_idx]][0]), Vector2<int>(1300, 300), "./assets/font.ttf", *win);
    _score2 = factory->createText(std::to_string(_scores[_games[_games_idx]][1]), Vector2<int>(1300, 400), "./assets/font.ttf", *win);
    _score3 = factory->createText(std::to_string(_scores[_games[_games_idx]][2]), Vector2<int>(1300, 500), "./assets/font.ttf", *win);
}

void HighScore::draw(SPIWindow &win)
{
    _game->setText(_games[_games_idx]);
    _name1->setText(_names[_games[_games_idx]][0]);
    _name2->setText(_names[_games[_games_idx]][1]);
    _name3->setText(_names[_games[_games_idx]][2]);
    _score1->setText(std::to_string(_scores[_games[_games_idx]][0]));
    _score2->setText(std::to_string(_scores[_games[_games_idx]][1]));
    _score3->setText(std::to_string(_scores[_games[_games_idx]][2]));
    win->show(*_title);
    win->show(*_game);
    win->show(*_name1);
    win->show(*_name2);
    win->show(*_name3);
    win->show(*_score1);
    win->show(*_score2);
    win->show(*_score3);
}

void HighScore::nextScore()
{
    if (_games_idx < (_games_nbr - 1))
	++_games_idx;
}

void HighScore::prevScore()
{
    if (_games_idx > 0)
	--_games_idx;
}

void HighScore::addScore(const std::string &name, int score)
{
    if (score > _scores[_games[_games_idx]][0]) {
	_scores[_games[_games_idx]][2] = _scores[_games[_games_idx]][1];
	_names[_games[_games_idx]][2] = _names[_games[_games_idx]][1];
	_scores[_games[_games_idx]][1] = _scores[_games[_games_idx]][0];
	_names[_games[_games_idx]][1] = _names[_games[_games_idx]][0];
	_scores[_games[_games_idx]][0] = score;
	if (!name.empty())
	    _names[_games[_games_idx]][0] = name;
	else
	    _names[_games[_games_idx]][0] = "name";
	return;
    }
    if (score > _scores[_games[_games_idx]][1]) {
	_scores[_games[_games_idx]][2] = _scores[_games[_games_idx]][1];
	_names[_games[_games_idx]][2] = _names[_games[_games_idx]][1];
	_scores[_games[_games_idx]][1] = score;
	if (!name.empty())
	    _names[_games[_games_idx]][1] = name;
	else
	    _names[_games[_games_idx]][1] = "name";
	return;
    }
    if (score > _scores[_games[_games_idx]][1]) {
	_scores[_games[_games_idx]][2] = score;
	if (!name.empty())
	    _names[_games[_games_idx]][2] = name;
	else
	    _names[_games[_games_idx]][2] = "name";
	return;
    }
}
