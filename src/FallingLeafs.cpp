
#include "FallingLeafs.h"

leafs::leafs(int x, int y, int z ) {
    
    pos.set(x, y, z);
    vel.set(ofRandom(-2,-4), ofRandom(-2,2), ofRandom(0,-2));
    leafSize = ofRandom( 1, 3);
    
    ofColor pink(255, 187, 218); // pink
    ofColor white(255, 255, 255); // white
    col.push_back(pink); // Pushing both colours to the array
    col.push_back(white);
    n = ofRandom( 1, 4 );
    randomValue = ofRandom(0, 2); // returns a number between 0 and 1
}

void leafs::update() {
    
    xoffset -= 0.0002;
    yoffset = 0.0003;
    
    for( int i = 0; i < n; i ++) {
        noiseValue = ofMap(ofNoise(xoffset + i/4, yoffset), 0, 1, -PI/4, PI/4);
    }
    vel.x -= noiseValue;
    pos += vel; // Adding velocity to the position
    
}

void leafs::display(){
    
    ofSetColor(col[randomValue]); // Setting the colour to pink or white
    ofDrawCircle(pos.x, pos.y, pos.z, leafSize);
    
}

