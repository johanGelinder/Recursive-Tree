
#include <stdio.h>
#include "Branch.h"

void Branch::setup() {
    
    // Setting the initial values
    theta = 30.0;
    rotate = ofRandom(36.00,56.00);
    branchValue = 140;
    leafSize = ofRandom(2,4); // setting the size of the leafs
    n = ofRandom( 1, 4 );
}


void Branch::display() {
    
    ofBackground(20); // background colour
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()); // translating to middle of the screen and to bottom on the Y-axis
    xoffset += 0.06; // Increasing the x and yoffset variable
    yoffset += 0.003;
    ofSetColor(90,60,40); // set the colour of the trunk
    branch(branchValue); // Call the branch function and passing in 180
    
}

void Branch::reset() {
    
    theta = ofRandom(25.0, 40.0); // By pressed a key theta randomizes
}

float Branch::branch(float len) {
    
    float strokeWeight = ofMap(len, 8, 140, 0.5, 40); // Mapping Len to be the size of the branches
    
    ofSetLineWidth(strokeWeight*0.7); // Setting the "strokeWeight"
    ofDrawLine(0, 0, 0, -len); // Draw the trunk
    ofTranslate(0, -len); // Translate to -len ( end of the trunk )
    
    len *= 0.73; // Shrink the length of each branch when it grows
    
    ofPushMatrix();
    ofRotateY(rotate); // Rotate each branch
    
    if (len > 1.6) { // If len is greater than 1.6
        
        ofSetColor(90,60,40); // Set the colour
        for( int i = 0; i < n; i ++) { // Looping through n
            noiseValue = ofMap(ofNoise(xoffset + i, yoffset), 0, 1, -PI/2, PI/2); // Applying noise and saving the value in the variable noiseValue
        }
        
        ofPushMatrix();
        ofRotate(theta + 10 + noiseValue); // Rotate the next branch with theta + 10 + adding noise to the rotation to create the wind effect
        branch(len); // Call the branch function recursivly
        ofPopMatrix();
        ofSetColor(90,60,40); // Set the colour
        ofPushMatrix();
        ofRotate(-theta+noiseValue*0.5); // Rotate again and adding noise
        branch(len); // Call the branch function again
        ofPopMatrix();
        
    } else {
        
        ofSetColor(255); // Set the colour of the leafs
        ofDrawCircle(3,0, leafSize/2); // Draw the white leafs
        ofSetColor(255,187,218); // Set the colour of the leafs
        ofDrawCircle(0, 0, leafSize/2 ); // Draw the pink leafs
    }
    ofPopMatrix();

    return len;
}










