#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void addLine(int x, int y, int width, int height);
    

    bool leftToRight;
    int step;
    int screenHeight;
    int screenWidth;
    
    string paletteString[1000][5];
    char paletteChar[1000][5][9];
    unsigned long int palettes[1000][5];
    int paletteSelector;
};
