//
//  Enemy.cpp
//  codeLadMidterm
//
//  Created by Surya on 05/04/13.
//
//

#include "Enemy.h"



Enemy::Enemy(){
    boundaryMap.loadImage("stage/hit-map.jpg");
    location.set(80,80);
    velocity.set(0, 0);
    counter = 0;
    eventTime =0;
    
    b.x = location.x;
    b.y = location.y;
    b.width = ENEMY_WIDTH;
    b.height = ENEMY_HEIGHT;
    
    avatar = new ofImage("player/matt-front.png");
    sprites[0].loadImage("player/matt-front.png");
    sprites[1].loadImage("player/matt-back.png");
    sprites[2].loadImage("player/matt-left.png");
    sprites[3].loadImage("player/matt-right.png");
    avatar = &sprites[0];
}


Enemy::Enemy(ofVec2f l){
    boundaryMap.loadImage("stage/hit-map.jpg");
    location.set(l);
    counter = 0;
    eventTime =0;
    sprites.resize(4);
    for (int i = 0; i < 4; ++i) {
        sprites[i].allocate(80, 115, OF_IMAGE_COLOR);
    }
    b.x = location.x;
    b.y = location.y;
    b.width = ENEMY_WIDTH;
    b.height = ENEMY_HEIGHT;
    
    avatar = new ofImage("player/matt-front.png");
    sprites[0].loadImage("player/matt-front.png");
    sprites[1].loadImage("player/matt-back.png");
    sprites[2].loadImage("player/matt-left.png");
    sprites[3].loadImage("player/matt-right.png");
    avatar = &sprites[0];
    
}

void Enemy::update(){
    currentTime = ofGetElapsedTimeMillis();
    if (currentTime>eventTime) {
        eventTime =currentTime+1000;
        move();
        b.x = location.x;
        b.y = location.y;
    }
     
    

}

void Enemy::display(){
    
    ofPushStyle();
   // ofSetColor(128, 128, 50);
//    ofCircle(location.x,location.y, ENEMY_WIDTH,ENEMY_HEIGHT);
    avatar->draw(location.x, location.y, ENEMY_WIDTH,ENEMY_HEIGHT);
    ofPopStyle();
    
}

void Enemy::move(){
    
    int choice = ofRandom(3);
    if (checkEdges()) {
        switch (choice) {
            case 0:
                location.x+=20;
                avatar = &sprites[3];
                break;
            case 1:
                location.x-=20;
                                avatar = &sprites[2];
                break;
            case 2:
                location.y+=20;
                                avatar = &sprites[0];
                break;
            case 3:
                location.y-=20;
                                avatar = &sprites[1];
                break;
            default:
                break;
        }
        
    }
    else{
        switch (choice) {
            case 0:
                location.x-=20;
                break;
            case 1:
                location.x+=20;
                break;
            case 2:
                location.y-=20;
                break;
            case 3:
                location.y+=20;
                break;
            default:
                break;
        }
    }
    
}

bool Enemy::checkEdges(){
    for(int j=0;j<ENEMY_WIDTH;j++){
        for(int i=0;i<ENEMY_HEIGHT;i++){
            ofColor c = boundaryMap.getPixelsRef().getColor(location.x+i,location.y+j);
            
            if(c.b<254){
                //cout<<"here"<<endl;
                //cout<<c<<endl;
                return false;
                
            }
        }
    }
    return true;
}