/*
 * TileMapRapidJsonParser.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: lalo
 */

#include "TileMapRapidJsonParser.h"
#include "rapidjson/document.h"

TileMapRapidJsonParser::TileMapRapidJsonParser(FileUtils& fileUtils) : mFileUtils(fileUtils) {
}

TileMapRapidJsonParser::~TileMapRapidJsonParser()
{
	// TODO Auto-generated destructor stub
}

TileMapData TileMapRapidJsonParser::parse(std::string& filePath) {

	std::string unparsedJson = this->mFileUtils.readFileToString(filePath);
	rapidjson::Document document;
	document.Parse(unparsedJson.c_str());

	TileMapData data;
	return data;
}

