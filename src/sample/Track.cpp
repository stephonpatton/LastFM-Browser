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
    
    return track;
}

vector<std::string> const &getTrack()
{
}
