//
//  GameObject.hpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//
#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "stdafx.h"

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();
    
    virtual void Load(std::string filename);
    virtual void Draw(sf::RenderWindow & window);
    virtual void Update(float elapsedTime);
    
    virtual void SetPosition(float x, float y);
    virtual sf::Vector2f GetPosition() const;
    
    virtual float GetWidth() const;
    virtual float GetHeight() const;
    virtual sf::Rect<float> GetBoundingRect() const;
    
protected:
    sf::Sprite& GetSprite();
    
private:
    sf::Sprite  _sprite;
    sf::Texture _image;
    std::string _filename;
    
};


#endif /* GameObject_hpp */

