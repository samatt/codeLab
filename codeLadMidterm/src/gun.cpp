//
//  gun.cpp
//  Explode
//
//  Created by Katie Adee on 4/5/13.
//
//

#include "gun.h"

gun::gun(){

};

gun::gun(float _x, float _y){
    loc.set(_x,_y);
    vel.set(0,0);
    
}

void gun::update(){
    loc+=vel;
    vel+=acc;
    vel.limit(30);
    

}

void gun::display(){
    ofRect(loc, 5, 5);
}

void gun::shoot(ofVec2f l, ofVec2f dir){
    loc.set(l);
    ploc.set(loc.x,loc.y);
    dir=dir.normalized();
    acc.set(dir);
    acc *= 0.95;
//    cout<<acc<<endl;

}

Boolean gun::checkEdges(){
    if((loc.x<0||loc.x||ofGetWidth())&&(loc.y<0||loc.y>ofGetHeight())){
        return false;
    }
    return true;
}

ofPoint gun::bullet(){
    return loc;
}

ofPoint gun::reload(){
    return ploc;
}
