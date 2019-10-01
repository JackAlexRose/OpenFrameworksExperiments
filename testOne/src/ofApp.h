#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
    
        void keyPressed(int key);

		
    float posX;
    float posY;
    float x;
    float y;
    float time;
    float width;
    float height;
    float speed;
    
    ofTrueTypeFont font1;
    int fontGrey;
    
    string paletteString[1000][5];
    char paletteChar[1000][5][9];
    unsigned long int palettes[1000][5];
    int paletteSelector;
    
    ofxPanel gui;
    ofxToggle switchRand;
    bool randMode;
};
