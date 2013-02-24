#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    rectCoord.set(ofGetWidth()/2, ofGetHeight()/2);
    mouseCoord.set(0, 0);
    direction.set(0,0);
    momentum.set(.1,.1);
    force.set(0,.1);
    velocity = 10;
    
    acceleration = 0.2;
    //   cout<< direction.normalize();
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    //rectCoord = mouseCoord;
    direction = mouseCoord - rectCoord;
    direction.normalize();
    
    if(ofGetKeyPressed(32)){
        velocity = 1.5;
        momentum += direction*velocity;
        //velocity += acceleration*3;
        
    }
    else{
        //velocity -= acceleration;
        velocity =0;
        momentum+=force;
        
    }
    
    if(velocity<0){
        velocity = 0;
    }
    rectCoord +=momentum;
    
    if(rectCoord.x<0){
        momentum.x =-0.75*momentum.x;
        rectCoord.x =0;
    }
    else if(rectCoord.x>ofGetWidth()){
        momentum.x =-0.75*momentum.x;
        rectCoord.x = ofGetWidth()-10;
    }
    if(rectCoord.y>=ofGetHeight()){
        momentum.y = -0.75*momentum.y;
        rectCoord.y = ofGetHeight()-10;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(128, 128, 128);
    ofRect(rectCoord, 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mouseCoord.set(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}