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
    for(int x=0;x<guns.size();x++){
        guns[x].update();
        if(!guns[x].checkEdges()){
            if(guns.size()>2 ){
            //delete this vector value
            guns.erase(guns.begin()+(x-1));        
            }
        }
    }

    for(int i=0; i<NUM_OF_ENEMIES;i++){
        enemies[i].update();
    }
}

void gameScreen::draw(){
    
    bgGame.draw(0, 0,ofGetWidth(),ofGetHeight());
    player.display();
    cout<<guns.size()<<endl;
    for(int x=0;x<guns.size();x++){
      guns[x].display();

    }
    
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
    if(key==OF_KEY_UP||key==OF_KEY_DOWN||key==OF_KEY_RIGHT||key==OF_KEY_LEFT){
        player.move(key);
    }
    else if(key==' '){
        gun g = gun();
        guns.push_back(g);
        ofVec2f a = ofVec2f();
        a.x = player.location.x+player.b.width/2;
        a.y = player.location.y+player.b.height/2;
        //shoot the latest bullet
        guns[guns.size()-1].shoot(a,player.currentDirection);
    }
}

void gameScreen::exit(){
    cout<<"exit game screen"<<endl;
}

