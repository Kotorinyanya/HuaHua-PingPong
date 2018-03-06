//
//  Game.cpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#include "Game.hpp"

void Game::Menu()
{
    _mainWindow.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HIGHT),"HUAJI!");
    
    sf::Font font;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    std::stringstream ss;
    ss << "HUAJI PONG GAME" << "\n\n" << "Developed by SFML 2.4.2" << "\n\n" << "Huzheng Yang  2017060901013" << "\n\n\n" << "PRESS A BUTTON TO CONTIUNE" << "\n\n\n\n\n" << "Hint: Press UP to perfrom a STRIKE";
    sf::Text MenuText(ss.str(), font, 60);
    
    while(true)
    {
        _mainWindow.clear(sf::Color(0,0,0));
        _mainWindow.draw(MenuText);
        _mainWindow.display();
        
        if(_currentEvent.type == sf::Event::KeyPressed || GetInput().type == sf::Event::MouseButtonPressed)
        {
            break;
        }
    }
    
    Game::Start();
}

void Game::Start()
{
    //_mainWindow.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HIGHT),"HUAJI!");
    
    Paddle *player = new Paddle();
    player->SetPosition((WINDOW_WIDTH/2),WINDOW_HIGHT-20);
    
    AI *AIplayer = new AI();
    AIplayer->SetPosition((WINDOW_WIDTH/2),20);
    
    Ball *ball = new Ball();
    ball->SetPosition((WINDOW_WIDTH/2),(WINDOW_HIGHT/2)-15);
    
    ScoreBoard *scoreBoard = new ScoreBoard();
    
    _gameObjectManager.Add("Paddle",player);
    _gameObjectManager.Add("Ball",ball);
    _gameObjectManager.Add("AIPaddle", AIplayer);
    _gameObjectManager.Add("ScoreBoard", scoreBoard);
    
    while(true)
    {
        GetInput();
        _mainWindow.clear(sf::Color(0,0,0));
        _gameObjectManager.UpdateAll();
        _gameObjectManager.DrawAll(_mainWindow);
        
        _mainWindow.display();
        
        if(_currentEvent.type == sf::Event::Closed)
        {
            break;
        }
    }
    _mainWindow.close();
}


const sf::Event& Game::GetInput()
{
    _mainWindow.pollEvent(_currentEvent);
    return _currentEvent;
}

const GameObjectManager& Game::GetGameObjectManager()
{
    return Game::_gameObjectManager;
}

sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
sf::Event Game::_currentEvent;


