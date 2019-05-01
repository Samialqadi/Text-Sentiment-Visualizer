//
//  particle.hpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/27/19.
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>
#include "ofMain.h"

// Modified from openFrameworks Example particle system
class Particle {
    
public:
    Particle();
    
    void SetAttractPoints(vector<ofPoint> *attract);
    
    void Reset();
    void Update();
    void Draw(std::string tone);
    
    void ApplyForces();
    void UpdatePosition();
    void RestrictToScreen();
    
    int kRandomLower = -10000;
    int kRandomUpper = 10000;
    double kVelocityLower = -3.9;
    double kVelocityUpper = 3.9;
    double kScaleLower = 0.5;
    double kScaleUpper = 1.0;
    double kDragLower = 0.95;
    double kDragUpper = 0.998;
    double kPosShift = 0.01;
    double kTimeShift = 0.2;
    double kScaleShift = 4.0;
    double kForceShift = 0.04;

    ofPoint position;
    ofPoint velocity;
    ofPoint force;
        
    float drag;
    float random_val;
    float scale;
    
    vector<ofPoint> *attract_points;
};


#endif /* particle_hpp */
