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
 * Purpose: Sample C++ FLTK view class. MusicLibrary handles the library for the applciation
 * by adding and removing from a jsonfile file.
 * This software is meant to run on Debian Wheezy Linux
 * <p/>
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Stephon Patton & Tim Lindquist (spatton6@asu.edu)
 * @file    MusicLibrary.cpp
 * @date    January, 2020
 **/

#include "MusicLibrary.hpp"
#include <stdlib.h>

using namespace std;

MusicLibrary::MusicLibrary()
{
}

string getAlbumNames()
{
    return "";
}

Album getAlbum(string title)
{
    Album album = Album();
    return album;
}

void addAlbum(string lastFMstring)
{
}

void removeAlbum(string removeAlbum)
{
}

void saveLibraryToFile()
{
}

void restoreLibraryFromFile()
{
}