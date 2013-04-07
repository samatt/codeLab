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
    vel.limit(20);
    

}

void gun::display(){
    ofRect(loc, 5, 5);
}

ofPoint gun::shoot(){
    ploc.set(loc.x,loc.y);
    acc.set(0,-2.0);
}

ofPoint gun::bullet(){
    return loc;
}

ofPoint gun::reload(){
    return ploc;
}
