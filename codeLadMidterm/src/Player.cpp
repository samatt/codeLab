//
//  Player.cpp
//  codeLadMidterm
//
//  Created by Surya on 05/04/13.
//
//

#include "Player.h"


Player::Player(){
    
    location.set(900, 100);
    sprites.resize(4);
    for (int i = 0; i < 4; ++i) {
        sprites[i].allocate(80, 115, OF_IMAGE_COLOR);
    }
    
    currentDirection.set(0,0);
    
    b.x = location.x;
    b.y = location.y;
    b.width = PLAYER_WIDTH;
    b.height = PLAYER_HEIGHT;
    
    
    avatar = new ofImage("player/katie-front.png");
    boundaryMap.loadImage("stage/hit-map.jpg");
    sprites[0].loadImage("player/katie-front.png");
    sprites[1].loadImage("player/katie-back.png");
    sprites[2].loadImage("player/katie-left.png");
    sprites[3].loadImage("player/katie-right.png");
    
    cout << avatar << " " << &sprites[0] << endl;
}

Player::Player( float x, float y){
    location.set(x,y);
    sprites.resize(4);
    
    sprites[0].loadImage("player/surya-front.png");
    sprites[1].loadImage("player/surya-back.png");
    sprites[2].loadImage("player/surya-left.png");
    sprites[3].loadImage("player/surya-right.png");
    avatar = &sprites[0];
    
}


void Player:: move(int key){
    //    if(checkEdges()){
    switch (key) {
        case OF_KEY_UP:
            if(!checkEdges()&&currentDirection.y ==-1){
                location.y+=10;
            }
            else{
                location.y-=10;
                avatar = &sprites[1];
                currentDirection.set(0,-1);
            }
            
            break;
        case OF_KEY_DOWN:
            if(!checkEdges()&&currentDirection.y ==1){
                location.y-=10;
            }
            else{
                location.y+=10;
                avatar = &sprites[0];
                currentDirection.set(0,1);
            }
            break;
        case OF_KEY_LEFT:
            if(!checkEdges()&&currentDirection.x ==-1){
                location.x+=10;
            }
            else{
                location.x-=10;
                avatar = &sprites[2];
                currentDirection.set(-1,0);
            }
            break;
        case OF_KEY_RIGHT:
            if(!checkEdges()&&currentDirection.x ==1){
                location.x -= 10;
            }else{
                location.x+=10;
                avatar = &sprites[3];
                currentDirection.set(1,0);
            }
            
            break;
        default:
            cout<<"im in move"<<endl;
            break;
    }
    
}

void Player::update(){
    boundaryMap.resize(ofGetWidth(), ofGetHeight());
    b.x = location.x;
    b.y = location.y;
}
void Player::display(){
    
    avatar->draw(location.x, location.y,PLAYER_WIDTH,PLAYER_HEIGHT);
    
}

bool Player::checkCollision(vector<ParticleSystem> p) {
    
    //for(int i =0; i<p.size();i++){
    if (!((b.x + b.width) >= (p[3].centerX))) {
        
        return 0;
    }
    
    if (!(b.x <= (p[3].centerX + p[3].width))) {

        return 0;
    }
    
    if (!((b.y - b.height) <= p[3].centerY)) {
        
        return 0;
    }
    
    if (!(b.y >= (p[3].centerY - p[3].height))) {
        return 0;
        
    }
    
    //}
    
    return 1;

}



bool Player::checkEdges(){
    //
    for(int i=0;i<PLAYER_HEIGHT+5;i++){
        for(int j=0;j<PLAYER_WIDTH+5;j++){
            
            
            ofColor c = boundaryMap.getPixelsRef().getColor(location.x+j,location.y+i);
            
            if(c.b<254){
                //    cout<<"here"<<endl;
                // cout<<c<<endl;
                return false;
                
            }
        }
    }
    return true;
    
}

Player::~Player() {
    
    //   delete avatar;
}
