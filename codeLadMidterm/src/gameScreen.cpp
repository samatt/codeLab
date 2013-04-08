//
//  gameScreen.cpp
//  codeLabObjects2
//
//  Created by Surya on 01/04/13.
//
//

#include "gameScreen.h"
#include  "testApp.h"

gameScreen::gameScreen():Screen(255,0,0,"gameScreen"){
    
}

void gameScreen::setup(){
    //boundaryMap.loadImage("stage/8BitITP.svg");
    gameOver = false;
    bgGame.loadImage("stage/8BitITP-blank-1.jpg");
    score = 0;
    
    food[0].loadImage("food/burger.png");
    food[1].loadImage("food/pizza.png");
    score =0;
    foodpos.resize(12);
    
    foodpos[0].set(630,275);
    foodpos[1].set(764,338);
    foodpos[2].set(582,454);
    foodpos[3].set(735,450);
    foodpos[4].set(775,545);
    foodpos[5].set(900,310);
    foodpos[6].set(900,460);
    foodpos[7].set(715,125);
    foodpos[8].set(269,190);
    foodpos[9].set(40,190);
    foodpos[10].set(150,85);
    foodpos[11].set(900,200);
    

    furniture.resize(42);
    
    furniture[0].setup("furniture/m-chair-1.png", 660,235, 25, 25);
    furniture[1].setup("furniture/m-chair-2.png", 595,235, 25, 25);
    furniture[2].setup("furniture/m-chair-3.png", 595,300, 25, 25);
    furniture[3].setup("furniture/round-table.png", 610, 250, 65, 63);
    
    
    furniture[4].setup("furniture/m-chair-2.png", 720,300, 25, 25);
    furniture[5].setup("furniture/m-chair-3.png", 725,360, 25, 25);
    furniture[6].setup("furniture/m-chair-4.png", 785,360, 25, 25);
    furniture[7].setup("furniture/round-table.png", 740,315, 65, 63);
    
    
    furniture[8].setup("furniture/m-chair-2.png", 540,415, 25, 25);
    furniture[9].setup("furniture/m-chair-4.png", 610,475, 25, 25);
    furniture[10].setup("furniture/m-chair-1.png", 610,415, 25,25);
    furniture[11].setup("furniture/round-table.png", 560,430, 65, 63);
    
    
    furniture[12].setup("furniture/m-chair-2.png", 720,500, 25, 25);
    furniture[13].setup("furniture/m-chair-4.png", 700,630, 25, 25);
    furniture[14].setup("furniture/m-chair-1.png", 800,500, 25, 25);
    furniture[15].setup("furniture/round-table.png", 750,515, 65, 63);
    
    furniture[16].setup("furniture/o-chair.png", 890,190, 35, 30);
    furniture[17].setup("furniture/b-table.png", 860,220, 95, 33);
    
    furniture[18].setup("furniture/o-chair.png", 890,270, 35, 30);
    furniture[19].setup("furniture/b-table.png", 860,300, 95, 33);
    
    furniture[20].setup("furniture/o-chair.png", 890,350, 35, 30);
    furniture[21].setup("furniture/b-table.png", 860,380, 95, 33);
    
    furniture[22].setup("furniture/o-chair.png", 890,430, 35, 30);
    furniture[23].setup("furniture/b-table.png", 860,460, 95, 33);
    
    furniture[24].setup("furniture/printer.png", 710,431, 60, 50);
    
    furniture[25].setup("furniture/plant-1.png", 935,150, 45, 30);
    furniture[26].setup("furniture/plant-2.png", 945,180, 35, 30);
    furniture[27].setup("furniture/plant-1.png", 935,265, 45, 30);
    furniture[28].setup("furniture/plant-2.png", 945,355, 35, 30);
    furniture[29].setup("furniture/plant-1.png", 935,440, 45, 30);
    furniture[30].setup("furniture/plant-2.png", 925,500, 35, 30);
    
    furniture[31].setup("furniture/plant-3.png", 920,550, 48, 60);
    
    furniture[32].setup("furniture/o-chair.png", 700,90, 35, 30);
    furniture[33].setup("furniture/matt-desk.png", 643,120, 140, 35);
    furniture[34].setup("furniture/matt-plant.png", 710,147, 76, 35);
    
    furniture[35].setup("furniture/garbage.png", 380,485, 25, 22);
    furniture[36].setup("furniture/garbage.png", 50,65, 25, 22);
    
    furniture[37].setup("furniture/green-bench.png", 100,65, 115, 33);
    
    furniture[38].setup("furniture/o-chair.png", 30,160, 35, 30);
    furniture[39].setup("furniture/b-table.png", 0,190, 95, 33);
    
    furniture[40].setup("furniture/wood-bench.png", 220,185, 138, 35);
    
    furniture[41].setup("furniture/tiny-table.png", 380,58, 45, 42);
    
    /*
     furniture.resize(5);
     furniture[0].setup("furniture/garbage.png", 100, 700, 50, 50);
     furniture[1].setup("furniture/round-table.png", 605, 436, 50, 50);
     furniture[2].setup("furniture/round-table.png", 605, 282, 50, 50);
     furniture[3].setup("furniture/round-table.png", 760, 278, 50, 50);
     furniture[4].setup("furniture/round-table.png", 771, 449, 50, 50);
     */
   // player = Player();
    for(int i=0; i<NUM_OF_ENEMIES;i++){
        Enemy e= Enemy(ofVec2f(ofRandom(500, 800), ofRandom(100,200)));
        enemies.push_back(e);
    }
}
void gameScreen::loadPlayer(int p){
    player = Player(p);
}
void gameScreen::update(){
    
    player.update();
    
    if(furniture.size()>0){
        for(unsigned int j = 0; j < furniture.size(); j++){
            furniture[j].update();
            if(furniture[j].isExploded()&&furniture.size()>1){
                furniture.erase(furniture.begin()+j);
            }
        }
    }
    
    for(int i=0; i<NUM_OF_ENEMIES;i++){
        enemies[i].update();
    }
    
    for(int x=0;x<guns.size();x++){
        guns[x].update();
        if(!guns[x].checkEdges()){
            if(guns.size()>2 ){
                
                //debug
                cout<<guns.size()<<endl;
                
                //delete this vector value
                guns.erase(guns.begin()+(x-1));
            }
        }
        else{
            if(furniture.size()>0){
                for(unsigned int i = 0; i < furniture.size(); i++){
                    ofVec2f b = guns[x].bullet();
                    if(furniture[i].explode(b.x, b.y)){
                        guns.erase(guns.begin()+x);
                    }
                    
                }
            }
            
        }
    }
    if(foodpos.size()>0){
        for(int f=0;f<foodpos.size();f++){
            
            boundingBox b;
            b.x = foodpos[f].x;
            b.y = foodpos[f].y;
            b.width = FOOD_WIDTH;
            b.height = FOOD_HEIGHT;
            if (player.isFood(b)) {
                //  cout<<f<<player.isFood(b)<<endl;
                foodpos.erase(foodpos.begin()+f);
                score++;
            }
            
        }
    }
    
    for(int k=0;k<enemies.size();k++){
        
        if(player.isFood(enemies[k].b)){
            gameOver = true;
        }
    }

    
    
}

