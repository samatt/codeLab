//
//  gameScreen.cpp
//  codeLabObjects2
//
//  Created by Surya on 01/04/13.
//
//

#include "gameScreen.h"
#include  "testApp.h"

gameScreen::gameScreen():Screen(255,0,0,"gameScreen"){
    
}

void gameScreen::setup(){
    
    bgGame.loadImage("stage/8BitITP.jpeg");
    player = Player();
    enemy = Enemy();
}

void gameScreen::update(){
    enemy.update();
}

void gameScreen::draw(){
    bgGame.draw(0, 0,ofGetWidth(),ofGetHeight());
    player.display();
    enemy.display();

}

void gameScreen::mousePressed(){
    cout<<"game screen mouse pressed";
    testApp* app = (testApp*)ofGetAppPtr();
    app->currentScreen = &app->intro;
    app->currentScreen->setup();
    
}

void gameScreen::keyPressed(int key){
    player.move(key);
}

void gameScreen::exit(){
    cout<<"exit game screen"<<endl;
    player.~Player();
}

