/**]
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation version 2
 * of the License.
 * <p/>
 * This program is distributed in the hope that it will be useful,
 * but without any warranty or fitness for a particular purpose.
 * <p/>
 * Please review the GNU General Public License at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 * see also: https://www.gnu.org/licenses/gpl-faq.html
 * so you are aware of the terms and your rights with regard to this software.
 * Or, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,USA
 * <p/>
 * Purpose: Sample C++ FLTK view class. Album handles the albums in the application.
 * Contains functions to add, remove, and look up albums and their tracks in a library.
 * This software is meant to run on Debian Wheezy Linux
 * <p/>
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Stephon Patton & Tim Lindquist (spatton6@asu.edu)
 * @file    Album.cpp
 * @date    January, 2020
 **/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <iostream>
#include <json/json.h>
#include "Track.hpp"

//using namespace std;

class Album
{
public:
    ~Album();
    Album();
    // Album(Album &j);
    Album(Json::Value root);

    Json::Value value;
    std::vector<Track> tracks;
    std::string album_name;
    std::string artist;
    std::string image_url; //extra large image
    std::string genre;
    std::string run_time; //hh:mm:ss
    std::string summary;

    std::string setLastFMKey(std::string);

    void removeTrack(Track track);
    Track getTrack(Track track);
    void addTrack(Track track);

    Album parseLastFMJson(std::string aJsonString);

private:
    std::string lastFMkey; //May not need this
};

#endif //UNTITLED_ALBUM_HPP
