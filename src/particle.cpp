#include "particle.hpp"

Particle::Particle() {
    attract_points = NULL;
}

void Particle::SetAttractPoints(vector<ofPoint> *attract) {
    attract_points = attract;
}

void Particle::Reset() {
    random_val = ofRandom(kRandomLower, kRandomUpper);
    
    position.x = ofRandomWidth();
    position.y = ofRandomHeight();
    
    velocity.x = ofRandom(kVelocityLower, kVelocityUpper);
    velocity.y = ofRandom(kVelocityLower, kVelocityUpper);
    
    force = ofPoint(0, 0, 0);
    
    scale = ofRandom(kScaleLower, kScaleUpper);
    
    drag = ofRandom(kDragLower, kDragUpper);
}

void Particle::Update() {
    ApplyForces();
    
    UpdatePosition();
    
    RestrictToScreen();
}

void Particle::Draw(std::string tone) {
    if (tone == "") {
        ofColor gray(128, 128, 128);
        ofSetColor(gray);
    } else if (tone == "joy") {
        ofColor yellow(255, 255, 0);
        ofSetColor(yellow);
    } else if (tone == "fear") {
        ofColor black(0, 0, 0);
        ofSetColor(black);
    } else if (tone == "sadness") {
        ofColor blue(0, 0, 255);
        ofSetColor(blue);
    } else if (tone == "anger") {
        ofColor red(255, 0, 0);
        ofSetColor(red);
    } else if (tone == "analytical") {
        ofColor purple(128, 0, 128);
        ofSetColor(purple);
    } else if (tone == "confident") {
        ofColor brown(165, 42, 42);
        ofSetColor(brown);
    } else if (tone == "tentative") {
        ofColor light_blue(173, 216, 230);
        ofSetColor(light_blue);
    }
    
    ofDrawCircle(position.x, position.y, scale * kScaleShift);
}

void Particle::ApplyForces() {
    ofPoint attraction_point(ofGetWidth() / 2, ofGetHeight() / 2);
    force = attraction_point - position;
    
    velocity *= drag;
    
    force.x = ofSignedNoise(random_val, position.y * kPosShift, ofGetElapsedTimef() * kTimeShift);
    force.y = ofSignedNoise(random_val, position.x * kPosShift, ofGetElapsedTimef() * kTimeShift);
    velocity += force * kForceShift;
}

void Particle::UpdatePosition() {
    position += velocity;
}

void Particle::RestrictToScreen() {
    if (position.x > ofGetWidth()) {
        position.x = ofGetWidth();
        velocity.x *= -1.0;
    } else if (position.x < 0) {
        position.x = 0;
        velocity.x *= -1.0;
    }
    
    if (position.y > ofGetHeight()) {
        position.y = ofGetHeight();
        velocity.y *= -1.0;
    } else if (position.y < 0) {
        position.y = 0;
        velocity.y *= -1.0;
    }
}
