#include "Mover.h"


Mover::Mover(const ofVec2f & position, ofColor cor){
    initialLoc = position;
    location = position;
    velocity.set(0, 0);
    acceleration.set(0, 0);
    
    color = cor;
    isBack = false;
    mass = 2;
    maxForce = 2;
    maxSpeed = 2;
    
}

void Mover::applyForce(const ofVec2f & force){
    ofVec2f f(force/mass);
    acceleration += f;
}

void Mover::goBack( ){
    
    ofVec2f forceBack =  initialLoc - location;
    float l = forceBack.length();
    forceBack.normalize();
    
    if(l < 15) {
        float m = ofMap(l, 0, 25, 0, maxSpeed);
        forceBack *= m;
    }
    else{
        forceBack*= maxSpeed;
    }
    
    ofVec2f steer = forceBack - velocity;
    steer.limit(maxForce);
    applyForce(steer);
    
    
}

void Mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

void Mover::draw(){
    ofPushStyle();
    ofSetColor(color);
    ofFill();
    ofRect(location, mass,mass);
    ofPopStyle();
}



void Mover::setMass(float m){
    mass = m;
}







void Mover::airResistance(){
    
    float speed = velocity.length();
    float dragMagnitude = 0.005 * speed * speed;
    
    ofVec2f drag;
    drag.set(velocity);
    drag *= -1;
    drag.normalize();
    
    
    drag *= dragMagnitude;
    applyForce(drag);
    
}