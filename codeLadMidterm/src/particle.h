//
//  particle.h
//  Explode
//
//  Created by Katie Adee on 4/5/13.
//
//

#pragma once
#include "ofMain.h"
#include "Mover.h"

class ParticleSystem{
    
    
private:
    

    ofImage png;
    vector<Mover> movers;
    
    
    
public:
    
    void setup(string name, int cx, int cy, int w, int h);
    void update();
    void draw();
    void drawExplosion();
    bool isExploded();
    void drawTarget(int mx, int my);
    bool explode(int mx, int my);

    
    int centerX, centerY;
    int width, height;
    bool hit;
    bool prevHit;

    
};