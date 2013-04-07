//
//  Enemy.h
//  codeLadMidterm
//
//  Created by Surya on 05/04/13.
//
//

#ifndef __codeLadMidterm__Enemy__
#define __codeLadMidterm__Enemy__

#include <iostream>
#include "ofMain.h"
#include "BoundingBox.h"
#define ENEMY_WIDTH 10
#define ENEMY_HEIGHT 10
class Enemy{
    
public:
    
    Enemy();
    Enemy(ofVec2f l);
    void update();
    void display();
    void move();
    bool checkEdges();

    ofImage avtar;
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    boundingBox b;
private:
    ofImage boundaryMap;
    int counter;
    unsigned long currentTime;
    unsigned long eventTime;
    
    
};
#endif /* defined(__codeLadMidterm__Enemy__) */
