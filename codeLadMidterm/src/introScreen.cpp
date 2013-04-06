//
//  introScreen.cpp
//  codeLabObjects2
//
//  Created by Surya on 01/04/13.
//
//

#include "introScreen.h"
#include "testApp.h"

introScreen::introScreen(): Screen(100,100,200,"Blue Intro"){
    
}

void introScreen::setup(){
    Screen::setup();
}

void introScreen::update(){
    
}

void introScreen::draw(){
    ofCircle(200, 200, 100);
}

void introScreen::mousePressed(){
    cout<<" introscreen mouse pressed";
    testApp* app = (testApp*)ofGetAppPtr();
    app->currentScreen = &app->game;
    app->currentScreen->setup();
}