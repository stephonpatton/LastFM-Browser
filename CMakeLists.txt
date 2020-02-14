cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
include(LibFindMacros)
include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)
find_package(Jsoncpp)
find_package(Threads REQUIRED)
find_package(FLTK REQUIRED)

include_directories(${FLTK_INCLUDE_DIRS})
include_directories(${Jsoncpp_INCLUDE_DIR})
include_directories(src/sample/)
add_executable(untitled src/sample/samplemain.cpp src/sample/MediaClientGui.cpp src/sample/MediaDescription.cpp src/sample/MediaLibrary.cpp src/sample/Album.cpp src/sample/Album.hpp src/sample/Track.cpp src/sample/Track.hpp src/sample/MusicLibrary.cpp src/sample/MusicLibrary.hpp src/sample/main.cpp src/sample/main.h)
target_link_libraries(untitled ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(untitled ${CURLPP_LDFLAGS})
target_link_libraries(untitled ${Jsoncpp_LIBRARY})
target_link_libraries(untitled fltk)
target_link_libraries(untitled fltk_images)



#//TODO: Change later
add_custom_command(
        TARGET untitled POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/config.ini
        ${CMAKE_CURRENT_BINARY_DIR})

link_directories(/usr/local/pgsql/lib/)
message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
message("C Flags = ${CMAKE_CXX_FLAGS_DEBUG}")