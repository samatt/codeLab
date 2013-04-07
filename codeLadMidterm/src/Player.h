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
#include "Enemy.h"
#include "BoundingBox.h"
#define DRAW_WIDTH 40
#define DRAW_HEIGHT 60
class Player{
public:
    Player();
    ~Player();
    Player(float x, float y);
    
    void move(int key);
    void update();
    void draw();
    void display();
    Boolean checkEdges();
    Boolean checkCollision(vector<Enemy> e);
    
    ofImage* avatar;
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    boundingBox b;
private:
    ofImage boundaryMap;
    vector<ofImage> sprites;
};

#endif /* defined(__codeLadMidterm__Player__) */
