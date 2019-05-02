#include "ofApp.h"

void ofApp::setup() {
    foreground_sentence.load("AntipastoPro-Extralight_trial.ttf", 50);
    small_legend.load("AntipastoPro-Extralight_trial.ttf", 30);
    legend_emotion.load("AntipastoPro-Extralight_trial.ttf", 35);
    
    ofSetVerticalSync(true);
    
    std::string answer = ofSystemTextBoxDialog("What text would you like to put into motion?");
    sentence_tones = Parser(ToneAnalyzer(BuildJson(answer)));

    current_state_ = NO_LEGEND;
    
    particles.assign(num_of_particles * sentence_tones.size(), Particle());

    resetParticles();
}

void ofApp::resetParticles() {
    for (unsigned int i = 0; i < particles.size(); i++) {
        particles[i].Reset();
    }
}

void ofApp::update() {
    for (unsigned int i = 0; i < particles.size(); i++) {
        particles[i].Update();
    }
}

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
                particles[i].Draw(SentencesTone::FindStrongestTone(sentence_tones[sen].tones));
            }
        }
        
        ofSetColor(255, 255, 255);
        foreground_sentence.drawString(sentence_tones[current_num].text,
                         (ofGetWidth() / 2) - (foreground_sentence.stringWidth(sentence_tones[current_num].text) / 2), ofGetHeight() / 2);
    } else if (current_num == sentence_tones.size()) {        
        current_num = 0;
    }
    
    if (current_state_ == LEGEND) {
        DrawLegend();
    } else if (current_state_ == NO_LEGEND) {
        DrawLegendToggle();
    }
    
    total_frame_time += last_frame;
}

void ofApp::DrawLegend() {
    ofSetColor(192, 192, 192);
    ofRectangle legend;
    
    legend.x = ofGetWidth() * 0.1;
    legend.y = ofGetHeight() * 0.1;
    legend.width = ofGetWidth() * 0.8;
    legend.height = ofGetHeight() * 0.8;
    
    ofDrawRectRounded(legend, 10);
    
    ofColor gray(128, 128, 128);
    ofSetColor(gray);
    ofDrawRectangle(ofGetWidth() * 0.15, ofGetHeight() * 0.16,
                    ofGetWidth() * 0.1, ofGetHeight() * 0.13);
    legend_emotion.drawString("No emotion", ofGetWidth() * 0.28, ofGetHeight() * 0.24);

    ofColor yellow(255, 255, 0);
    ofSetColor(yellow);
    ofDrawRectangle(ofGetWidth() * 0.15, ofGetHeight() * 0.34,
                    ofGetWidth() * 0.1, ofGetHeight() * 0.13);
    legend_emotion.drawString("Joy", ofGetWidth() * 0.28, ofGetHeight() * 0.42);
    
    ofColor black(0, 0, 0);
    ofSetColor(black);
    ofDrawRectangle(ofGetWidth() * 0.15, ofGetHeight() * 0.52,
                    ofGetWidth() * 0.1, ofGetHeight() * 0.13);
    legend_emotion.drawString("Fear", ofGetWidth() * 0.28, ofGetHeight() * 0.6);
    
    ofColor blue(0, 0, 255);
    ofSetColor(blue);
    ofDrawRectangle(ofGetWidth() * 0.15, ofGetHeight() * 0.71,
                    ofGetWidth() * 0.1, ofGetHeight() * 0.13);
    legend_emotion.drawString("Sadness", ofGetWidth() * 0.28, ofGetHeight() * 0.79);

    ofColor red(255, 0, 0);
    ofSetColor(red);
    ofDrawRectangle(ofGetWidth() * 0.55, ofGetHeight() * 0.16,
                    ofGetWidth() * 0.1, ofGetHeight() * 0.13);
    legend_emotion.drawString("Anger", ofGetWidth() * 0.68, ofGetHeight() * 0.24);
    
    ofColor purple(128, 0, 128);
    ofSetColor(purple);
    ofDrawRectangle(ofGetWidth() * 0.55, ofGetHeight() * 0.34,
                    ofGetWidth() * 0.1, ofGetHeight() * 0.13);
    legend_emotion.drawString("Analytical", ofGetWidth() * 0.68, ofGetHeight() * 0.42);
    
    ofColor brown(165, 42, 42);
    ofSetColor(brown);
    ofDrawRectangle(ofGetWidth() * 0.55, ofGetHeight() * 0.52,
                    ofGetWidth() * 0.1, ofGetHeight() * 0.13);
    legend_emotion.drawString("Confident", ofGetWidth() * 0.68, ofGetHeight() * 0.6);
    
    ofColor light_blue(173, 216, 230);
    ofSetColor(light_blue);
    ofDrawRectangle(ofGetWidth() * 0.55, ofGetHeight() * 0.71,
                    ofGetWidth() * 0.1, ofGetHeight() * 0.13);
    legend_emotion.drawString("Tentative", ofGetWidth() * 0.68, ofGetHeight() * 0.79);
}

void ofApp::DrawLegendToggle() {
    ofColor gray(128, 128, 128);
    ofSetColor(gray);
    ofRectangle legend_toggle;
    
    legend_toggle.x = ofGetWidth() * 0.25;
    legend_toggle.y = ofGetHeight() * 0.9;
    legend_toggle.width = ofGetWidth() * 0.5;
    legend_toggle.height = ofGetHeight() * 0.2;
    
    ofDrawRectRounded(legend_toggle, 10);
    
    ofSetColor(0, 0, 0); //white
    std::string small_legend_text = "Click for color legend";
    small_legend.drawString(small_legend_text, ofGetWidth() * 0.5 - (small_legend.stringWidth(small_legend_text) / 2), ofGetHeight() * 0.97);
}

void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y) {

}

void ofApp::mouseDragged(int x, int y, int button) {

}

void ofApp::mousePressed(int x, int y, int button) {
    if (current_state_ == LEGEND) {
        current_state_ = NO_LEGEND;
    } else {
        current_state_ = LEGEND;
    }
}

void ofApp::mouseReleased(int x, int y, int button) {

}

void ofApp::mouseEntered(int x, int y) {

}

void ofApp::mouseExited(int x, int y) {

}

void ofApp::windowResized(int w, int h) {

}

void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::dragEvent(ofDragInfo dragInfo) {
    
}
