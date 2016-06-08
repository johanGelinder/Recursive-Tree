#pragma once

#include "ofMain.h"
#include "Branch.h"
#include "FallingLeafs.h"

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void timers();
    void createLeafs();
    void deleteLeafs();
    void mousePressed(int x, int y, int button);
     void keyPressed(int key);
    Branch branches;
    vector<leafs*> l;
    
    float timer;
    float leafTimer;
    float deleteTimer;
    bool create = false;
    int numLeafs;
    bool dropLeafs = true;
    int move;
    
};
