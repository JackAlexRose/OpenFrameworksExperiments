#include "ofApp.h"
#include "math.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    
    //stop the canvas from refreshing every draw cycle
    ofSetBackgroundAuto(false);
    
    step = 20;
    
    //code for retrieving and parsing colour palette info
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
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    screenHeight = ofGetHeight();
    screenWidth = ofGetWidth();
}

void ofApp::addLine(int x, int y, int width, int height){

    leftToRight = (ofRandom(1) >= 0.5);
    
    //randomly selects a colour from the palette
    int randSelector = ofRandom(5);
    ofSetHexColor(palettes[paletteSelector][randSelector]);

    
    if(leftToRight) ofDrawLine(x, y, x+width, y+height);
    else ofDrawLine(x + width, y, x, y + height);
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofClear(0);
    
    //randomly selects a palette
    paletteSelector = ofRandom(991);
    
    for(int x = 0; x < screenWidth; x += step) {
        for(int y = 0; y < screenHeight; y+= step) {
            addLine(x, y, step, step);
        }
    }
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
