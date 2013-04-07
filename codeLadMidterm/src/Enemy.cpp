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
    
}


Enemy::Enemy(ofVec2f l){
    boundaryMap.loadImage("stage/hit-map.jpg");
    location.set(l);
    counter = 0;
    eventTime =0;

    
}

void Enemy::update(){
    currentTime = ofGetElapsedTimeMillis();
    if (currentTime>eventTime) {
        eventTime =currentTime+1000;
        cout<<eventTime<<endl;
        move();
        b.x = location.x;
        b.y = location.y;
    }
     
    

}

void Enemy::display(){
    
    ofPushStyle();
    ofSetColor(128, 128, 50);
    ofCircle(location.x,location.y, ENEMY_WIDTH,ENEMY_HEIGHT);
    ofPopStyle();
    
}

void Enemy::move(){
    
    int choice = ofRandom(3);
    if (checkEdges()) {
        switch (choice) {
            case 0:
                location.x+=20;
                break;
            case 1:
                location.x-=20;
                break;
            case 2:
                location.y+=20;
                break;
            case 3:
                location.y-=20;
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