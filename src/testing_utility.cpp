//
//  testing_utility.cpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/30/19.
//

#include <stdio.h>

#include "testing_utility.h"

bool operator==(const std::vector<SentencesTone::Sentence>& lhs, const std::vector<SentencesTone::Sentence> &rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    
    for (int i = 0; i < lhs.size(); i++) {
        if (!SentenceToneFieldsEqual(lhs[i], rhs[i])) {
            return false;
        } else if (lhs[i].tones.size() != rhs[i].tones.size()) {
            return false;
        }
        
        for (int j = 0; j < lhs[i].tones.size(); j++) {
            if (!ToneFieldsEqual(lhs[i].tones[j], rhs[i].tones[j])) {
                return false;
            }
        }
        
        return true;
    }

}

bool ToneFieldsEqual(SentencesTone::Tone lhs, SentencesTone::Tone rhs) {
    return lhs.tone_id == rhs.tone_id && lhs.tone_name == rhs.tone_name && lhs.score == rhs.score;
}

bool SentenceToneFieldsEqual(SentencesTone::Sentence lhs, SentencesTone::Sentence rhs) {
    return lhs.sentence_id == rhs.sentence_id && lhs.text == rhs.text;
}
