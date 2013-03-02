// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// A class for a draggable attractive body in our world

#pragma once
#include "ofMain.h"
#include "Mover.h"

class Attractor {
public:
	
	Attractor();
	ofVec2f attract(Mover m);
	void display();
	
	// The methods below are for mouse interaction
	void clicked(int mx, int my);
	void hover(int mx, int my);
	void stopDragging();
	void drag();
	
	float mass;    // Mass, tied to size
	float G;       // Gravitational Constant
	ofVec2f location;   // Location
	Boolean dragging = false; // Is the object being dragged?
	Boolean rollover = false; // Is the mouse over the ellipse?
	ofVec2f dragOffset;  // holds the offset for when object is clicked on
};

