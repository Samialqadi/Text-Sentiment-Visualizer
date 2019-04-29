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

class Particle {
    
public:
    Particle();
    
    void setAttractPoints(vector<ofPoint> *attract);
    
    void reset();
    void update();
    void draw(std::string tone);
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    
    float drag;
    float uniqueVal;
    float scale;
    
    vector<ofPoint> *attractPoints;
};


#endif /* particle_hpp */
