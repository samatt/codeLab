//// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com
//  Mover.cpp
//  NOC_1_10_motion101_OF
//
//
//

#include "Mover.h"

Mover::Mover() {
}

void Mover::init(float m, float x , float y){
	mass = m;
    location.set(x,y);
    velocity.set(0, 0);
    acceleration.set(0, 0);
    color.set(0, 100);
	g = 0.6;
}

void Mover::applyForce(ofVec2f force) {
    ofVec2f f;
    f.set(force / mass);
    acceleration +=f;
}

void Mover::update() {
	
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
	
}

void Mover::display(){
    ofFill();
    ofSetColor(color);
	ofEnableAlphaBlending();
    ofCircle(location.x, location.y, mass*10);
	ofDisableAlphaBlending();
    
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(1);
    ofCircle(location.x, location.y, mass*10);
}

float Mover::checkCollison(vector<Mover>& m){

    for(int i= 0; i< m.size();i++){
        float dist = ofDist(location.x,location.y,m[i].location.x,m[i].location.y);

        cout<<dist<<","<<10*(mass+m[i].mass)<<endl;
        if(dist<10*(mass+m[i].mass)){
            if(dist != 0){
                m[i].color.set(50, 50, 128);

                cout<<"here"<<endl;
            }
            
        }
        
    }
}

ofVec2f Mover::attract(Mover m) {
    ofVec2f force;
	force.set(location - m.location);             // Calculate direction of force
    float distance = force.length();                                 // Distance between objects
    distance = ofClamp(distance, 5.0, 25.0);                             // Limiting the distance to eliminate "extreme" results for very close or very far objects
    force.normalize();                                            // Normalize vector (distance doesn't matter here, we just want this vector for direction
	
    float strength = (g * mass * m.mass) / (distance * distance); // Calculate gravitional force magnitude
	force *= strength;                                         // Get force vector --> magnitude * direction
    return force;

}

Boolean Mover::checkEdges(){
    Boolean outOfBounds = false;
    if(location.x>ofGetWidth()){
        outOfBounds=true;
    }
    else if(location.x<0){
        outOfBounds=true;
        
    }
    
    if(location.y>ofGetHeight()){
        outOfBounds=true;
    }
    else if(location.y<0){
        outOfBounds = true;
    }
    
    return outOfBounds;
}