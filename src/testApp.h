#pragma once

#include "ofMain.h"
#include "ofxDuration.h"
#include "ofxFX.h"
class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	ofxDuration duration;
	
	void trackUpdated(ofxDurationEventArgs& args);
	string ip;
	int port;
	
	ofxFluid fluid;
    
    ofVec2f oldM;
    int     width,height;
    bool    bPaint, bObstacle, bBounding, bClear;
};
