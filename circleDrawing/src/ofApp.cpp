#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    step = PI/5;  // see note 1
    time = 0;
    h = ofGetWidth() / 2;
    k = ofGetHeight() / 2;
    r = 10;
    previousTime = 0;
    f = 0;
    theta = 0;
    ai = 1;
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (f < 50){
        
        if(theta < (2* PI) + (step * 3)){
            x = h + r * cos(theta);
            y = k - r * sin(theta);
            ofDrawCircle(x, y, 2);
            theta+=step;
            previousTime = time;
        } else {
            r+=5;
            f+=3;
            step = PI/(5 + f);
            theta = 0;
        }
    } else {
        if(ai == 0){
            h = ofRandom(ofGetWidth());
            k = ofRandom(ofGetHeight());
        }
        f = 0;
        r = 10;
        ai = 1 - ai;
        ofSetColor(ai * 255);
        step = PI/5;
    }
    
//    var h = 150;
//    var k = 150;
//    var r = 50;
//
//    ctx.beginPath();  //tell canvas to start a set of lines
//
//    for(var theta=0;  theta < 2*Math.PI;  theta+=step)
//    { var x = h + r*Math.cos(theta);
//        var y = k - r*Math.sin(theta);    //note 2.
//        ctx.lineTo(x,y);
//    }
//
//    ctx.closePath();     //close the end to the start point
//    ctx.stroke();        //actually draw the accumulated lines
        time++;
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
