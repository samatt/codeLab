//
//  Attractor.h
//  codeLabGravityForces
//
//  Created by Surya on 23/02/13.
//
//

#ifndef codeLabGravityForces_Attractor_h
#define codeLabGravityForces_Attractor_h
#include "ofMain.h"
#include "mover.h"
class Attractor{
    public:
    Attractor();
    float mass;
    void display();
    ofVec2f attract(Mover m);
    ofVec2f location;
    float G;
};

#endif
