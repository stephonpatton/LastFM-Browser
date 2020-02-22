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
 * @file    Track.hpp
 * @date    January, 2020
 **/

#ifndef UNTITLED_TRACK_HPP
#define UNTITLED_TRACK_HPP

#include <iostream>
#include <vector>
//#include "samplemain.cpp"

using namespace std;

class Track
{
public:
    // vector<std::string> tracks;
    Track();
    Track parseLastFMJson(std::string aJsonString);

    std::string track_name;
    std::string artist;
    int rank;
    std::string duration;
    std::string file_name;

    // vector<std::string> &getTrack();
    // void setKey(std::string key);
};

#endif //UNTITLED_TRACK_HPP
