#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"

class ofApp : public ofBaseApp {

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
    
    enum InputState {
        TAKE_USER_INPUT = false,
        DONT_TAKE_USER_INPUT = true
    };
    
    InputState current_state_;
    
    ofxCenteredTrueTypeFont title;
};
