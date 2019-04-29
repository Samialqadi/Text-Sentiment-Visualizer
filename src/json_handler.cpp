//
//  json_handler.cpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/20/19.
//

#include "json_handler.hpp"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

std::vector<SentencesTone::Sentence> Parser(std::string json) {
    std::vector<SentencesTone::Sentence> sentence_tones;
    
    std::vector<char> vector_cpy(json.length() + 1);
    strcpy(vector_cpy.data(), json.c_str());
    
    rapidjson::Document document;
    document.Parse(vector_cpy.data());
    
    for (int i = 0; i < document["sentences_tone"].Size(); i++) {
        SentencesTone::Sentence sentence;
        
        sentence.text = document["sentences_tone"][i]["text"].GetString();
        
        for (int j = 0; j < document["sentences_tone"][i]["tones"].Size(); j++) {
            SentencesTone::Tone tone;
            
            tone.score = document["sentences_tone"][i]["tones"][j]["score"].GetDouble();
            tone.tone_id = document["sentences_tone"][i]["tones"][j]["tone_id"].GetString();
            tone.tone_name = document["sentences_tone"][i]["tones"][j]["tone_name"].GetString();
            
            sentence.tones.push_back(tone);
        }
        
        sentence_tones.push_back(sentence);
    }
    
    return sentence_tones;
}

std::string BuildJson(const std::string input) {
    rapidjson::StringBuffer json_string;
    rapidjson::Writer<rapidjson::StringBuffer> writer(json_string);
    
    std::vector<char> vector_cpy(input.length() + 1);
    strcpy(vector_cpy.data(), input.c_str());

    
    writer.StartObject();
    writer.Key("text");
    writer.String(vector_cpy.data());
    writer.EndObject();
    
    return json_string.GetString();
}
