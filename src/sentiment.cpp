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
#include "api_information.h"
#include "json_handler.hpp"

std::string ToneAnalyzer(std::string json) {
    // initialize RestClient
    RestClient::init();
    
    // get a connection object
    RestClient::Connection *conn = new RestClient::Connection("https://gateway.watsonplatform.net/tone-analyzer/api");
    
    // configure basic auth
    conn->SetBasicAuth("apikey", APIKEY);
    
    // set connection timeout to 5s
    conn->SetTimeout(5);
    
    // set different content header for POST, PUT and PATCH
    conn->AppendHeader("Content-Type", "application/json");
    RestClient::Response post = conn->post("/v3/tone?version=2017-09-21", json);
        
    // deinit RestClient
    RestClient::disable();
    
    delete conn;
    
    return post.body;
}
