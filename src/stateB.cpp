#include "stateB.h"

//--------------------------------------------------------------
void stateB::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void stateB::update(){
    
}

//--------------------------------------------------------------
void stateB::draw(){
    ofRect(ofGetWidth()/2, ofGetHeight()/2, 100, 100);
}

string stateB::getName(){
    return "stateB";
}

//--------------------------------------------------------------
void stateB::keyPressed(int key){
    if (key == 'a') {
        changeState("stateA");
    }
}

//--------------------------------------------------------------
void stateB::keyReleased(int key){
    
}

//--------------------------------------------------------------
void stateB::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void stateB::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void stateB::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void stateB::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void stateB::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void stateB::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void stateB::dragEvent(ofDragInfo dragInfo){
    
}
