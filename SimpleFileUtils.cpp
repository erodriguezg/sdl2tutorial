/*
 * SimpleFileUtils.cpp
 *
 *  Created on: May 30, 2018
 *      Author: lalo
 */

#include "SimpleFileUtils.h"
#include <fstream>
#include <streambuf>

SimpleFileUtils::SimpleFileUtils()
{
}

SimpleFileUtils::~SimpleFileUtils()
{
}


std::string SimpleFileUtils::readFileToString(const std::string& relativeFilePath){
	std::ifstream file(relativeFilePath);
	std::string str((std::istreambuf_iterator<char>(file)),
	                 std::istreambuf_iterator<char>());
	return str;
}
