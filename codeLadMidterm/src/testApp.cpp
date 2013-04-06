#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    currentScreen = &intro;
    currentScreen->setup();


}

//--------------------------------------------------------------
void testApp::update(){
    currentScreen->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    currentScreen->draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if (key =='f') {
        ofToggleFullscreen();
    }
    
    currentScreen->keyPressed(key);
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    cout<<x<<" "<<y<<endl;
    currentScreen->mousePressed();


}

void testApp::exit(){
    currentScreen->exit();
}


