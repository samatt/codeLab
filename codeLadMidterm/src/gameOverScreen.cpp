//
//  gameOverScreen.cpp
//  codeLadMidterm
//
//  Created by Katie Adee on 4/8/13.
//
//

#include "gameOverScreen.h"
#include "testApp.h"

gameOverScreen::gameOverScreen(): Screen(100,100,200,"game over"){
    
}

void gameOverScreen::setup(){
    Screen::setup();
    gameOver.loadImage("stage/game-over.jpg");
}

void gameOverScreen::update(){
    
}

void gameOverScreen::draw(){
    gameOver.draw(0, 0,ofGetWidth(),ofGetHeight());
}

void gameOverScreen::mousePressed(){
    cout<<" heading back to start screen";
    testApp* app = (testApp*)ofGetAppPtr();
    app->currentScreen = &app->intro;
    app->currentScreen->setup();
}