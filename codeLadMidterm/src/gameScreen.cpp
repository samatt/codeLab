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
    for(int i=0; i<NUM_OF_ENEMIES;i++){
        
        Enemy e= Enemy(ofVec2f(ofRandom(500, 800), ofRandom(100,200)));
        enemies.push_back(e);
    }
}

void gameScreen::update(){
    player.update();
    for(int i=0; i<NUM_OF_ENEMIES;i++){
        enemies[i].update();
    }
}

void gameScreen::draw(){
    
    bgGame.draw(0, 0,ofGetWidth(),ofGetHeight());
    player.display();
    for(int i =0; i<NUM_OF_ENEMIES;i++){
        enemies[i].display();
    }
    
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
    //player.~Player();
}

