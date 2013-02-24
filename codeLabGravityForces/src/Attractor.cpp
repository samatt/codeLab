//
//  Attractor.cpp
//  codeLabGravityForces
//
//  Created by Surya on 23/02/13.
//
//

#include "Attractor.h"
#include "ofConstants.h"
Attractor:: Attractor(){
    location.set(ofGetWidth()/2,ofGetHeight()/2);
    mass = 50;
    G=0.01;
}

void Attractor::display(){
    ofSetColor(175,200);
    ofCircle(location.x, location.y, mass*2);    
}

ofVec2f Attractor::attract(Mover m){
    ofVec2f force;
    force = location- m.location;
    float distance = force.length();

    distance= ofClamp(distance, 2, 5);

    force = force.normalize();
        
    //This gives the unit vector in the direction of force.
    //cout<<distance<<endl;
    float strength = (G*mass*m.mass)/(distance*distance);
    force =force*strength;
    cout<<force<<endl;
    return force;
    
}