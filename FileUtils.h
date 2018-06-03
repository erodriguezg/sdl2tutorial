/*
 * FileUtils.h
 *
 *  Created on: May 30, 2018
 *      Author: lalo
 */

#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <iostream>
#include <string>

class FileUtils {

public:

	FileUtils() {};
	virtual ~FileUtils(){};
	virtual std::string readFileToString(const std::string& relativeFilePath) = 0;

};

#endif /* FILEUTILS_H_ */
