//
//  Sound.cpp
//  My Game
//
//  Created by SRT_KID on 1/4/18.
//  Copyright © 2018 SRT_KID. All rights reserved.
//

#include "Sound.hpp"

HitSound::HitSound()
{
    Load(resourcePath() + "ping-pong-ball-hit-single_zJrmw2N_.ogg");
}

HitSound::~HitSound()
{
}

void HitSound::Load(std::string filename)
{
    _buffer.loadFromFile(filename);
    _sound.setBuffer(_buffer);
}

void HitSound::Play()
{
    _sound.play();
}
