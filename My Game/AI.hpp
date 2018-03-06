//
//  AI.hpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Game.hpp"

class AI : public GameObject
{
public:
    AI();
    ~AI();
    
    void Update(float elapsedTime);
    void Draw(sf::RenderWindow& rw);
    
    float GetVelocity() const;
    unsigned GetLevel() const;
    void LevelUp();
    
    void MaxVelocityUp(float acceleration);
    void MaxAccelerationUp(float acceleration);
    
private:
    float _velocity;
    float _maxVelocity;
    float _acceleration;
    unsigned _level;
};

#endif /* AI_hpp */

