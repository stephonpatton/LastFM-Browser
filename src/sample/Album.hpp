//
// Created by Stephon Patton on 2/10/20.
//

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <iostream>
#include <json/json.h>
#include "Track.hpp"

//using namespace std;

class Album {
public:
    Album();
    ~Album();
    Json::Value value;
    std::string album_name;
    std::string artist;
    std::string image_url;
    std::string genre;
    std::string run_time;
    std::string summary;

    std::string setLastFMKey(std::string);
    Track getTrack(Track track);
    Album parseLastFMJson(std::string aJsonString);
private:
    std::string lastFMkey;
};

#endif //UNTITLED_ALBUM_HPP
