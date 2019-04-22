//
//  sentiment.cpp
//  emotion-motion
//
//  Created by Sami Alqadi on 4/20/19.
//

#include <iostream>
#include "sentiment.hpp"

#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

void test2() {
    std::cout << "Under the bed" << std::endl;

    // initialize RestClient
    RestClient::init();
    
    // get a connection object
    RestClient::Connection* conn = new RestClient::Connection("https://gateway.watsonplatform.net/tone-analyzer/api");
    
    // configure basic auth
    conn->SetBasicAuth("apikey", "UcoL6cwUaDMZxniXJ6s6amNj07h0uPP4vsN04crzRrK_");
    
    // set connection timeout to 5s
    conn->SetTimeout(5);
    
    // set different content header for POST, PUT and PATCH
    conn->AppendHeader("Content-Type", "application/json");
    RestClient::Response post = conn->post("/v3/tone?version=2017-09-21", "{\"text\": \"I hate these new features On #ThisPhone after the update. I hate #ThisPhoneCompany products, you'd have to torture me to get me to use #ThisPhone. The emojis in #ThisPhone are stupid. #ThisPhone is a useless, stupid waste of money. #ThisPhone is the worst phone I've ever had - ever 😠. #ThisPhone another ripoff, lost all respect SHAME. I'm worried my #ThisPhone is going to overheat like my brother's did. #ThisPhoneCompany really let me down... my new phone won't even turn on.\"}");
    
    std::cout << post.body;
    
    // deinit RestClient. After calling this you have to call RestClient::init()
    // again before you can use it
    RestClient::disable();
}
