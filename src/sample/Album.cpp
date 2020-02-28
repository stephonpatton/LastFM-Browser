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

#include "Album.hpp"
//#include <jsoncpp/json/json.h>
#include <json/json.h>
#include <json/value.h>
#include <vector>
#include <stdlib.h>
#include "Track.hpp"
//#include "samplemain.cpp"

#include <iostream>
using namespace std;

// Album::Album(Album &album)
// {
// }

Track tracks = Track();
Album::Album()
{
}
Album::~Album()
{
}

Album::Album(Json::Value)
{
}

// Album Album::parseLastFMJson(std::string aJsonString)
// {
// }

std::string Album::setLastFMKey(std::string key)
{
    lastFMkey = key;
    return lastFMkey;
}

Album Album::parseLastFMJson(std::string aJsonString)
{
    Album album = Album();
    Json::Reader reader;
    Json::Value root;

    bool parseSuccess = reader.parse(aJsonString, root, false);
    if (parseSuccess)
    {
        //TODO: Delete later
        Json::Value::Members mbr = root.getMemberNames();
        for (vector<string>::const_iterator i = mbr.begin(); i != mbr.end(); i++)
        {
            Json::Value jsonM = root[*i];
            // if (*i == "album")
            // {
            //     const Json::Value track_array = root["tracks"];
            //     // for (int index = 0; index < track_array.size(); ++index)
            //     // {
            //     //     cout << "Track array : " << track_array[index].asString() << endl;
            //     // }
            //     // cout << "From track class: " << track_array << endl;
            //     // cout << "From track parse: " << jsonM << endl;

            //     // track.track_name = jsonM.asString();
            //     // cout << "TRACK NAME IS" << track.track_name << endl;
            // }
            // for (int index = 0; index < root.size(); ++index)
            // {
            //     // cout << "Root: " << root[index].asString();
            // }
            // if (*i == "album")
            cout << "Size of Album: " << jsonM.size() << endl;
            for (int index = 0; index < jsonM["tracks"]["track"].size(); index++)
            {
                cout << "Current track: " << jsonM["tracks"]["track"][index] << endl;
            }

            cout << "This is from album class \n" + aJsonString << endl;
            return album;
        }
    }
}

void Album::addTrack(Track track)
{
    Album::tracks.push_back(track);
    // cout << "Track: " << track << "added" << endl;
    // cout << "Total Tracks: " << tracks << endl;
}

//Track Album::getTrack(Track track) {
//    track.getTrack();
//}