//
//  gameOverScreen.h
//  codeLadMidterm
//
//  Created by Katie Adee on 4/8/13.
//
//

#ifndef __codeLadMidterm__gameOverScreen__
#define __codeLadMidterm__gameOverScreen__

#include <iostream>
#include "Screen.h"



class gameOverScreen : public Screen{
    
public:
    
    gameOverScreen();
    
    void setup();
    void update();
    void draw();
    void mousePressed();
    
    ofImage gameOver;
};

#endif /* defined(__codeLadMidterm__gameOverScreen__) */
