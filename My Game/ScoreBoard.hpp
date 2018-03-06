//
//  ScoreBoard.hpp
//  My Game
//
//  Created by SRT_KID on 11/15/17.
//  Copyright © 2017 SRT_KID. All rights reserved.
//

#ifndef ScoreBoard_hpp
#define ScoreBoard_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "GameObjectManager.hpp"
#include <sstream>

class ScoreBoard : public GameObject
{
public:
    ScoreBoard();
    ~ScoreBoard();
    
    void Load(std::string filename);
    void Update(float elapsedTime);
    void Draw(sf::RenderWindow & rw);
    
    void PlayerScoreUp();
    void AIScoreUp();
    
    void PlayerScoreUp100();
    void AIScoreUp100();
    
    void LevelUp();
    
private:
    int _PlayerScore;
    int _AIScore;
    unsigned _level;
    sf::Font _font;
    sf::Text _text;
};

#endif /* ScoreBoard_hpp */

