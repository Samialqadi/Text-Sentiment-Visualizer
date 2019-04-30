#pragma once

#include "ofMain.h"
#include "particle.hpp"
#include "json_handler.hpp"
#include "sentiment.hpp"
#include "sentences_tone.hpp"
#include "ofxCenteredTrueTypeFont.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();
        void resetParticles();

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
    
    ofxCenteredTrueTypeFont title;
    
    std::vector<SentencesTone::Sentence> sentence_tones;
    int current_num = 0;
    
    vector<Particle> particles;
    vector<ofPoint> attractPoints;
    vector<ofPoint> attractPointsWithMovement;
    
    double total_frame_time = 0;
    int num_of_particles = 500;
    
};
