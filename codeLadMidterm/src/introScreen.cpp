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
    player =0;
}

void introScreen::setup(){
    Screen::setup();
    start.loadImage("stage/start-screen.jpg");
    kate.loadImage("player/katie-front.png");
    sur.loadImage("player/surya-front.png");
}

void introScreen::update(){
    
}

void introScreen::draw(){
    start.draw(0, 0,ofGetWidth(),ofGetHeight());
    kate.draw(ofGetWidth()/2-100,200);
    sur.draw(ofGetWidth()/2+100,200);
}

void introScreen::mousePressed(){
    if (ofGetMouseX() < ofGetWidth()/2){
        player = 0;
    }
    else{
        player=1;
    }
    
    cout<<" introscreen mouse pressed";
    testApp* app = (testApp*)ofGetAppPtr();
    app->currentScreen = &app->game;
    app->currentScreen->setup();

    app->currentScreen->loadPlayer(player);

    
}