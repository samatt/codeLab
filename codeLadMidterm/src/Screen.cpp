//
//  Screen.cpp
//  codeLabObjects2
//
//  Created by Surya on 01/04/13.
//
//

#include "Screen.h"

Screen::Screen(){
    
}

Screen::Screen(int r, int g, int b, string _name){
 
    bgColor.r = r;
    bgColor.g = g;
    bgColor.b =b;
 
    name = _name;
}

void Screen::setup(){
    ofBackground(bgColor);
}

void Screen::update(){
    
}

void Screen::draw(){
    
}

void Screen::mousePressed(){
    
}

void Screen::keyPressed(int key){
    
}

void Screen::exit(){
    cout<<"exit screen"<<endl;
}