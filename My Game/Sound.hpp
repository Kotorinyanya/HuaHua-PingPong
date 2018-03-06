//
//  Sound.hpp
//  My Game
//
//  Created by SRT_KID on 1/4/18.
//  Copyright © 2018 SRT_KID. All rights reserved.
//

#ifndef Sound_hpp
#define Sound_hpp

#include <stdio.h>
#include <string>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"

class HitSound
{
public:
    HitSound();
    ~HitSound();
    
    void Load(std::string filename);
    void Play();
private:
    sf::Sound _sound;
    sf::SoundBuffer _buffer;
};

#endif /* Sound_hpp */
