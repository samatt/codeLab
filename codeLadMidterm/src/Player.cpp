//
//  Player.cpp
//  codeLadMidterm
//
//  Created by Surya on 05/04/13.
//
//

#include "Player.h"


Player::Player(){
    
    location.set(524, 537);
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
    //boundaryMap.load("stage/8BitITP.svg")
    //bMapSvg.load("stage/8BitITP.svg");
    boundaryMap.loadImage("stage/hit-map.jpg");
    sprites[0].loadImage("player/katie-front.png");
    sprites[1].loadImage("player/katie-back.png");
    sprites[2].loadImage("player/katie-left.png");
    sprites[3].loadImage("player/katie-right.png");
    
//    cout << avatar << " " << &sprites[0] << endl;
}

Player::Player( int p){
    if(p==0){
        location.set(610, 620);
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
    }
    else{
        location.set(610, 620);
        sprites.resize(4);
        for (int i = 0; i < 4; ++i) {
            sprites[i].allocate(80, 115, OF_IMAGE_COLOR);
        }
        
        currentDirection.set(0,0);
        
        b.x = location.x;
        b.y = location.y;
        b.width = PLAYER_WIDTH;
        b.height = PLAYER_HEIGHT;
        
        
        avatar = new ofImage("player/surya-front.png");
        boundaryMap.loadImage("stage/hit-map.jpg");
        sprites[0].loadImage("player/surya-front.png");
        sprites[1].loadImage("player/surya-back.png");
        sprites[2].loadImage("player/surya-left.png");
        sprites[3].loadImage("player/surya-right.png");
    }
}

void Player:: alternateMove(int key){
    //    if(checkEdges()){
    switch (key) {
        case OF_KEY_UP:
            if(currentDirection.y==-1){
                    location.y+=10;
            }
                
                    break;

        case OF_KEY_DOWN:
            if(currentDirection.y==1){
                location.y-=10;
            }
                    break;
            
        case OF_KEY_LEFT:
            if(currentDirection.x==-1){
                location.x+=10;
                break;
            }

        case OF_KEY_RIGHT:
            if(currentDirection.x==1){
                location.x -= 10;
                break;
            }

        default:
            cout<<"im in move"<<endl;
            break;
    }

}
void Player:: move(int key){
    //    if(checkEdges()){
    switch (key) {
        case OF_KEY_UP:
            if(!insideEdges()&&currentDirection.y ==-1){
                location.y+=10;
            }
            else{
                location.y-=10;
                avatar = &sprites[1];
                currentDirection.set(0,-1);
            }
            
            break;
        case OF_KEY_DOWN:
            if(!insideEdges()&&currentDirection.y ==1){
                location.y-=10;
            }
            else{
                location.y+=10;
                avatar = &sprites[0];
                currentDirection.set(0,1);
            }
            break;
        case OF_KEY_LEFT:
            if(!insideEdges()&&currentDirection.x ==-1){
                location.x+=10;
            }
            else{
                location.x-=10;
                avatar = &sprites[2];
                currentDirection.set(-1,0);
            }
            break;
        case OF_KEY_RIGHT:
            if(!insideEdges()&&currentDirection.x ==1){
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
bool Player::isFood(boundingBox k) {
    int collision = 0;

        if(!((b.x + b.width) >= (k.x))) {
            
            return 0;
        }
        
        if(!(b.x <= (k.x + k.width))) {
            
            return 0;
            // collision++;
        }
        
        if (!((b.y - b.height) <= k.y)) {
            return 0;
            //collision++;
        }
        
        if (!(b.y >= (k.y - k.height))) {
           return 0;
            // collision++;
            
        }

    return 1;
    
}
int Player::isCollided(vector <ParticleSystem> p) {
    int collision = 0;
    for(int i =0; i<p.size();i++){
        if (!((b.x + b.width) >= (p[i].centerX))) {
           /// collision++;
            //return 0;
        }
        
        else if (!(b.x <= (p[i].centerX + p[i].width))) {
            
           // collision++;
        }
        
        else if (!((b.y - b.height) <= p[i].centerY)) {
            
            //collision++;
        }
        
        else if (!(b.y >= (p[i].centerY - p[i].height))) {
           // collision++;
            
        }
        else{
            collision++;
        }
        
    }
   // cout<<collision<<endl;
    return collision;
    
}



bool Player::insideEdges(){
    //
    for(int i=0;i<PLAYER_HEIGHT+5;i++){
        for(int j=0;j<PLAYER_WIDTH+5;j++){
            
            
            ofColor c = boundaryMap.getPixelsRef().getColor(location.x+j,location.y+i);
            
            if(c.b<254){
                //    cout<<"here"<<endl;
                //cout<<c<<endl;
                return false;
                
            }
        }
    }
    return true;
    
}

Player::~Player() {
    
    //   delete avatar;
}
