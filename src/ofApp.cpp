#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    title.load("AntipastoPro-Extralight_trial.ttf", 50);
    
    ofSetVerticalSync(true);
    
    //Call API and build vector from user input
    std::string answer = ofSystemTextBoxDialog("What text would you like to put into motion?");
    sentence_tones = Parser(ToneAnalyzer(BuildJson(answer)));

    particles.assign(num_of_particles * sentence_tones.size(), Particle());

    resetParticles();
}

//--------------------------------------------------------------
void ofApp::resetParticles() {
    for (unsigned int i = 0; i < particles.size(); i++) {
        particles[i].reset();
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (unsigned int i = 0; i < particles.size(); i++) {
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(60, 60, 60), ofColor(10, 10, 10));

    double last_frame = 0.0;
    if (ofGetLastFrameTime() < 0.5) {
        last_frame = ofGetLastFrameTime();
    }
    
    if (total_frame_time >= 5.0) {
        current_num++;
        total_frame_time = 0.0;
    }
    
    if (current_num < sentence_tones.size()) {
        for (int sen = 0; sen <= current_num; ++sen) {
            for (unsigned int i = num_of_particles * sen; i < num_of_particles * (sen + 1); i++) {
                particles[i].draw(SentencesTone::FindStrongestTone(sentence_tones[sen].tones));
            }
        }
        
        ofSetColor(255, 255, 255);
        title.drawString(sentence_tones[current_num].text, (ofGetWidth() / 2) - (title.stringWidth(sentence_tones[current_num].text) / 2), ofGetHeight() / 2);

    } else if (current_num == sentence_tones.size()) {        
        current_num = 0;
    }
    
    total_frame_time += last_frame;
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
