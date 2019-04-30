//
//  json_handler.hpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/20/19.
//

#ifndef json_handler_hpp
#define json_handler_hpp

#define OBJECT 3
#define ARRAY 4
#define STRING 5
#define NUMBER 6

#include <stdio.h>
#include <string>
#include "sentences_tone.hpp"

std::vector<SentencesTone::Sentence> Parser(std::string json);
std::string BuildJson(std::string input);
bool IsValidJson(std::string json);

#endif /* json_handler_hpp */
