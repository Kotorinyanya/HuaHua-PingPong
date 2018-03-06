//
//  GameObjectManager.hpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#ifndef GameObjectManager_hpp
#define GameObjectManager_hpp

#include <stdio.h>
#include "GameObject.hpp"

class GameObjectManager
{
public:
    GameObjectManager();
    ~GameObjectManager();
    
    void Add(std::string name, GameObject* gameObject);
    void Remove(std::string name);
    GameObject* Get(std::string name) const;
    
    void DrawAll(sf::RenderWindow& renderWindow);
    void UpdateAll();
    
private:
    std::map<std::string, GameObject*> _gameObjects;
    
    sf::Clock clock;
    
    struct GameObjectDeallocator
    {
        void operator()(const std::pair<std::string,GameObject*> & p) const
        {
            delete p.second;
        }
    };
};

#endif /* GameObjectManager_hpp */
