//
//  GameObject.cpp
//  My Game
//
//  Created by SRT_KID on 11/14/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Load(std::string filename)
{
    _image.loadFromFile(filename);
    _filename = filename;
    _sprite.setTexture(_image);
}

void GameObject::Draw(sf::RenderWindow & renderWindow)
{
    renderWindow.draw(_sprite);
}

void GameObject::Update(float elapsedTime)
{
}

void GameObject::SetPosition(float x, float y)
{
    _sprite.setPosition(x, y);
}

sf::Vector2f GameObject::GetPosition() const
{
    return _sprite.getPosition();
}

sf::Sprite& GameObject::GetSprite()
{
    return _sprite;
}

float GameObject::GetWidth() const
{
    return _sprite.getLocalBounds().width;
}

float GameObject::GetHeight() const
{
    return _sprite.getLocalBounds().height;
}

sf::Rect<float> GameObject::GetBoundingRect() const
{
    return _sprite.getGlobalBounds();
}


