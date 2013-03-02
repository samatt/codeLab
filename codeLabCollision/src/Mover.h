//
//  Mover.h
//  NOC_1_10_motion101_OF
//
//
//

#pragma once
#include <iostream>
#include "ofMain.h"


class Mover {
    public:
    
    Mover();
	void init(float m, float x , float y);
    void update();
    void display();
    ofVec2f attract(Mover m);
    void applyForce(ofVec2f force); 
    Boolean checkEdges();
    // The Mover tracks location, velocity, and acceleration 
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofColor color;
    float mass;
	float checkCollison(vector<Mover>& m);
	float g;
    
};