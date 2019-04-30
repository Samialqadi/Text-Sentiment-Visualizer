//
//  sentiment_test.cpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/29/19.
//

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "testing_utility.h"
#include "sentiment.hpp"
#include "json_handler.hpp"

int main(int argc, char *argv[]) {
    int result = Catch::Session().run(1, argv);

    return result;
}

TEST_CASE("API call working properly") {
    std::string input = "I hate these new features on this phone after the update. I hate this phone company's products, you'd have to torture me to get me to use this phone. The emojis on this phone are stupid. This phone is a useless, stupid waste of money.";
    std::vector<SentencesTone::Sentence> sentence_tones = Parser(ToneAnalyzer(BuildJson(input)));

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
