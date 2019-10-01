#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    wHeight = 500;
    wWidth = 500;
    ofSetBackgroundColor(255);
    ofSetBackgroundAuto(false);
    ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    ofNoFill();
    ofDrawRectangle(ofGetWidth() / 2 - (wWidth / 2), ofGetHeight() / 2 - (wWidth / 2), wWidth, wHeight);
    ofSetLineWidth(2);
    
    for(int i = 0; i < 25; i++)
    {
        xPts[i].x = (ofGetWidth() / 2 - (wWidth / 2)) + (i * 20);
        xPts[i].y = ofGetHeight() / 2 + (wHeight / 2);
        
        yPts[i].x = ofGetWidth() / 2 - (wWidth / 2);
        yPts[i].y = (ofGetHeight() / 2 - (wHeight / 2))  + (i * 20);
        
        ofDrawLine(xPts[i].x, xPts[i].y, yPts[i].x, yPts[i].y);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
