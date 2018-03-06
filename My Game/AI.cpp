//
//  AI.cpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#include "AI.hpp"

AI::AI():
_velocity(0.0f),
_maxVelocity(400.0f),
_acceleration(5.0f),
_level(1)
{
    Load(resourcePath() + "paddle.png");
    GetSprite().setOrigin(GetSprite().getLocalBounds().width /2, GetSprite().getLocalBounds().height / 2);
}


AI::~AI()
{
}

void AI::Draw(sf::RenderWindow & rw)
{
    GameObject::Draw(rw);
}

float AI::GetVelocity() const
{
    return _velocity;
}

unsigned AI::GetLevel() const
{
    return _level;
}

void AI::LevelUp()
{
    _maxVelocity += 100.f;
    _acceleration += 5.0f;
    GetSprite().scale(1.5f, 1.0f);
    _level += 1;
}

void AI::MaxVelocityUp(float acceleration)
{
     _maxVelocity += acceleration;
}

void AI::MaxAccelerationUp(float acceleration)
{
    _acceleration += acceleration;
}

void AI::Update(float elapsedTime)
{
    const Ball* gameBall = static_cast<Ball*>(Game::GetGameObjectManager().Get("Ball"));
    sf::Vector2f ballPosition = gameBall->GetPosition();
    
    if(GetPosition().x -20 < ballPosition.x)
        _velocity += _acceleration;
    else if(GetPosition().x +20 > ballPosition.x)
        _velocity -= _acceleration;
    else if(GetPosition().x == ballPosition.x)
        _velocity = 0.0f;
    
    if(_velocity > _maxVelocity)
        _velocity = _maxVelocity;
    
    if(_velocity < -_maxVelocity)
        _velocity = -_maxVelocity;
    
    sf::Vector2f pos = this->GetPosition();
    
    /*  边缘反弹，已弃用
    if(pos.x  <= GetSprite().getLocalBounds().width/2
       || pos.x >= (WINDOW_WIDTH - GetSprite().getLocalBounds().width/2))
    {
        _velocity = -_velocity;
    }
     */
    
    GetSprite().move(_velocity * elapsedTime, 0);
}
