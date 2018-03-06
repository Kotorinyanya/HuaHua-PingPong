//
//  GameObjectManager.cpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#include "GameObjectManager.hpp"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
    std::for_each(_gameObjects.begin(),_gameObjects.end(),GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, GameObject* gameObject)
{
    _gameObjects.insert(std::pair<std::string,GameObject*>(name,gameObject));
}

void GameObjectManager::Remove(std::string name)
{
    std::map<std::string, GameObject*>::iterator results = _gameObjects.find(name);
    if(results != _gameObjects.end() )
    {
        delete results->second;
        _gameObjects.erase(results);
    }
}

GameObject* GameObjectManager::Get(std::string name) const
{
    std::map<std::string, GameObject*>::const_iterator results = _gameObjects.find(name);
    if(results == _gameObjects.end() )
        return NULL;
    return results->second;
    
}


void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
    std::map<std::string,GameObject*>::const_iterator itr = _gameObjects.begin();
    while(itr != _gameObjects.end())
    {
        itr->second->Draw(renderWindow);
        itr++;
    }
}

void GameObjectManager::UpdateAll()
{
    std::map<std::string,GameObject*>::const_iterator itr = _gameObjects.begin();
    float timeDelta = clock.restart().asSeconds();
    
    while(itr != _gameObjects.end())
    {
        itr->second->Update(timeDelta);
        itr++;
    }
    
}
