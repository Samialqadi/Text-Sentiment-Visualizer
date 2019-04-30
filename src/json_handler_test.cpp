//
//  json_handler_test.cpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/28/19.
//

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "json_handler.hpp"

int main(int argc, char *argv[]) {
    int result = Catch::Session().run(1, argv);
    
    return result;
}

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

TEST_CASE("JSON Parsing correctly") {
    std::string json = "{\"sentences_tone\":[{\"sentence_id\":0,\"text\":\"I hate these new features on this phone after the update.\",\"tones\":[{\"score\":0.593637,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":1,\"text\":\"I hate this phone company's products, you'd have to torture me to get me to use this phone.\",\"tones\":[{\"score\":0.567034,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"}]},{\"sentence_id\":2,\"text\":\"The emojis on this phone are stupid.\",\"tones\":[{\"score\":0.726412,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":3,\"text\":\"This phone is a useless, stupid waste of money.\",\"tones\":[{\"score\":0.809971,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]}]}";
    std::vector<SentencesTone::Sentence> sentence_tones = Parser(json);
    
    std::vector<SentencesTone::Sentence> expected_sentence_tones;
    
    SentencesTone::Sentence sentence1;
    sentence1.text = "I hate these new features on this phone after the update.";
    sentence1.sentence_id = 0;
    std::vector<SentencesTone::Tone> tones1;
    SentencesTone::Tone temp_tone_1;
    temp_tone_1.score = 0.593637;
    temp_tone_1.tone_id = "anger";
    temp_tone_1.tone_name = "Anger";
    tones1.push_back(temp_tone_1);
    sentence1.tones = tones1;
    
    SentencesTone::Sentence sentence2;
    sentence2.text = "I hate this phone company's products, you'd have to torture me to get me to use this phone.";
    sentence2.sentence_id = 1;
    std::vector<SentencesTone::Tone> tones2;
    SentencesTone::Tone temp_tone_2;
    temp_tone_2.score = 0.567034;
    temp_tone_2.tone_id = "confident";
    temp_tone_2.tone_name = "Confident";
    tones2.push_back(temp_tone_2);
    sentence2.tones = tones2;

    SentencesTone::Sentence sentence3;
    sentence3.text = "The emojis on this phone are stupid.";
    sentence3.sentence_id = 2;
    std::vector<SentencesTone::Tone> tones3;
    SentencesTone::Tone temp_tone_3;
    temp_tone_3.score = 0.726412;
    temp_tone_3.tone_id = "anger";
    temp_tone_3.tone_name = "Anger";
    tones3.push_back(temp_tone_3);
    sentence3.tones = tones3;

    SentencesTone::Sentence sentence4;
    sentence4.text = "This phone is a useless, stupid waste of money.";
    sentence4.sentence_id = 3;
    std::vector<SentencesTone::Tone> tones4;
    SentencesTone::Tone temp_tone_4;
    temp_tone_4.score = 0.809971;
    temp_tone_4.tone_id = "anger";
    temp_tone_4.tone_name = "Anger";
    tones4.push_back(temp_tone_4);
    sentence4.tones = tones4;
    
    expected_sentence_tones.push_back(sentence1);
    expected_sentence_tones.push_back(sentence2);
    expected_sentence_tones.push_back(sentence3);
    expected_sentence_tones.push_back(sentence4);

    REQUIRE(sentence_tones == expected_sentence_tones);
}

TEST_CASE("JSON being built properly") {
    std::string input = "This is the first sentence. This is the second sentence. I am trying to replicate what user input would look like.";
    std::string input_as_json = BuildJson(input);
    
    std::string expected_json = "{\"text\":\"This is the first sentence. This is the second sentence. I am trying to replicate what user input would look like.\"}";
    
    REQUIRE(input_as_json == expected_json);
}
