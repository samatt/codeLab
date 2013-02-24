//
//  mover.h
//  codeLabGravityForces
//
//  Created by Surya on 23/02/13.
//
//

#ifndef codeLabGravityForces_mover_h
#define codeLabGravityForces_mover_h
#include "ofMain.h"

class Mover{
public:
    Mover();
    Mover(float m, float x, float y,ofColor _c);
    void applyForce(ofVec2f force);
    void update();
    void display();
    void checkEdges();
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofColor color;
    
    float mass;
    
    
};

#endif
