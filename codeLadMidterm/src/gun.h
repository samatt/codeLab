//
//  gun.h
//  Explode
//
//  Created by Katie Adee on 4/5/13.
//
//

#ifndef __Explode__gun__
#define __Explode__gun__

#include <iostream>
#include "ofMain.h"
class gun{
public:
    ofPoint loc;
    ofPoint ploc;
    ofVec2f vel;
    ofVec2f acc;
    
    gun();
    gun(float x, float y);
    
    void update();
    void display();
    ofPoint shoot();
    ofPoint bullet();
    ofPoint reload();
    
};
#endif /* defined(__Explode__gun__) */
