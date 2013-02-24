#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float xPos, yPos, rPos;
    float rot;
    float xCircle,yCircle,rCircle;
    float xRand,yRand, rRand;
    int alpha1,alpha2,alpha3;
    bool background;
    bool rainbow;
    ofFloatColor pos,circle,rand;
};
