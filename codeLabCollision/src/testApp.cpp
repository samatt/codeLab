#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofBackground(255);
    a = Attractor();
    
    
    for (int i =0; i<NUM_OF_PARTICLES;i++){
        Mover _m = Mover();
        _m.init(ofRandom(1,5),ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        m.push_back(_m);
        
    }
    
    controller = &m[0];
 controller->color.set(128,128,0);
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i =0; i<NUM_OF_PARTICLES;i++){
        ofVec2f force = a.attract(m[i]);
        m[i].applyForce(force);
        m[i].update();
    }
    controller->checkCollison(m);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
  //  a.display();
    for(int i =0; i<NUM_OF_PARTICLES;i++){
        m[i].display();
        
    }

    if(controller->checkEdges()){
        for(int i =0; i<10;i++){
            m[i].color.set(128,100);
        }
       // controller->color = (128,128,0);
    }

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    if(key ==OF_KEY_DOWN){
        ofVec2f accdwn = ofVec2f(0, 5);
        controller->applyForce(accdwn);
        
    }
    else if(key ==OF_KEY_UP){
        ofVec2f accup = ofVec2f(0, -5);
        controller->applyForce(accup);
    }
    else if(key ==OF_KEY_LEFT){
        ofVec2f accleft = ofVec2f(-5, 0);
        controller->applyForce(accleft);
    }
    else if(key ==OF_KEY_RIGHT){
        ofVec2f accright = ofVec2f(5,0 );
        controller->applyForce(accright);
    }

    if(key == 'r'){
        controller->color.set(0,100);
        controller = &m[ofRandom(0,m.size())];
        controller->color.set(128,128,0);
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
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