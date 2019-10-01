#include "ofApp.h"
#include <json.hpp>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void ofApp::setup(){
    gui.setup();
    gui.add(switchRand.setup("Even distribution", false));
    
    font1.load("Roboto-Light.ttf", 40);
    fontGrey = 80;
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
        
        cout << paletteSelector << endl;
    }
    }

void ofApp::draw(){
    gui.draw();
    
    time = ofGetElapsedTimef();
    
    ofSetBackgroundColor(80, 80, 80);

    
    for(int i = 0; i < 200; i++) {
        width = ofGetWidth() * 2;
        height = ofGetHeight() * 2;
        speed = 0.1;
        posX = i * 29.4;
        posY = i * 29.8;
        x = width * ofNoise(time * speed + posX);
        y = height * ofNoise(time * speed + posY);
        
        if(switchRand == 0){
            int randSelector = ofNoise(posX) * 7 - 1;
            ofSetHexColor(palettes[paletteSelector][randSelector]);
        } else if(switchRand == 1){
            int modulusRand = i % 5;
            ofSetHexColor(palettes[paletteSelector][modulusRand]);
        }
        ofDrawCircle(x, y, 23);
    }
    
    ofSetColor(fontGrey, fontGrey, fontGrey);
    font1.drawString("Wednesday", (ofGetWidth() / 4) * 2.75, (ofGetHeight() / 4) * 3.75);
}

void ofApp::keyPressed(int key){

    if(key == 57358) {
        paletteSelector++;
        if(paletteSelector > 991) paletteSelector = 0;
    }
    if(key == 57356) {
        paletteSelector--;
        if(paletteSelector < 0) paletteSelector = 991;
    }
    
    cout << paletteSelector << endl;
    
}

