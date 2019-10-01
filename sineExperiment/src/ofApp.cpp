#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    time = 0;
    ofSetBackgroundAuto(false);
    wHeight = ofGetHeight();
    wWidth = ofGetWidth();
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    
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
    sunSize = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (time < 1200){
        //randomly selects a colour from the palette
        int randSelector = ofRandom(5);
        ofSetHexColor(palettes[paletteSelector][randSelector]);
        
        pts[aI].x = x1(time) + (wWidth / 2);
        pts[aI].y = y1(time) + (wHeight / 2) - sunSize;
        nPts++;
        ofDrawLine(pts[aI].x, pts[aI].y, pts[1-aI].x, pts[1-aI].y);
        ofDrawLine(x1(time) + (wWidth / 2), y1(time) + (wHeight / 2) + sunSize, x2(time) + (wWidth / 2), y2(time)+ (wHeight / 2) + sunSize);
    }
    if (time > 1500) keyPressed(65555);
    time++;
    aI = 1 - aI;
}

float ofApp::x1(int t){
    return sin(t/10) * 100 + sin(t) * 2;
}

float ofApp::y1(int t){
    return cos(t/10) * sunSize;
}

float ofApp::x2(int t){
    return sin(t/10) * 100 + sin(t / 15) * 300;
}

float ofApp::y2(int t){
    return cos(t/10) * sunSize;
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
