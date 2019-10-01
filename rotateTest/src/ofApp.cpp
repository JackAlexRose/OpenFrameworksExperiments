#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    time = 0;
    ofSetBackgroundColor(0);
    numBalls = 5;
    //translateX = ofRandom(ofGetWidth());
    //translateY = ofRandom(ofGetHeight());
    
    ofFile file("1000.json");
    if(file.exists()){
        cout << "found file" << endl;
        ofJson json = ofLoadJson( "1000.json" );
        for(int i = 0; i<992; i++)
        {
            for(int n = 0; n<5; n++){
                paletteString[i][n] = json[i][n];
                strcpy(paletteChar[i][n], paletteString[i][n].c_str());
                palettes[i][n] = strtoul(paletteChar[i][n],0,16);
            }
        }
        paletteSelector = ofRandom(991);
    }
    
    for(int i = 0; i < 5; i++){
        translateX[i] = ofRandom(ofGetWidth());
        translateY[i] = ofRandom(ofGetHeight()) - ofGetHeight() - 200;
        ballSize[i] = ofRandom(180) + 20;
        ballSpeed[i] = ofRandom(4) + 1;
        ballColour[i] = ofRandom(5);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < 5; i++){
        translateY[i]+= ballSpeed[i];
        if(translateY[i] > ofGetHeight() + ballSize[i] * 2) {
            translateY[i] = ofRandom(ofGetHeight()) - ofGetHeight() - 200;
            translateX[i] = ofRandom(ofGetWidth());
            ballSize[i] = ofRandom(180) + 20;
            ballSpeed[i] = ofRandom(4) + 1;
            ballColour[i] = ofRandom(5);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < 5; i++){
        rotationX[i] = ofNoise(time + i) * 360;
        rotationY[i] = ofNoise(time + 90 + i) * 360;
        rotationZ[i] = ofNoise(time + 180 + i) * 360;
    }
    
    for(int i = 0; i < 5; i++){
        ofPushMatrix();
        ofTranslate(translateX[i], translateY[i]);
        ofRotateXDeg(rotationX[i]);
        ofRotateYDeg(rotationY[i]);
        ofRotateZDeg(rotationZ[i]);
        
        ofSetHexColor(palettes[paletteSelector][ballColour[i]]);
        ofDrawIcoSphere(ballSize[i]);
        ofTranslate(-translateX[i], -translateY[i]);
        ofPopMatrix();
    }
    time+=0.01;
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    paletteSelector = ofRandom(991);

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
