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

    
    avatar = new ofImage("player/surya-front.png");
    boundaryMap.loadImage("stage/hit-map.jpg");
    sprites[0].loadImage("player/surya-front.png");
    sprites[1].loadImage("player/surya-back.png");
    sprites[2].loadImage("player/surya-left.png");
    sprites[3].loadImage("player/surya-right.png");
    cout << avatar << " " << &sprites[0] << endl;
}

Player::Player( float x, float y){
    location.set(x,y);
    sprites.resize(4);
    
    sprites[0].loadImage("player/surya-front.png");
    sprites[1].loadImage("player/surya-back.png");
    sprites[2].loadImage("player/surya-left.png");
    sprites[3].loadImage("player/surya-right.png");
    // avtar.loadImage("player/surya-front.png");
    avatar = &sprites[0];
    
}


void Player:: move(int key){
    if(checkEdges()){
        switch (key) {
            case OF_KEY_UP:
                location.y-=10;
                avatar = &sprites[1];
                currentDirection.set(0,-1);
                break;
            case OF_KEY_DOWN:
                location.y+=10;
                avatar = &sprites[0];
                currentDirection.set(0,1);
                break;
            case OF_KEY_LEFT:
                location.x-=10;
                avatar = &sprites[2];
                currentDirection.set(-1,0);
                
                break;
            case OF_KEY_RIGHT:
                location.x+=10;
                avatar = &sprites[3];
                currentDirection.set(1,0);
                break;
            default:
                cout<<"im in move"<<endl;
                break;
        }

    }
    else{
        switch (key) {
            case OF_KEY_UP:
                location.y+=10;
                break;
            case OF_KEY_DOWN:
                location.y-=10;
                break;
            case OF_KEY_LEFT:
                location.x+=10;
                break;
            case OF_KEY_RIGHT:
                location.x-=10;
                break;
            default:
                cout<<"im in move"<<endl;
                break;
        }
    }
        
    
}

void Player::update(){
    b.x = location.x;
    b.y = location.y;
}
void Player::display(){

    avatar->draw(location.x, location.y,PLAYER_WIDTH,PLAYER_HEIGHT);
    
}
//
//Boolean Player::checkCollision(vector<Enemy> e) {
//
//    for(int i =)
//    if (!((box1.x + box1.width) >= box2.x)) {
//    return 0;     }
//    if (!(box1.x <= (box2.x + box2.width))) {
//        return 0;     }
//    if (!((box1.y - box1.height) <= box2.y)) {
//        return 0;     }
//    if (!(box1.y >= (box2.y - box2.height))) {
//        return 0;     }
//    return 1;
//}


Boolean Player::checkEdges(){
             //
   for(int j=0;j<PLAYER_WIDTH;j++){
   for(int i=0;i<PLAYER_HEIGHT;i++){
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
