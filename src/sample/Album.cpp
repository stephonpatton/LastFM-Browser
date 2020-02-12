//
// Created by Stephon Patton on 2/10/20.
//

#include "Album.hpp"
//#include <jsoncpp/json/json.h>  //TODO: Could be this on linux
#include <json/json.h>
#include <json/value.h>
//#include "samplemain.cpp"

#include <iostream>
using namespace std;


Album::Album() {
    lastFMkey = "hello";

}

Album::~Album() {
}


std::string Album::setLastFMKey(std::string key) {
    lastFMkey = key;
    return lastFMkey;
}

Track Album::getTrack(Track track) {
    track.getTrack();
}