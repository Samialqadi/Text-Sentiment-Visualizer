#include "ofMain.h"
#include "ofApp.h"
#include "string_to_json.hpp"
#include "sentiment.hpp"

//========================================================================
int main() {
	ofSetupOpenGL(1024, 768, OF_WINDOW);			// <-------- setup the GL context
        
//    test2();

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
