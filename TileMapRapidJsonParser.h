/*
 * TileMapRapidJsonParser.h
 *
 *  Created on: Jun 2, 2018
 *      Author: lalo
 */

#ifndef TILEMAPRAPIDJSONPARSER_H_
#define TILEMAPRAPIDJSONPARSER_H_

#include "TileMapJsonParser.h"
#include "FileUtils.h"

class TileMapRapidJsonParser: TileMapJsonParser {
public:
	TileMapRapidJsonParser(FileUtils& fileUtils);
	virtual ~TileMapRapidJsonParser();

	TileMapData parse(std::string& filePath);

private:
	FileUtils& mFileUtils;
};

#endif /* TILEMAPRAPIDJSONPARSER_H_ */
