//
//  Paddle.cpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#include "Paddle.hpp"


Paddle::Paddle():
    _velocity(0),
    _maxVelocity(1500.0f)
{
    Load(resourcePath() + "paddle.png");
    GetSprite().setOrigin(GetSprite().getLocalBounds().width /2, GetSprite().getLocalBounds().height / 2);
    GetSprite().setScale(2.0f, 1.0f);
}

Paddle::~Paddle()
{
}

void Paddle::Draw(sf::RenderWindow& rw)
{
    GameObject::Draw(rw);
}

float Paddle::GetVelocity() const
{
    return _velocity;
}

void Paddle::Update(float elapsedTime)
{
    sf::Event event = Game::GetInput();
    if(event.type == sf::Event::KeyPressed)
        switch (event.key.code)
        {
            case sf::Keyboard::Left:
                _velocity -= 20.0f;
                break;
            case sf::Keyboard::Right:
                _velocity += 20.0f;
                break;
            default:
                break;
        }
    if(_velocity >= _maxVelocity)
        _velocity = _maxVelocity;
    if(_velocity <= -_maxVelocity)
        _velocity = -_maxVelocity;
        
    if(event.type == sf::Event::KeyReleased)
        _velocity = 0.0f;
    
    sf::Vector2f pos = this->GetPosition();
    if(pos.x  < GetSprite().getLocalBounds().width/2)
        _velocity = 300.0f;
    if(pos.x > (WINDOW_WIDTH - GetSprite().getLocalBounds().width/2))
    {
        _velocity = -300.0f;
    }
    
    GetSprite().move(_velocity * elapsedTime, 0);
}

