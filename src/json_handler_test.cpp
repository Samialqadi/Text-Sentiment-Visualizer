////
////  json_handler_test.cpp
////  emotion-motion
////
////  Created by Sami Alqadi on 4/28/19.
////
//
//#define CATCH_CONFIG_RUNNER
//#include "catch.hpp"
//#include "testing_utility.h"
//#include "json_handler.hpp"
//
//int main(int argc, char *argv[]) {
//    int result = Catch::Session().run(1, argv);
//
//    return result;
//}
//
//TEST_CASE("JSON Parsing correctly") {
//    std::string json = "{\"sentences_tone\":[{\"sentence_id\":0,\"text\":\"I hate these new features on this phone after the update.\",\"tones\":[{\"score\":0.593637,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":1,\"text\":\"I hate this phone company's products, you'd have to torture me to get me to use this phone.\",\"tones\":[{\"score\":0.567034,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"}]},{\"sentence_id\":2,\"text\":\"The emojis on this phone are stupid.\",\"tones\":[{\"score\":0.726412,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":3,\"text\":\"This phone is a useless, stupid waste of money.\",\"tones\":[{\"score\":0.809971,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]}]}";
//    std::vector<SentencesTone::Sentence> sentence_tones = Parser(json);
//
//    std::vector<SentencesTone::Sentence> expected_sentence_tones;
//
//    SentencesTone::Sentence sentence1;
//    sentence1.text = "I hate these new features on this phone after the update.";
//    sentence1.sentence_id = 0;
//    std::vector<SentencesTone::Tone> tones1;
//    SentencesTone::Tone temp_tone_1;
//    temp_tone_1.score = 0.593637;
//    temp_tone_1.tone_id = "anger";
//    temp_tone_1.tone_name = "Anger";
//    tones1.push_back(temp_tone_1);
//    sentence1.tones = tones1;
//
//    SentencesTone::Sentence sentence2;
//    sentence2.text = "I hate this phone company's products, you'd have to torture me to get me to use this phone.";
//    sentence2.sentence_id = 1;
//    std::vector<SentencesTone::Tone> tones2;
//    SentencesTone::Tone temp_tone_2;
//    temp_tone_2.score = 0.567034;
//    temp_tone_2.tone_id = "confident";
//    temp_tone_2.tone_name = "Confident";
//    tones2.push_back(temp_tone_2);
//    sentence2.tones = tones2;
//
//    SentencesTone::Sentence sentence3;
//    sentence3.text = "The emojis on this phone are stupid.";
//    sentence3.sentence_id = 2;
//    std::vector<SentencesTone::Tone> tones3;
//    SentencesTone::Tone temp_tone_3;
//    temp_tone_3.score = 0.726412;
//    temp_tone_3.tone_id = "anger";
//    temp_tone_3.tone_name = "Anger";
//    tones3.push_back(temp_tone_3);
//    sentence3.tones = tones3;
//
//    SentencesTone::Sentence sentence4;
//    sentence4.text = "This phone is a useless, stupid waste of money.";
//    sentence4.sentence_id = 3;
//    std::vector<SentencesTone::Tone> tones4;
//    SentencesTone::Tone temp_tone_4;
//    temp_tone_4.score = 0.809971;
//    temp_tone_4.tone_id = "anger";
//    temp_tone_4.tone_name = "Anger";
//    tones4.push_back(temp_tone_4);
//    sentence4.tones = tones4;
//
//    expected_sentence_tones.push_back(sentence1);
//    expected_sentence_tones.push_back(sentence2);
//    expected_sentence_tones.push_back(sentence3);
//    expected_sentence_tones.push_back(sentence4);
//
//    REQUIRE(sentence_tones == expected_sentence_tones);
//}
//
//TEST_CASE("JSON being built properly") {
//    std::string input = "This is the first sentence. This is the second sentence. I am trying to replicate what user input would look like.";
//    std::string input_as_json = BuildJson(input);
//
//    std::string expected_json = "{\"text\":\"This is the first sentence. This is the second sentence. I am trying to replicate what user input would look like.\"}";
//
//    REQUIRE(input_as_json == expected_json);
//}
//
//TEST_CASE("Invalid JSON") {
//    SECTION("Empty json") {
//        std::string json = "{}";
//        
//        REQUIRE(!IsValidJson(json));
//    }
//    
//    SECTION("Error API response") {
//        std::string json = "{\"code\":400,\"sub_code\":\"C00007\",\"error\":\"No text given\"}";
//        
//        REQUIRE(!IsValidJson(json));
//    }
//    
//    SECTION("No tones") {
//        std::string json = "{\"document_tone\":{\"tones\":[]}}";
//        
//        REQUIRE(!IsValidJson(json));
//    }
//}
//
//TEST_CASE("Valid JSON") {
//    std::string json = "{\"document_tone\":{\"tones\":[{\"score\":0.565706,\"tone_id\":\"fear\",\"tone_name\":\"Fear\"},{\"score\":0.647322,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"},{\"score\":0.724923,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"}]},\"sentences_tone\":[{\"sentence_id\":0,\"text\":\"I hate these new features On #ThisPhone after the update.\",\"tones\":[{\"score\":0.637279,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":1,\"text\":\"I hate #ThisPhoneCompany products, you'd have to torture me to get me to use #ThisPhone.\",\"tones\":[{\"score\":0.591225,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"},{\"score\":0.645985,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"},{\"score\":0.560098,\"tone_id\":\"analytical\",\"tone_name\":\"Analytical\"}]},{\"sentence_id\":2,\"text\":\"The emojis in #ThisPhone are stupid.\",\"tones\":[{\"score\":0.760538,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":3,\"text\":\"#ThisPhone is a useless, stupid waste of money.\",\"tones\":[{\"score\":0.810585,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":4,\"text\":\"#ThisPhone is the worst phone I've ever had - ever \\uD83D\\uDE20.\",\"tones\":[{\"score\":0.517921,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"},{\"score\":0.874372,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"}]},{\"sentence_id\":5,\"text\":\"#ThisPhone another ripoff, lost all respect SHAME.\",\"tones\":[{\"score\":0.92125,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"}]},{\"sentence_id\":6,\"text\":\"I'm worried my #ThisPhone is going to overheat like my brother's did.\",\"tones\":[{\"score\":0.749632,\"tone_id\":\"fear\",\"tone_name\":\"Fear\"}]},{\"sentence_id\":7,\"text\":\"#ThisPhoneCompany really let me down... my new phone won't even turn on.\",\"tones\":[{\"score\":0.75152,\"tone_id\":\"tentative\",\"tone_name\":\"Tentative\"},{\"score\":0.672469,\"tone_id\":\"analytical\",\"tone_name\":\"Analytical\"}]}]}";
//    
//    REQUIRE(IsValidJson(json));
//}
