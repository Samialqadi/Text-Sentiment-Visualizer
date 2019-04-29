#include "particle.hpp"

//------------------------------------------------------------------
Particle::Particle() {
    attractPoints = NULL;
}

//------------------------------------------------------------------
void Particle::setAttractPoints(vector<ofPoint> *attract) {
    attractPoints = attract;
}

//------------------------------------------------------------------
void Particle::reset() {
    //the unique val allows us to set properties slightly differently for each particle
    uniqueVal = ofRandom(-10000, 10000);
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    vel.x = ofRandom(-3.9, 3.9);
    vel.y = ofRandom(-3.9, 3.9);
    
    frc = ofPoint(0, 0, 0);
    
    scale = ofRandom(0.5, 1.0);
    
    drag = ofRandom(0.95, 0.998);
}

//------------------------------------------------------------------
void Particle::update() {
    //1 - APPLY THE FORCES BASED ON WHICH MODE WE ARE IN
    
    ofPoint attractPt(ofGetWidth() / 2, ofGetHeight() / 2);
    frc = attractPt - pos;
    
    //let get the distance and only repel points close to the mouse
    float dist = frc.length();
    frc.normalize();
    
    vel *= drag;
    if (dist < 150) {
        vel += -frc * 0.6; //notice the frc is negative
    } else {
        //if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
        frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef() * 0.2);
        frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef() * 0.2);
        vel += frc * 0.04;
    }
    
    //2 - UPDATE OUR POSITION
    
    pos += vel;
    
    //3 - LIMIT THE PARTICLES TO STAY ON SCREEN
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1.0;
    } else if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1.0;
    }
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1.0;
    } else if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1.0;
    }
    
}

//------------------------------------------------------------------
void Particle::draw(std::string tone) {
    if (tone == "joy") {
        ofColor yellow(255, 255, 0);
        ofSetColor(yellow);
    } else if (tone == "fear") {
        ofColor white(255, 255, 255);
        ofSetColor(white);
    } else if (tone == "sadness") {
        ofColor blue(0, 0, 255);
        ofSetColor(blue);
    } else if (tone == "anger") {
        ofColor red(255, 0, 0);
        ofSetColor(red);
    } else if (tone == "analytical") {
        ofColor gray(128, 128, 128);
        ofSetColor(gray);
    } else if (tone == "confident") {
        ofColor brown(165, 42, 42);
        ofSetColor(brown);
    } else if (tone == "tentative") {
        ofColor light_blue(173, 216, 230);
        ofSetColor(light_blue);
    }
    
    ofDrawCircle(pos.x, pos.y, scale * 4.0);
}
