//
//  Player.h
//  codeLadMidterm
//
//  Created by Surya on 05/04/13.
//
//

#ifndef __codeLadMidterm__Player__
#define __codeLadMidterm__Player__

#include <iostream>
#include "ofMain.h"
#define DRAW_WIDTH 40
#define DRAW_HEIGHT 60
class Player{
public:
    Player();
    ~Player();
    Player(float x, float y);
    
    void move(int key);
    void draw();
    void display();
    Boolean checkEdges();

    ofImage* avatar;
    vector<ofImage> sprites;
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
private:
    ofImage boundaryMap;
};

#endif /* defined(__codeLadMidterm__Player__) */
