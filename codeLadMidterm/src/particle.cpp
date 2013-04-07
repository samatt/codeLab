

#include "particle.h"


void ParticleSystem::setup(string name, int cx, int cy, int w, int h){

    png.loadImage(name);
    
    centerX = cx;
    centerY = cy;
    width = w;
    height = h;
    hit = false;
    
    
    for(unsigned int y = 0; y < png.height; y+=5){
        for(unsigned int x = 0; x < png.width; x+=5){
            
            ofVec2f pixelPosition;
            pixelPosition.set(cx+x,cy+y);
            ofColor c = png.getPixelsRef().getColor(x, y);
            int b = c.getBrightness();
            if(b < 230){
                Mover m =  Mover(pixelPosition, c);
                movers.push_back(m);
            }
            
        }
    }
    

}


void ParticleSystem::update(){

    for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].update();
    }
}


void ParticleSystem::draw(){
    
    for(unsigned int i = 0; i < movers.size(); i++){
        if(movers[i].location == movers[i].initialLoc) movers[i].draw();
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



void ParticleSystem::explode(int mx, int my){
    
    if(mx>centerX&&mx<centerX+width&&my<centerY+height&&my>centerY){
    hit=true;

        
        for(unsigned int i = 0; i < movers.size(); i++){
          
                ofVec2f force = ofVec2f(ofRandom(-100,100), ofRandom(-100,100));
                movers[i].applyForce(force);
            
                
            
        }

    }
    
}