void gameScreen::draw(){
    
    bgGame.draw(0, 0,ofGetWidth(),ofGetHeight());
    player.display();
    
    for(int x=0;x<guns.size();x++){
        guns[x].display();
        
    }
    for(int i =0; i<NUM_OF_ENEMIES;i++){
        enemies[i].display();
    }
    
    ofSeedRandom(9);
    for (int i=0; i<foodpos.size(); i++){
        int imgnum = (ofRandom(0,2));
        food[imgnum].draw(foodpos[i].x,foodpos[i].y,FOOD_WIDTH,FOOD_HEIGHT);
    }
    if (furniture.size()>0) {
        for(unsigned int j = 0; j < furniture.size(); j++){
            furniture[j].draw();
        }
        
        for(unsigned int i = 0; i < furniture.size(); i++){
            furniture[i].drawExplosion();
        }
    }
    
    ofDrawBitmapString(ofToString(score), 121,672);
    
    if(gameOver){
        cout<<"game over"<<endl;
          testApp* app = (testApp*)ofGetAppPtr();
        app->currentScreen = &app->over;
        app->currentScreen->setup();

    }
}

void gameScreen::mousePressed(){
    cout<<"game screen mouse pressed";
    
}

void gameScreen::keyPressed(int key){
    if(key==OF_KEY_UP||key==OF_KEY_DOWN||key==OF_KEY_RIGHT||key==OF_KEY_LEFT){
        if(player.isCollided(furniture)==0){
            player.move(key);
        }
        else{
            player.alternateMove(key);
        }
        
        
    }
    else if(key==' '){
        gun g = gun();
        guns.push_back(g);
        
        ofVec2f a = ofVec2f();
        //shoot from the center of the player
        a.x = player.location.x+player.b.width/2;
        a.y = player.location.y+player.b.height/2;
        
        //shoot the latest bullet
        guns[guns.size()-1].shoot(a,player.currentDirection);
    }
}

void gameScreen::exit(){
    cout<<"exit game screen"<<endl;
}

