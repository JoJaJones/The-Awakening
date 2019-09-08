/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef INPUT_COLLECTOR_HPP
#define INPUT_COLLECTOR_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <sstream>

/*********************************************************************
 * Class to validate or sanitize input from the user into a usable
 * format
 *
 * Includes an optional bool to allow for flexibility when parsing
 *  - if true only accepts numbers that are followed by whitespace or
 *          the end of the string
 *  - if false returns the number as processed prior to the invalid character
 *
 * Useful functions:
 *  - collectInt
 *      - int with min val call with: int min, string prompt, bool strict
 *      - int with max val call with: string prompt, int max, bool strict
 *      - int in range call with: string prompt, int min, int max, bool strict
 *
 *********************************************************************/
class InputCollector {
public:
    std::string trimWs(std::string inputString);

public:
    int collectInt(std::string msgOut, bool isStrict = false);
    int collectInt(std::string msgOut, int minVal, int maxVal, bool isStrict = false);
    int collectInt(std::string msgOut, int maxVal, bool isStrict = false);
    int collectInt(int minVal, std::string msgOut, bool isStrict = false);
    double collectDouble(std::string msgOut, bool isStrict = false);
    double collectDouble(std::string msgOut, double minVal, double maxVal, bool isStrict = false);
    void getValidString(std::string msgOut, std::string &userInput);

    void displayMsg(std::string msgOut);
    void displayMsgAndWait(std::string msgOut);
//	long collectLong(std::string msgOut, bool isStrict = false);
//	float collectFloat(std::string msgOut, bool isStrict = false);
//	unsigned collectUnsigned(std::string msgOut, bool isStrict = false);
//	char collectChar(std::string msgOut, bool isStrict = false);
//	std::string collectString(std::string msgOut, bool isStrict = false);
};

#endif