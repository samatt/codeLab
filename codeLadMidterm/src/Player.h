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
#include "particle.h"
#include "BoundingBox.h"
#include "ofxSvg.h"

#define PLAYER_WIDTH 40
#define PLAYER_HEIGHT 60
class Player{
public:
    Player();
    ~Player();
    Player(int p);
    
    void move(int key);
    void update();
    void draw();
    void display();
    bool insideEdges();
    void alternateMove(int key);
    int isCollided(vector <ParticleSystem> p);
    bool isFood(boundingBox k);
    
    ofImage* avatar;
    ofVec2f location;
    ofVec2f currentDirection;
    ofVec2f velocity;
    ofVec2f acceleration;
   // boundingBox k;
    boundingBox b;
private:
    ofImage boundaryMap;
    ofxSVG bMapSvg;
    vector<ofImage> sprites;
};

#endif /* defined(__codeLadMidterm__Player__) */
