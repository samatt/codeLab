

#include "particle.h"


void ParticleSystem::setup(string name, int cx, int cy, int w, int h){
    
    png.loadImage(name);
    
    centerX = cx;
    centerY = cy;
    width = w;
    height = h;
    hit = false;
    prevHit = false;
    
    png.resize(width, height);
    
    for(unsigned int y = 0; y < height; y+=1){
        for(unsigned int x = 0; x < width; x+=1){
            
            ofVec2f pixelPosition;
            pixelPosition.set(cx+x,cy+y);
            ofColor c = png.getPixelsRef().getColor(x, y);
            //int b = c.getBrightness();
            //if(b < 255){
                Mover m =  Mover(pixelPosition, c);
                movers.push_back(m);
            //}
            
        }
    }
}


void ParticleSystem::update(){
    
    for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].update();
    }
}


void ParticleSystem::draw(){
    ofPushStyle();
    ofSetColor(0, 0, 128);
    ofCircle(centerX, centerY, 10);
    ofPopStyle();
    for(unsigned int i = 0; i < movers.size(); i++){
        if(movers[i].location == movers[i].initialLoc) movers[i].draw();
    }
    
}

bool ParticleSystem::isExploded(){

    float dist = ofDist(movers[0].location.x, movers[0].location.y, movers[0].initialLoc.x, movers[0].initialLoc.y);
    
    //if a pixel has moved more than 200 pxs from its original position its safe to assume it has explded
    if(dist>50){
        return true;
    }
    else{
        return false;
    }
    
}
void ParticleSystem::drawExplosion(){
    
    for(unsigned int i = 0; i < movers.size(); i++){
        float dist = ofDist(movers[i].location.x, movers[i].location.y, movers[i].initialLoc.x, movers[i].initialLoc.y);
        
        if(movers[i].location != movers[i].initialLoc && dist < 20*movers[i].velocity.length()){
            movers[i].draw();
        }
        
    }
}

void ParticleSystem::drawTarget(int mx, int my){
    
    
    if(mx > centerX-width/2 && mx < centerX+width/2 && my > centerY-height/2 && my < centerY+height/2){
        
    }
    
}


bool ParticleSystem::explode(int mx, int my){
    
    if(mx>centerX&&mx<centerX+width&&my<centerY+height&&my>centerY){
        hit=true;
                
        for(unsigned int i = 0; i < movers.size(); i++){
            
            ofVec2f force = ofVec2f(ofRandom(-10,10), ofRandom(-10,10));
            movers[i].applyForce(force);

        }
        return true;
    }
    return false;
}

