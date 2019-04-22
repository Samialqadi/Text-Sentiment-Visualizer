//
//  string_to_json.cpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/20/19.
//

#include "string_to_json.hpp"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

void test() {
    // 1. Parse a JSON string into DOM.
    const char* json = "{\"document_tone\":{\"tones\":[{\"score\":0.565706,\"tone_id\":\"fear\",\"tone_name\":\"Fear\"},{\"score\":0.647322,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"},{\"score\":0.724923,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"}]},\"sentences_tone\":[{\"sentence_id\":0,\"text\":\"I hate these new features On #ThisPhone after the update.\",\"tones\":[{\"score\":0.637279,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":1,\"text\":\"I hate #ThisPhoneCompany products, you'd have to torture me to get me to use #ThisPhone.\",\"tones\":[{\"score\":0.591225,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"},{\"score\":0.645985,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"},{\"score\":0.560098,\"tone_id\":\"analytical\",\"tone_name\":\"Analytical\"}]},{\"sentence_id\":2,\"text\":\"The emojis in #ThisPhone are stupid.\",\"tones\":[{\"score\":0.760538,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":3,\"text\":\"#ThisPhone is a useless, stupid waste of money.\",\"tones\":[{\"score\":0.810585,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"}]},{\"sentence_id\":4,\"text\":\"#ThisPhone is the worst phone I've ever had - ever \\uD83D\\uDE20.\",\"tones\":[{\"score\":0.517921,\"tone_id\":\"anger\",\"tone_name\":\"Anger\"},{\"score\":0.874372,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"}]},{\"sentence_id\":5,\"text\":\"#ThisPhone another ripoff, lost all respect SHAME.\",\"tones\":[{\"score\":0.92125,\"tone_id\":\"confident\",\"tone_name\":\"Confident\"}]},{\"sentence_id\":6,\"text\":\"I'm worried my #ThisPhone is going to overheat like my brother's did.\",\"tones\":[{\"score\":0.749632,\"tone_id\":\"fear\",\"tone_name\":\"Fear\"}]},{\"sentence_id\":7,\"text\":\"#ThisPhoneCompany really let me down... my new phone won't even turn on.\",\"tones\":[{\"score\":0.75152,\"tone_id\":\"tentative\",\"tone_name\":\"Tentative\"},{\"score\":0.672469,\"tone_id\":\"analytical\",\"tone_name\":\"Analytical\"}]}]}";
    rapidjson::Document document;
    document.Parse(json);
    
    // 2. Modify it by DOM.
    const rapidjson::Value& sentences_tone = document["sentences_tone"];
    
    assert(sentences_tone.IsArray());
    
    for (rapidjson::Value::ConstValueIterator itr = sentences_tone.Begin(); itr != sentences_tone.End(); ++itr) {
        const rapidjson::Value& objects = *itr;
        assert(objects.IsObject()); // each attribute is an object
        for (rapidjson::Value::ConstMemberIterator itr2 = objects.MemberBegin(); itr2 != objects.MemberEnd(); ++itr2) {
            if (itr2->value.GetType() == 4) {
                for (auto &hello : itr2->value.GetArray()) {
                    for (rapidjson::Value::ConstMemberIterator itr3 = hello.MemberBegin(); itr3 != hello.MemberEnd(); ++itr3) {
                        if (itr3->value.GetType() == 5) {
                            std::cout << itr3->value.GetString() << std::endl;
                        } else if (itr3->value.GetType() == 6) {
                            std::cout << itr3->value.GetDouble() << std::endl;
                        }
                    }
                }
            } else if (itr2->value.GetType() == 5) {
                std::cout << itr2->value.GetString() << std::endl;
            } else if (itr2->value.GetType() == 6) {
                std::cout << itr2->value.GetInt() << std::endl;
            }
        }
    }
}
