#include "ofApp.h"
#include <stdlib.h>

//--------------------------------------------------------------
void ofApp::setup(){
    step = 10;
    nPts = 0;
    size = 500;
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0);
    pointThrow = 0;
    
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
    time = 0;
    previousTime = 0;
    drawingDone = true;
    
    j = step;
    i = step;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    screenHeight = ofGetHeight();
    screenWidth = ofGetWidth();
    
    time = ofGetElapsedTimeMillis();
    
    if(drawingDone == false && (time - previousTime) >= 1){
        if(i <= (size - step)) {
            if(j <= (size - step)){
                pointThrow = ofRandom(10);
                int distanceToCenter = abs(j - size / 2);
                int variance = fmax(size / 2 - 100 - distanceToCenter, 0);
                pointThrow = ofRandom(variance /2 * -1);
                
                pts[j].x = j + screenWidth / 4;
                pts[j].y = i + (screenHeight / 4) + pointThrow;
                
                ofSetColor(255);
                
                //randomly selects a colour from the palette
                int randSelector = ofRandom(5);
                randSelector = ((i / 10) - 1) % 5;
                ofSetHexColor(palettes[paletteSelector][randSelector]);
                
                
                
                if(nPts>0){
                    ofDrawLine(pts[j-step].x, pts[j-step].y, pts[j].x, pts[j].y);
                    
                    //create a black polygon below the line to cover previous lines
                    ofSetColor(0);
                    polyPath.clear();
                    polyPath.moveTo(pts[j-step].x, pts[j-step].y + 1);
                    polyPath.lineTo(pts[j].x, pts[j].y + 1);
                    polyPath.lineTo(pts[j].x, screenHeight);
                    polyPath.lineTo(pts[j-step].x, screenHeight);
                    polyPath.close();
                    polyPath.setFillColor(0);
                    polyPath.draw();
                }
                nPts++;
                previousTime = time;
                j+=step;
            } else {
                i += step;
                j = step;
                nPts = 0;
            }
        }else {
            i = step;
            drawingDone = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofClear(0);
    
    //randomly selects a palette
    paletteSelector = ofRandom(991);
    drawingDone = false;
    i = step;
    j = step;
    nPts = 0;
    
    
    /*
     for(int i = step; i <= size - step; i += step) {
     nPts = 0;
     for(int j = step; j <= size - step; j+= step) {
     pointThrow = ofRandom(10);
     int distanceToCenter = abs(j - size / 2);
     int variance = fmax(size / 2 - 100 - distanceToCenter, 0);
     pointThrow = ofRandom(variance /2 * -1);
     
     pts[j].x = j + screenWidth / 4;
     pts[j].y = i + (screenHeight / 4) + pointThrow;
     
     ofSetColor(255);
     
     //randomly selects a colour from the palette
     int randSelector = ofRandom(5);
     randSelector = ((i / 10) - 1) % 5;
     ofSetHexColor(palettes[paletteSelector][randSelector]);
     
     
     
     if(nPts>0){
     ofDrawLine(pts[j-step].x, pts[j-step].y, pts[j].x, pts[j].y);
     
     //create a black polygon below the line to cover previous lines
     ofSetColor(0);
     polyPath.clear();
     polyPath.moveTo(pts[j-step].x, pts[j-step].y + 1);
     polyPath.lineTo(pts[j].x, pts[j].y + 1);
     polyPath.lineTo(pts[j].x, screenHeight);
     polyPath.lineTo(pts[j-step].x, screenHeight);
     polyPath.close();
     polyPath.setFillColor(0);
     polyPath.draw();
     }
     nPts++;
     }
     
     }
     */
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
