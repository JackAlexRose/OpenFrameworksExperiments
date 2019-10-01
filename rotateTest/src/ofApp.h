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
		
    ofEasyCam cam;
    float rotationX[5];
    float rotationY[5];
    float rotationZ[5];
    float time;
    int numBalls;
    float translateX[5];
    float translateY[5];
    float ballSize[5];
    float ballSpeed[5];
    int ballColour[5];

    string paletteString[1000][5];
    char paletteChar[1000][5][9];
    unsigned long int palettes[1000][5];
    int paletteSelector;
};
