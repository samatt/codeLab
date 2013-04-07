//
//  gameScreen.h
//  codeLabObjects2
//
//  Created by Surya on 01/04/13.
//
//

#ifndef __codeLabObjects2__gameScreen__
#define __codeLabObjects2__gameScreen__

#include <iostream>
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "gun.h"
#include "particle.h"
#define NUM_OF_ENEMIES 4

class gameScreen:public Screen{
    
public:
    gameScreen();
    
    void setup();
    void update();
    void draw();
    void exit();
    
    void mousePressed();
    void keyPressed(int key);
    
    vector<gun> guns;
    ofImage bgGame;
    ofImage boundaryMap;
    Player player;
    vector<Enemy> enemies;
    vector<ParticleSystem> furniture;
};
#endif /* defined(__codeLabObjects2__gameScreen__) */
