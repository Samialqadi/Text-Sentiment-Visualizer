//
//  sentences_tone_test.cpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/29/19.
//

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "sentences_tone.hpp"

int main(int argc, char *argv[]) {
    int result = Catch::Session().run(1, argv);

    return result;
}

TEST_CASE("Finding Strongest Tone") {
    std::vector<SentencesTone::Tone> tones;

    SentencesTone::Tone temp_tone_1;
    temp_tone_1.score = 0.593637;
    temp_tone_1.tone_id = "tentative";
    temp_tone_1.tone_name = "tentative";

    SentencesTone::Tone temp_tone_2;
    temp_tone_2.score = 0.567034;
    temp_tone_2.tone_id = "confident";
    temp_tone_2.tone_name = "Confident";

    SentencesTone::Tone temp_tone_3;
    temp_tone_3.score = 0.726412;
    temp_tone_3.tone_id = "anger";
    temp_tone_3.tone_name = "Anger";

    SentencesTone::Tone temp_tone_4;
    temp_tone_4.score = 0.809971;
    temp_tone_4.tone_id = "anger";
    temp_tone_4.tone_name = "Anger";

    tones.push_back(temp_tone_1);
    tones.push_back(temp_tone_2);
    tones.push_back(temp_tone_3);
    tones.push_back(temp_tone_4);

    SECTION("Many tones") {
        REQUIRE(SentencesTone::FindStrongestTone(tones) == "anger");
    }

    SECTION("One Tone") {
        tones.pop_back();
        tones.pop_back();
        tones.pop_back();

        REQUIRE(SentencesTone::FindStrongestTone(tones) == "tentative");
    }

    SECTION("No tones") {
        tones.pop_back();
        tones.pop_back();
        tones.pop_back();
        tones.pop_back();

        REQUIRE(SentencesTone::FindStrongestTone(tones) == "");
    }

}
