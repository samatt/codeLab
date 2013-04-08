#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "Player.h"
#include "introScreen.h"
#include "gameScreen.h"
#include "gameOverScreen.h"

class testApp : public ofBaseApp{
    
public:
    
    Screen* currentScreen;
    
    introScreen intro;
    gameScreen game;
    gameOverScreen   over;
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    
    
    
    
    
};
