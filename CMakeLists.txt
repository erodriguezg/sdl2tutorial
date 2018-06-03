cmake_minimum_required(VERSION 3.5.1)
project(sdl2tutorial)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake-modules/")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SUB_SOURCES)
add_executable(sdl2tutorial ${SUB_SOURCES})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer 2.0.1 REQUIRED)

set(RAPIDJSON_INCLUDE_DIR "$ENV{RAPIDJSON_SOURCE_DIR}/include")

message(STATUS "RAPID_JSON_INCLUDE_DIR: ${RAPIDJSON_INCLUDE_DIR}")

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${RAPIDJSON_INCLUDE_DIR})

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES_FIX)
target_link_libraries(sdl2tutorial ${SDL2_LIBRARIES_FIX} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY})

#copy resources
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})