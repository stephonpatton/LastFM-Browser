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
 * Purpose: Sample C++ FLTK view class. Track handles the tracks in the application.
 * Contains functions to add, remove, and look up tracks in a library.
 * This software is meant to run on Debian Wheezy Linux
 * <p/>
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Stephon Patton & Tim Lindquist (spatton6@asu.edu)
 * @file    Track.cpp
 * @date    January, 2020
 **/

#include <iostream>
#include <vector>
#include "Track.hpp"

using namespace std;

Track::Track()
{
    track_name = "";
    artist = "";
    rank = 0;
    duration = "";
    file_name = "";
}

Track Track::parseLastFMJson(string aJsonString)
{
    Track track = Track();
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
            cout << "Size of root: " << jsonM.size() << endl;
            for (int index = 0; index < jsonM["tracks"]["track"].size(); index++)
            {
                cout << "Current jsonM: " << jsonM["tracks"]["track"][index] << endl;
            }
            if (*i == "album")
            {
                cout << "Success!" << endl;
                // cout << "Tracks: " << jsonM << endl;
            }
            else if (*i == "tracks")
            {
                cout << "Tracks: " << jsonM.asString() << endl;
            }
            // if (*i == "album")
            // {
            //     cout << "Tracks : " << *i << endl;
            // }
            else
            {
                cout << "No tracks" << endl;
            }

            if (jsonM["tracks"]["track"] == "name")
            {
                cout << "HELLO" << endl;
                cout << "Tracks: " << jsonM["tracks"][0] << endl;
            }
            // cout << "current jsonM : " << jsonM.asString() << endl;

            // cout << "From track parse: " << jsonM << endl;
        }
    }
    else
    {
        cout << "Failed to parse JSON " << reader.getFormatedErrorMessages();
    }

    return track;
}

vector<std::string> const &getTrack()
{
}
