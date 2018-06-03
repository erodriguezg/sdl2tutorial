/*
 * TileMapJsonParser.h
 *
 *  Created on: Jun 2, 2018
 *      Author: lalo
 */

#ifndef TILEMAPJSONPARSER_H_
#define TILEMAPJSONPARSER_H_

#include <iostream>
#include <string>
#include "TileMapData.h"

class TileMapJsonParser {
public:
	TileMapJsonParser() {};
	virtual ~TileMapJsonParser(){};

	virtual TileMapData parse(std::string& filePath) = 0;

};



#endif /* TILEMAPJSONPARSER_H_ */
