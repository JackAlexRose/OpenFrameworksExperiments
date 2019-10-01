#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 125, 125);
    startWidth = ofGetWidth();
    startHeight = ofGetHeight();
    startX = startWidth / 2;
    startY = startHeight / 2;
    drawCircle(startX, startY, startWidth, startWidth);
}

void ofApp::drawCircle(int x, int y, float width, float height){
    ofNoFill();
    ofSetHexColor(0x69d2e7);
    ofDrawEllipse(x, y, width, height);
    if (width > 2 && height > 2) {
        width *= 0.7f;
        height *= 0.7f;
        drawCircle(x, y, width, height);
        drawCircle(x + width/2, y, width/2, height/2);
        drawCircle(x - width/2, y, width/2, height/2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
