/*
 * SimpleFileUtils.h
 *
 *  Created on: May 30, 2018
 *      Author: lalo
 */

#ifndef SIMPLEFILEUTILS_H_
#define SIMPLEFILEUTILS_H_

#include "FileUtils.h"

class SimpleFileUtils: FileUtils {
public:
	SimpleFileUtils();
	~SimpleFileUtils();

	std::string readFileToString(const std::string& relativeFilePath);

};

#endif /* SIMPLEFILEUTILS_H_ */
