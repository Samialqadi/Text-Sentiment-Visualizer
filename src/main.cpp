#include "ofMain.h"
#include "ofApp.h"
#include "json_handler.hpp"
#include "sentiment.hpp"

//========================================================================
int main() {
	ofSetupOpenGL(1024, 768, OF_WINDOW);			// <-------- setup the GL context
    
    ToneAnalyzer(BuildJson("I am really sad. But if this works, I'll be really happy. So tell me code, are you going to work?"));
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
