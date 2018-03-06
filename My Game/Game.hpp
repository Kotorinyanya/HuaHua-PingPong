//
//  Game.hpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "stdafx.h"
#include "GameObject.hpp"
#include "GameObjectManager.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "AI.hpp"
#include "ScoreBoard.hpp"
#include "Sound.hpp"

class Game
{
    
public:
    static void Menu();
    static void Start();
    const static sf::Event& GetInput();
    const static GameObjectManager& GetGameObjectManager();
    
    
private:
    
    static sf::RenderWindow _mainWindow;
    static GameObjectManager _gameObjectManager;
    static sf::Event _currentEvent;
    
};

#endif /* Game_hpp */

