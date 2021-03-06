/*
 * CommandLine.cpp
 *
 *  Created on: Mar 27, 2019
 *      Author: neg6
 */

#include "CommandLine.h"

/** CommandLine
 *
 */
CommandLine::CommandLine(istream& in) {
	ampersand = false;

	cout << "Waiting for input" << endl;
	getline(in, myCommandLine);
	cout << "The command line is: " << myCommandLine << endl;
	istringstream iss(myCommandLine);
	vector<string> tempArgv;
	for (string s; iss >> s; ) {
		tempArgv.push_back(s);
		myArgc += 1;
	}


	// Converts input from a string into a StringStream
	// Reads each character individually from SS
	// Uses calloc() to allocate appropriate amount of space
	istringstream iss2(myCommandLine);
	char* argv[255];
	bool breakout = false;
	char space = ' ';
	char newLine = '\n';
	for (int i = 0; i < myArgc; i++) {
		char *temp = (char*) calloc(255, sizeof(char));
		int j = 0;
		while(true) {
			char singleChar;
			iss2.get(singleChar);
			if (singleChar == space) {
				temp[j] = '\0';
				break;
			} else if (singleChar == newLine || iss2.eof()) {
				temp[j] = '\0';
				breakout = true;
				break;
			} else if (singleChar == '&') {
				ampersand = true;
			}
			temp[j] = singleChar;
			j++;
		}
		argv[i] = temp;
		cout << argv[i] << endl;
		if (breakout) { break; }
	}

	myArgv = (char**) argv;
}
