//
//  ScoreBoard.cpp
//  My Game
//
//  Created by SRT_KID on 11/15/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#include "ScoreBoard.hpp"

ScoreBoard::ScoreBoard():
    _PlayerScore(0),
    _AIScore(0),
    _level(1)
{
    Load(resourcePath() + "sansation.ttf");
    _text.setFillColor(sf::Color::White);
}

ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::Load(std::string filename)
{
    _font.loadFromFile(filename);
    _text.setFont(_font);
}

void ScoreBoard::Draw(sf::RenderWindow & renderWindow)
{
    renderWindow.draw(_text);
}

void ScoreBoard::PlayerScoreUp()
{
    _PlayerScore += 1;
    return;
}

void ScoreBoard::AIScoreUp()
{
    _AIScore += 1;
    return;
}

void ScoreBoard::PlayerScoreUp100()
{
    _PlayerScore += 100;
    _level += 1;
    return;
}

void ScoreBoard::AIScoreUp100()
{
    _AIScore += 100;
    return;
}

void ScoreBoard::LevelUp()
{
    _level += 1;
}


void ScoreBoard::Update(float elapsedTime)
{
    std::stringstream ss;
    ss << "Player : " << _PlayerScore << "\n" << "AI : " << _AIScore << "\n\n" << "LEVEL: " << _level;
    _text.setString(ss.str());
}
