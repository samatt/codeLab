#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(true);
    ofBackground(255, 255, 255);
    
    for(int i=0; i<1; i++){
        ofColor _c;
        _c.set(128,100);
        Mover move(ofRandom(0.1, 4),ofRandom(0, ofGetWidth()),ofRandom(0,ofGetHeight()),_c );
        movers.push_back(move);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=0; i<movers.size(); i++){
        
        if(ofGetKeyPressed(' ')){
            ofVec2f force = a.attract(movers[i]);
            movers[i].applyForce(force);
        }
        else if(ofGetKeyPressed('k')){
            movers[i].location.y = ofGetHeight()-10;
        }
        else{
            wind.set(0.001,0);
            ofVec2f g;
            g.set(0,0.001*movers[i].mass);
            movers[i].applyForce(g);
        }

        movers[i].update();
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    //a.display();
    for(int i=0; i<movers.size(); i++){


        movers[i].display();
        movers[i].checkEdges();
    }
    
    //    m.applyForce(force);
    //    m.update();
    //    m.display();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
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
    
    int particles;
    particles = (int)ofRandom(5,15);
    cout<<particles<<endl;
    for(int i=0; i<particles; i++){
        ofColor _c;
        _c.setHex(ofRandom(0,0xFFFFFF));
        Mover move(ofRandom(0.1, 4),x,y,_c );
        ofVec2f force;
        force.set(ofRandom(0.01,1),ofRandom(0.01,1));
        move.applyForce(force);
        movers.push_back(move);
        
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    int particles = (int)ofRandom(5,15);
    cout<<particles<<endl;
    for(int i=0; i<particles; i++){
        ofColor _c;
        _c.setHex(ofRandom(0,0xFFFFFF));
        Mover move(ofRandom(0.1, 4),x,y,_c );
        ofVec2f force;
        force.set(-ofRandom(0.01,1),-ofRandom(0.01,1));
        move.applyForce(force);
        movers.push_back(move);
        
    }
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