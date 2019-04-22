#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(63, 128, 170);  // Sets the background color to blue
    
    current_state_ = TAKE_USER_INPUT;
    
    title.load("AntipastoPro-Hairline_trial.ttf", 40);
    
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(54, 110, 145);
    ofDrawRectangle(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 500, 100);
    
    ofSetColor(255, 255, 255);
    title.drawString("test", 400, 400);
    
    switch (current_state_) {
    case TAKE_USER_INPUT:
        std::string answer = ofSystemTextBoxDialog("What text would you like to put into motion?");
        //call function that calls api
        std::cout << answer << std::endl;
        current_state_ = DONT_TAKE_USER_INPUT;
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    
}
