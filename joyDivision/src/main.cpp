#include "ofMain.h"
#include "ofApp.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
/*
void ExecuteThread(int id){
    // Get current time
    auto nowTime = std::chrono::system_clock::now();
    
    // Put the thread to sleep for up to 3 seconds
    std::this_thread::sleep_for (std::chrono::milliseconds(50));
    nowTime = std::chrono::system_clock::now();
}
*/
