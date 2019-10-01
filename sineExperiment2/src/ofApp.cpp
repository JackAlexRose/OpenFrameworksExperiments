#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    time = 0;
    //ofSetBackgroundAuto(false);
    wHeight = ofGetHeight();
    wWidth = ofGetWidth();
    ofSetBackgroundColor(0);
    //ofSetFrameRate(120);
    
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
    aI = 0;
    nPts = 0;
    sunSize = 200;
    
    ofSetLineWidth(5);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //if (time < 1200){
        //randomly selects a colour from the palette
        int randSelector = ofRandom(5);
        ofSetHexColor(palettes[paletteSelector][randSelector]);
        
        for(int i = 0; i <= 100; i+=10)
        {
        ofDrawLine(x1(time + i) + (wWidth / 2), y1(time + i) + (wHeight / 2), x2(time + i) + (wWidth / 2), y2(time + i)+ (wHeight / 2));
        }
    //}
    //if (time > 1500) keyPressed(65555);
    aI = 1 - aI;
    time++;

}

float ofApp::x1(float t){
    return sin(t/10) * 100 + sin(t / 5) * 20;
}

float ofApp::y1(float t){
    return cos(t/10) * 100;
}

float ofApp::x2(float t){
    return sin(t/10) * 200 + sin(t) * 2;
}

float ofApp::y2(float t){
    return cos(t/20) * sunSize + cos(t / 12) * 20;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofClear(0);
    nPts = 0;
    paletteSelector = ofRandom(991);
    time = 0;
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
    wHeight = ofGetHeight();
    wWidth = ofGetWidth();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

