//
//  sentences_tone.cpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/22/19.
//

#include "sentences_tone.hpp"

std::string FindStrongestTone(std::vector<SentencesTone::Tone> tones) {
    if (tones.empty()) {
        return "";
    }
    
    SentencesTone::Tone max_tone = tones[0];
    double max = tones[0].score;
    
    for (SentencesTone::Tone tone : tones) {
        if (tone.score > max) {
            max = tone.score;
            max_tone = tone;
        }
    }
    
    return max_tone.tone_id;
}
