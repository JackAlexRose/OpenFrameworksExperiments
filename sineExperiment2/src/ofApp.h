#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    float x1(float t);
    float y1(float t);
    float x2(float t);
    float y2(float t);
    
    float time;
    int wHeight;
    int wWidth;
    ofPoint pts[2];
    int aI;
    int nPts;
    int sunSize;
    
    string paletteString[1000][5];
    char paletteChar[1000][5][9];
    unsigned long int palettes[1000][5];
    int paletteSelector;
    
};

