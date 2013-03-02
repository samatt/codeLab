// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// A class for a draggable attractive body in our world

#include "Attractor.h"

Attractor::Attractor() {
    location.set(ofGetWidth()/2,ofGetHeight()/2);
    mass = 20;
    G = 0.4;
    dragOffset.set(0.0,0.0);
}

ofVec2f Attractor::attract(Mover m) {
    ofVec2f force = location - m.location;   // Calculate direction of force
    float d = force.length();                              // Distance between objects
    d = ofClamp(d,5.0,25.0);                        // Limiting the distance to eliminate "extreme" results for very close or very far objects
    force.normalize();                                  // Normalize vector (distance doesn't matter here, we just want this vector for direction)
    float strength = (G * mass * m.mass) / (d * d);      // Calculate gravitional force magnitude
    force *= strength;                                  // Get force vector --> magnitude * direction
    return force;
}

// Method to display
void Attractor::display() {

    if (dragging) ofSetColor (50);
    else if (rollover) ofSetColor(100);
    else ofSetColor(175,200);
	
	ofFill();
	ofEnableAlphaBlending();
    ofSetColor(175,200);
    ofCircle(location.x, location.y, mass);
	ofDisableAlphaBlending();
    
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(2);
    ofCircle(location.x, location.y, mass);
}

// The methods below are for mouse interaction
void Attractor::clicked(int mx, int my) {
    float d = ofDist(mx,my,location.x,location.y);
    if (d < mass) {
		dragging = true;
		dragOffset.x = location.x-mx;
		dragOffset.y = location.y-my;
    }
}

void Attractor::hover(int mx, int my) {
    float d = ofDist(mx,my,location.x,location.y);
    if (d < mass) {
		rollover = true;
    }
    else {
		rollover = false;
    }
}

void Attractor::stopDragging() {
    dragging = false;
}



void Attractor::drag() {
    if (dragging) {
		location.x = ofGetMouseX() + dragOffset.x;
		location.y = ofGetMouseY() + dragOffset.y;
    }
}
