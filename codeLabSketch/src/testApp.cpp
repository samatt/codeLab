#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    xPos=0;
    yPos = ofGetHeight()/2;
    xRand = 0;
    yRand = 0;
    rPos = 20;
    rCircle =20;
    rRand = 20;
    xCircle = ofGetHeight()/2;
    background =false;
    pos = 0 ;
    circle = 0;
    rand =0;
    rainbow = false;
    pos.set(255, 0, 0);
    circle.set(0, 255, 0);
    rand.set(0,0,255);
    //    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void testApp::update(){
    
    if(ofGetKeyPressed(OF_KEY_RIGHT)){
        rot += 0.01;
        xCircle += 0.5;
        xRand += 0.5;
    }
    else if(ofGetKeyPressed(OF_KEY_LEFT)){
        rot -= 0.01;
        xCircle -= 0.5;
        xRand -= 0.5;
        
    }
    
    if(xPos>ofGetWidth()){
        xPos =0;
        alpha1 += 100;
    }
    else if(xPos<0){
        xPos = ofGetWidth();
        alpha1 -= 100;
        
    }
    if(xCircle>ofGetWidth()){
        xCircle = 0;
        alpha2 += 100;
    }
    else if(xCircle<0){
        alpha2 -= 100;
        xCircle = ofGetWidth();
    }
    if(xRand>ofGetWidth()){
        xRand =0;
        alpha3 += 100;
    }
    else if(xRand<0){
        alpha3 -= 100;
        xRand =ofGetWidth();
    }
    
    xPos = ofGetWidth()/2.0 + sin(rot)*100;
    yPos = ofGetHeight()/2.0+cos(rot)*100;
    yRand  = ofNoise(xRand/100)*300;//ofRandom(ofGetHeight()*.75,ofGetHeight());
    
}

//--------------------------------------------------------------
void testApp::draw(){
 
    if (rainbow) {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255),alpha1);
        ofCircle(xRand, yRand , rRand);
        
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255),alpha2);
        yCircle = ofGetHeight()/2.0+ sin(xCircle/50)*100;
        ofCircle(xCircle,yCircle, rCircle);
        
        
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255),alpha3);
        ofCircle(xPos , yPos, rPos) ;
        
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofCircle(xRand , yRand, 20) ;
        
        pos.set(ofRandom(255), ofRandom(255), ofRandom(255));
        circle.set(ofRandom(255), ofRandom(255), ofRandom(255));
        rand.set(ofRandom(255), ofRandom(255), ofRandom(255));
    }
    else
    {
        ofSetColor(255,0,0,alpha1);
        ofCircle(xRand, yRand , rRand);
        
        ofSetColor(0,255,0,alpha2);
        yCircle = ofGetHeight()/2.0+ sin(xCircle/50)*100;
        ofCircle(xCircle,yCircle, rCircle);
        
        
        ofSetColor(0,0,255,alpha3);
        ofCircle(xPos , yPos, rPos) ;
        
    }
    

    stringstream ss;
    
    // ofToString formatting available in 0072+
    ss << "a: Increase Size " << endl;
    ss << "b: Decrese Size"<< endl;
    ss << "1: Toggle Background " << endl;
    ss << "r: Rainbow Mode " << endl;

    ofSetColor(255);
    ofDrawBitmapString(ss.str(), 10, 10+12);
    
    
    //   ofDisableAlphaBlending();
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //  ofLog(OF_LOG_NOTICE,""+ ofToString(key));
    switch (key) {
        case OF_KEY_LEFT:
            //cout<<"here";
            xPos -=10;
            break;
        case OF_KEY_RIGHT:
            // cout<<"there";
            xPos += 10;
            break;
        case OF_KEY_UP:
            //cout<<"there";
            yPos -= 10;
            break;
        case OF_KEY_DOWN:
            //cout<<"there";
            yPos += 10;
            break;
        case 'a':
            //cout<<"there";
            rPos += 10;
            rCircle += 10;
            rRand += 10;
            break;
        case 'b':
            //cout<<"there";
            rPos -= 10;
            rCircle -= 10;
            rRand -= 10;
            break;
        case '1':
            background = !background;
            ofSetBackgroundAuto(background);
        case 'r':
            rainbow =!rainbow;
  
        default:
            break;
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