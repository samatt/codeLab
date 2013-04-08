//
//  Screen.h
//  codeLabObjects2
//
//  Created by Surya on 01/04/13.
//
//

#ifndef __codeLabObjects2__Screen__
#define __codeLabObjects2__Screen__

#include <iostream>
#include "ofMain.h"

class Screen{

public:
    Screen();
    Screen(int r, int g, int b, string _name);
    virtual void setup();
    virtual void update();
    virtual void draw();
    virtual void mousePressed();
    virtual void keyPressed(int key);
    virtual void exit();
    virtual void loadPlayer(int p);
    ofColor bgColor;
    string name;

};
#endif /* defined(__codeLabObjects2__Screen__) */
