#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    branches.setup(); // Calling the setup
    // Defining the timers
    timer = ofGetElapsedTimeMillis();
    leafTimer = ofGetElapsedTimeMillis();
    deleteTimer = ofGetElapsedTimeMillis();
    //
}

//--------------------------------------------------------------
void ofApp::update(){
   
    for(int i = 0; i < l.size(); i ++){
        l[i]->update(); // Update the leafs position
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    timers(); // Call the timers function
    move ++;
    float rot = ofMap(move, 0, ofGetWidth(), 0, 360); // Map the mouse to rotate the the tree 360 degrees
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/6); // Translate to the tree
    ofRotateY(rot); // rotate the tree
    ofTranslate(-ofGetWindowWidth()/2, -ofGetWindowHeight()/6); // Translate again to make it turn around its own axis
  
    branches.display(); // Display the tree
    ofPushMatrix();
    ofTranslate(-600, -600); // Translate again to make the leafs spawn from the right place
    for(int i = 0; i < l.size(); i ++){ // Looping through the vector
        l[i]->display(); // Display the leafs
    }
    ofPopMatrix();
    ofPopMatrix();
}

void ofApp::timers(){
    
    if( ofGetElapsedTimeMillis() >= deleteTimer + 25000){
        deleteLeafs(); // Calling the destructor ( Deleting the leafs )
        deleteTimer = ofGetElapsedTimeMillis(); // Reset the timers
        leafTimer = ofGetElapsedTimeMillis();
        dropLeafs = true; // When the leafs are deleted flip dropLeafs back to true
    }
    
    if( ofGetElapsedTimeMillis() >= leafTimer + 8000){ // Drop leafs for 8 sec
        dropLeafs = false;
    }
    
    if(dropLeafs) { // If dropLeafs is equal to true
        if( ofGetElapsedTimeMillis() >= timer + 500){ // Every 0.5 sec
            create = true; // Switch create to true
            timer = ofGetElapsedTimeMillis(); // Reset the timer
        }
    }
    
    if(create) {
        createLeafs(); // Call the createLeafs function
         create = false; // set it back to false
    }
}

void ofApp::createLeafs(){
    
    for(int i = 0; i < 20; i ++){  // push back 10 leafs at a time at a random location
        
        l.push_back(new leafs(ofRandom(ofGetWidth()/2-300,ofGetWidth()/2+300 ), ofRandom(ofGetHeight()/2-100, ofGetHeight()/2+100), ofRandom(-200, 200))); // Creating new objects on the heap and filling the vector with pointers to these objects
    }
}

void ofApp::deleteLeafs(){
    
    while (!l.empty()) { // If the vector is not empty
        delete l.back(); // Freeing the memory on the heap
        l.erase(l.end()-1);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
      branches.reset();
   }

void ofApp::keyPressed(int key){
    //ofSaveScreen(ofToString(ofGetFrameNum())+".png");
//    if(key == OF_KEY_RIGHT ){
//        move +=5;
//    }
//    if(key == OF_KEY_LEFT ){
//        move -=5;
//    }
}
