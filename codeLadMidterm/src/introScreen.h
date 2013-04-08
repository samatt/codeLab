//
//  introScreen.h
//  codeLabObjects2
//
//  Created by Surya on 01/04/13.
//
//

#ifndef __codeLabObjects2__introScreen__
#define __codeLabObjects2__introScreen__

#include <iostream>
#include "Screen.h"

class introScreen : public Screen{

public:
    introScreen();
    
    void setup();
    void update();
    void draw();
    void mousePressed();
    
    ofImage start;
    ofImage  kate;
    ofImage sur;
    int player;
    float mx;
  
};
#endif /* defined(__codeLabObjects2__introScreen__) */
