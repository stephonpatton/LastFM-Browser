#include "MediaLibrary.hpp"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <json/json.h>

using namespace std;
/**
 * Copyright 2020 Tim Lindquist,
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * Purpose: MediaLibrary is a class defining the interface between clients
 * and the server. The server implementation of MediaLibrary
 * provides storage for description of multiple media works -- song or video/clip.
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Tim Lindquist Tim.Lindquist@asu.edu
 *         Software Engineering, CIDSE, IAFSE, ASU Poly
 * @version January 2020
 */

std::string jsonString;
std::vector<Album> list;

MediaLibrary::MediaLibrary()
{
   initLibraryFromJsonFile("media.json");
}

MediaLibrary::~MediaLibrary()
{
   //cout << "MediaLibrary destructor.\n";
   media.clear();
}

void printAlbum(std::vector<Album> album)
{
   //TODO: Delete later?

   // for (vector<Album>::const_iterator i = album.begin(); i != album.end();)
   // {
   //    std::cout << *i << ' ';
   // }

   // std::copy(album.begin(), album.end(), std::ostream_iterator<std::string>(std::cout, " "));
}

bool MediaLibrary::addAlbumFromLastfmString(string jsonFileName, string jsonStringResult)
{
   Json::Reader reader;
   Json::Value root;

   jsonString = jsonStringResult;
   bool parseSuccess = reader.parse(jsonString, root, false);

   if (parseSuccess)
   {
      Json::Value wholeAlbum = root["album"];

      Album newAlbum = Album(wholeAlbum);

      list.push_back(newAlbum);
   }
}

void MediaLibrary::setLastFMString(string lastFM)
{
   jsonString = lastFM;
}

bool MediaLibrary::initLibraryFromJsonFile(string jsonFileName)
{
   bool ret = false;
   Json::Reader reader;
   Json::Value root;
   std::ifstream json(jsonFileName.c_str(), std::ifstream::binary);
   bool parseSuccess = reader.parse(json, root, false);
   if (parseSuccess)
   {
      Json::Value::Members mbr = root.getMemberNames();
      for (vector<string>::const_iterator i = mbr.begin(); i != mbr.end(); i++)
      {
         //cout << *i << " " << endl;
         Json::Value jsonMedia = root[*i];
         MediaDescription *aDesc = new MediaDescription(jsonMedia);
         media[*i] = *aDesc;
         cout << "adding ";
         aDesc->print();
      }
      ret = true;
   }
   return ret;
}

bool MediaLibrary::toJsonFile(string jsonFileName)
{
   bool ret = false;
   Json::Value jsonLib;
   for (std::map<string, MediaDescription>::iterator i = media.begin();
        i != media.end(); i++)
   {
      string key = i->first;
      cout << key << " " << endl;
      MediaDescription aMedia = media[key];
      Json::Value jsonMedia = aMedia.toJson();
      jsonLib[key] = jsonMedia;
   }
   Json::StyledStreamWriter ssw("  ");
   std::ofstream jsonOutFile(jsonFileName.c_str(), std::ofstream::binary);
   ssw.write(jsonOutFile, jsonLib);
   return true;
}

MediaDescription MediaLibrary::get(string aTitle)
{
   //cout << "get: " << aTitle << endl;
   MediaDescription aMedia = media[aTitle];
   return aMedia;
}

vector<string> MediaLibrary::getTitles()
{
   //cout << "getTitles: " << endl;
   vector<string> myVec;
   for (map<string, MediaDescription>::iterator it = media.begin();
        it != media.end(); ++it)
   {
      myVec.push_back(it->first);
      //cout << it->first << "\n";
   }
   return myVec;
}
