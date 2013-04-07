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
    
    
    ofImage bgGame;
    ofImage boundaryMap;
    Player player;
//    Enemy enemy;
    vector<Enemy> enemies;
    
};
#endif /* defined(__codeLabObjects2__gameScreen__) */
