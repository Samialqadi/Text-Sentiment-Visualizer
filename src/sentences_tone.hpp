//
//  sentences_tone.hpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/22/19.
//

#ifndef sentences_tone_hpp
#define sentences_tone_hpp

#include <stdio.h>
#include <string>
#include <vector>

class SentencesTone {
public:
    struct Tone {
        double score;
        std::string tone_id;
        std::string tone_name;
        
    };
    
    struct Sentence {
        int sentence_id;
        std::string text;
        std::vector<Tone> tones;
    };
        
    static std::string FindStrongestTone(std::vector<SentencesTone::Tone> tones);
    
};

#endif /* sentences_tone_hpp */
