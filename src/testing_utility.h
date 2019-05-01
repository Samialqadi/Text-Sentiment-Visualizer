//
//  testing_utility.h
//  emotion-motion
//
//  Created by Sami Alqadi on 4/29/19.
//

#ifndef testing_utility_h
#define testing_utility_h

#include "sentences_tone.hpp"

bool operator==(const std::vector<SentencesTone::Sentence>& lhs, const std::vector<SentencesTone::Sentence> &rhs);

bool ToneFieldsEqual(SentencesTone::Tone lhs, SentencesTone::Tone rhs);

bool SentenceToneFieldsEqual(SentencesTone::Sentence lhs, SentencesTone::Sentence rhs);

#endif /* testing_utility_h */
