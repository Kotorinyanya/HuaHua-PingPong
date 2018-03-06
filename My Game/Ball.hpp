//
//  Ball.hpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Game.hpp"
#include "Sound.hpp"
#include <cmath>
#include <ctime>

class Ball : public GameObject
{
public:
    Ball();
    ~Ball();
    void Update(float elapsedTime);
    
private:
    float _velocity;
    float _angle;
    float _elapsedTimeSinceStart;
    
    float LinearVelocityX(float angle);
    float LinearVelocityY(float angle);
    
    HitSound* sound = new HitSound();
};

#endif /* Ball_hpp */
