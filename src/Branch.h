
#ifndef branch_h
#define branch_h
#include "ofMain.h"

class Branch {

public:
    
    float branch(float len);
    
    void setup();
    void display();
    void reset();
    
    float theta, rotate;
    float branchValue;
    float leafSize;
    float xoffset, yoffset;
    float noiseValue;
    int n;
};

#endif /* branch_h */
