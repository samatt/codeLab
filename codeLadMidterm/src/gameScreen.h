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
    Enemy enemy;
    
    
};
#endif /* defined(__codeLabObjects2__gameScreen__) */
