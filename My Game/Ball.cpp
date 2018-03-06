//
//  Ball.cpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#include "Ball.hpp"

Ball::Ball():
    _velocity(600.0f),
    _elapsedTimeSinceStart(0.0f)
{
    Load(resourcePath() + "huaji copy.png");
    
    srand(time(NULL));
    _angle = rand() % 360 + 1;
}

Ball::~Ball()
{
}

void Ball::Update(float elapsedTime)
{
    _elapsedTimeSinceStart += elapsedTime;
    
    if(_elapsedTimeSinceStart < 1.0f)
        return;
    
    float moveByX = _velocity * elapsedTime * LinearVelocityX(_angle);
    float moveByY = _velocity * elapsedTime * LinearVelocityY(_angle);
    
    ScoreBoard* scoreboard = dynamic_cast<ScoreBoard*>(Game::GetGameObjectManager().Get("ScoreBoard"));
    
    Paddle* player = dynamic_cast<Paddle*>(Game::GetGameObjectManager().Get("Paddle"));
    sf::Rect<float> p1BoundingRect = player->GetBoundingRect();
    
    sf::Rect<float> BallBoundingRect = GetBoundingRect();
    
    sf::Event event = Game::GetInput();
    
    if(p1BoundingRect.intersects(BallBoundingRect))
    {
        sound->Play();
        
        //带特效，铲球
        if(_velocity > 1000.0f)
        {
            this->GetSprite().setColor(sf::Color::Green);
            //this->SetPosition(this->GetBoundingRect().left, player->GetBoundingRect().top - this->GetWidth()/2 - 1);
        }
        
        //发大招！铲球
        if(event.key.code == sf::Keyboard::Up)
        {
            this->GetSprite().setColor(sf::Color::Green);
            _velocity += 1000.0f;
        }
        
        scoreboard->PlayerScoreUp();
        //GetSprite().setColor(sf::Color::Blue);
        _angle = 360.0f - (_angle - 180.0f);
        moveByY = -moveByY;
        
        float playerVelocity1 = player->GetVelocity();
        //骚操作，削球
        if(playerVelocity1 < 0)
        {
            _angle -= 20.0f;
        }
        else if(playerVelocity1 > 0)
        {
            _angle += 20.0f;
        }
        //撞击后加速，提高难度
        _velocity += 40.0f;
    }
    

    
    AI* AIplayer = dynamic_cast<AI*>(Game::GetGameObjectManager().Get("AIPaddle"));
    sf::FloatRect p2BoundingRect = AIplayer->GetBoundingRect();
    
    
    if(p2BoundingRect.intersects(BallBoundingRect))
    {
        sound->Play();
        
        //带特效，铲球
        if(_velocity > 1000.0f)
        {
            this->GetSprite().setColor(sf::Color::Red);
            //this->SetPosition(this->GetBoundingRect().left, AIplayer->GetBoundingRect().top + AIplayer->GetHeight()/2 + 1);
        }
        
        scoreboard->AIScoreUp();
        _angle =  360.0f - (_angle - 180.0f);
        if(_angle > 360.0f)
            _angle -= 360.0f;
        
        moveByY = -moveByY;
        
        float playerVelocity2 = AIplayer->GetVelocity();
        
        //骚操作，削球
        if(playerVelocity2 < 0)
        {
            _angle -= 20.0f;
        }
        else if(playerVelocity2 > 0)
        {
            _angle += 20.0f;
        }
        //撞击后加速，提高难度
        _velocity += 40.0f;
    }
    
    //球撞击左右，反弹
    if(GetPosition().x + moveByX <= 0 + GetWidth()/2
       || GetPosition().x + GetHeight()/2 + moveByX >= WINDOW_WIDTH)
    {
        _angle = 360.0f - _angle;
        if(_angle > 260.0f && _angle < 280.0f)
            _angle += 20.0f;
        if(_angle > 80.0f && _angle < 100.0f)
            _angle += 20.0f;
        moveByX = -moveByX;
    }
    
    //球飞出下边界，AI得分
    if(GetPosition().y >= WINDOW_HIGHT)
    {
        this->GetSprite().setPosition(WINDOW_WIDTH/2, WINDOW_HIGHT-100);
        _angle = rand() % 90 - 45;
        _velocity = 600;
        _elapsedTimeSinceStart = 0.0f;
        
        scoreboard->AIScoreUp100();
        
        this->GetSprite().setColor(sf::Color::White);
    }
    
    //球飞出上边界，玩家得分，AI加速
    if(GetPosition().y <= 0)
    {
        this->GetSprite().setPosition(WINDOW_WIDTH/2, WINDOW_HIGHT-100);
        _angle = rand() % 90 - 45;
        _velocity = 600;
        _elapsedTimeSinceStart = 0.0f;
        
        AIplayer->LevelUp();
        scoreboard->PlayerScoreUp100();
        
        this->GetSprite().setColor(sf::Color::White);
    }

    GetSprite().move(moveByX,moveByY);
    
}

float Ball::LinearVelocityX(float angle)
{
    angle -= 90;
    if (angle < 0)
        angle = 360 + angle;
    return (float)std::cos( angle * ( 3.1415926 / 180.0f ));
}

float Ball::LinearVelocityY(float angle)
{
    angle -= 90;
    if (angle < 0)
        angle = 360 + angle;
    return (float)std::sin( angle * ( 3.1415926 / 180.0f ));
}



