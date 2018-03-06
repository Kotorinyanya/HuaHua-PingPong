//
//  Paddle.hpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#ifndef Paddle_hpp
#define Paddle_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Game.hpp"


class Paddle : public GameObject
{
public:
    Paddle();
    ~Paddle();
    
    void Update(float elapsedTime);
    void Draw(sf::RenderWindow & rw);
    
    float GetVelocity() const;
    
private:
    float _velocity;
    float _maxVelocity;
    
};

#endif /* Paddle_hpp */

