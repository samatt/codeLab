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
    
    bgGame.loadImage("stage/8BitITP-blank.jpg");
    furniture.resize(4);
    furniture[0].setup("furniture/round-table.png", 605, 436, 50, 50);
    furniture[1].setup("furniture/round-table.png", 605, 282, 50, 50);
    furniture[2].setup("furniture/round-table.png", 760, 278, 50, 50);
    furniture[3].setup("furniture/round-table.png", 771, 449, 50, 50);
    player = Player();
    for(int i=0; i<NUM_OF_ENEMIES;i++){
        Enemy e= Enemy(ofVec2f(ofRandom(500, 800), ofRandom(100,200)));
        enemies.push_back(e);
    }
}

void gameScreen::update(){
    player.update();
    
    for(unsigned int j = 0; j < furniture.size(); j++){
        furniture[j].update();
    }
    
    for(int i=0; i<NUM_OF_ENEMIES;i++){
        enemies[i].update();
    }
    
    for(int x=0;x<guns.size();x++){
        guns[x].update();
        if(!guns[x].checkEdges()){
            if(guns.size()>2 ){
                
                //debug
                cout<<guns.size()<<endl;
                
                //delete this vector value
                guns.erase(guns.begin()+(x-1));
            }
        }
        else{
            for(unsigned int i = 0; i < furniture.size(); i++){
                ofVec2f b = guns[x].bullet();
                furniture[i].explode(b.x, b.y);
                
            }
        }
    }
    
    
}

void gameScreen::draw(){
    
    bgGame.draw(0, 0,ofGetWidth(),ofGetHeight());
    player.display();
    
    for(int x=0;x<guns.size();x++){
        guns[x].display();
        
    }
    for(int i =0; i<NUM_OF_ENEMIES;i++){
        enemies[i].display();
    }
    
    for(unsigned int j = 0; j < furniture.size(); j++){
        furniture[j].draw();
    }
    
    for(unsigned int i = 0; i < furniture.size(); i++){
        furniture[i].drawExplosion();
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
        //shoot from the center of the player
        a.x = player.location.x+player.b.width/2;
        a.y = player.location.y+player.b.height/2;
        
        //shoot the latest bullet
        guns[guns.size()-1].shoot(a,player.currentDirection);
    }
}

void gameScreen::exit(){
    cout<<"exit game screen"<<endl;
}

