//
//  mover.cpp
//  codeLabGravityForces
//
//  Created by Surya on 23/02/13.
//
//

#include "mover.h"

Mover::Mover(){
    mass = 5;
   location.set(400, 400);
    velocity.set(1,0);
    acceleration.set(0,0);
    color.set(128,100);
    G =0.01;
    
}

Mover::Mover(float m, float x, float y, ofColor _c){
    mass = m;
    location.set(x,y);
    velocity.set(0.1,0);
    acceleration.set(0,0);
    color.set(_c);
}

void Mover:: applyForce(ofVec2f force){
    ofVec2f f;
    f.set(force);
    f.operator/=(mass);
    acceleration+=f;

}

void Mover:: update(){
    velocity+=acceleration;
    location+=velocity;
    acceleration.operator*(0);
}

void Mover::display(){
    ofSetColor(color);
    ofCircle(location.x, location.y, mass*4);
}

ofVec2f Mover::attract(Mover m){
    ofVec2f force;
    force = location- m.location;
    float distance = force.length();
    
    distance= ofClamp(distance, 2, 25);
    
    force = force.normalize();
    
    //This gives the unit vector in the direction of force.
    //cout<<distance<<endl;
    float strength = (G*mass*m.mass)/(distance*distance);
    force =force*strength;
    cout<<force<<endl;
    return force;
    
}

void Mover::checkEdges(){
    
    if(location.x>ofGetWidth()){
        location.x = ofGetWidth();
        velocity.x *= -1;
    }
    else if(location.x<0){
        velocity.x *= -1;
        location.x = 0;
        
    }
    
    if(location.y>ofGetHeight()){
        velocity.y *= -1;
        location.y = ofGetHeight();
    }
    else if(location.y<0){
        velocity.y *= -1;
        location.y = 0;
    }
}