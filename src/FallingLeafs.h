
#ifndef __TreeTest__FallingLeafs__
#define __TreeTest__FallingLeafs__

#include <stdio.h>
#include "ofMain.h"

class leafs {
    
public:
    
    void display();
    void update();
    leafs(int x, int y, int z);
    float n;
    
    ofVec3f pos;
    ofVec3f vel;
    
    int leafSize;
    int randomValue;
    float xoffset, yoffset;
    float noiseValue;
    vector<ofColor> col;
    
};

#endif /* defined(__TreeTest__FallingLeafs__) */
