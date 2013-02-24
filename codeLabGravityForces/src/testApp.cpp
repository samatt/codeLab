#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(true);
    ofBackground(255, 255, 255);
    

    //cout<<a.location<<","<<a.mass<<","<<a.G;
    //    gravity.set(0,0.001);
    //
    for(int i=0; i<1; i++){
        
        Mover move(10,ofRandom(0, ofGetWidth()),ofRandom(0,ofGetHeight()) );
        movers.push_back(move);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    //        for(int i=0; i<movers.size(); i++){
    //            wind.set(0.00001,0);
    //            ofVec2f g;
    //            g.set(0,0.1*movers[i].mass);
    //            cout<<movers[i].mass<<endl;
    //            movers[i].applyForce(g);
    //            movers[i].update();
    //
    //        }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //    for(int i=0; i<movers.size(); i++){
    //        movers[i].display();
    //        movers[i].checkEdges();
    //    }
    
//    ofVec2f force = a.attract(m);
        a.display();
    for(int i=0; i<movers.size(); i++){
        ofVec2f force = a.attract(movers[i]);
        movers[i].applyForce(force);
        movers[i].update();
        movers[i].display();
    }

    //cout<<force<<endl;
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