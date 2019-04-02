/*
 * CommandLine.h
 *
 *  Created on: Mar 27, 2019
 *      Author: neg6
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <istream>
using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	char* getCommand() const { return myArgv[0]; }
	int getArgCount() const { return myArgc; }
	char** getArgVector() const { return myArgv; }
	char* getArgVector(int i) const { return myArgv[i]; }
	bool noAmpersand() const { return !ampersand; }

private:
	string myCommandLine;
	int myArgc = 0;
	char** myArgv;
	bool ampersand;
};

#endif /* COMMANDLINE_H_ */
