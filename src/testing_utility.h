//
//  testing_utility.h
//  emotion-motion
//
//  Created by Sami Alqadi on 4/29/19.
//

#ifndef testing_utility_h
#define testing_utility_h

#include "sentences_tone.hpp"

bool operator==(const std::vector<SentencesTone::Sentence>& lhs, const std::vector<SentencesTone::Sentence> &rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    
    for (int i = 0; i < lhs.size(); i++) {
        if (lhs[i].sentence_id != rhs[i].sentence_id) {
            return false;
        } else if (lhs[i].text != rhs[i].text) {
            return false;
        } else if (lhs[i].tones.size() != rhs[i].tones.size()) {
            return false;
        }
        
        for (int j = 0; j < lhs[i].tones.size(); j++) {
            if (lhs[i].tones[j].tone_id != rhs[i].tones[j].tone_id) {
                return false;
            } else if (lhs[i].tones[j].tone_name != rhs[i].tones[j].tone_name) {
                return false;
            } else if (lhs[i].tones[j].score != rhs[i].tones[j].score) {
                return false;
            }
        }
        
        return true;
    }
}

#endif /* testing_utility_h */
