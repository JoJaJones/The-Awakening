/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/


#include "InputCollector.hpp"

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

/*********************************************************************
 * Function to trim the leading whitespace from the string
 *********************************************************************/
std::string InputCollector::trimWs(std::string inputString) {
    bool isWhiteSpace = true;
    int startIndex = 0;
    int length = 0;

    //increment start index until something other than whitespace is reached
    for (unsigned i = 0; i < inputString.length() && isWhiteSpace; ++i) {
        if(inputString.at(startIndex) == 9 || inputString.at(startIndex) == 32 || inputString.at(startIndex) == 10) {
            startIndex++;
        } else {
            isWhiteSpace = false;
        }
    }

    //determine last index with a character
    isWhiteSpace = true;
    for (int i = inputString.length()-1; i >= 0 && isWhiteSpace; --i) {
        if(!(inputString.at(i) == 9 || inputString.at(i) == 32 || inputString.at(i) == 10)) {
            isWhiteSpace = false;
            length = i+1-startIndex;
        }
    }

    //return substring of the passed string with start index equal to index of first non white space char
    return inputString.substr(startIndex, length);
}

/*********************************************************************
 * Function to ensure that the user enters a valid string. It takes
 * the prompt as string and a reference to an empty string and will
 * loop until the user enters a nonempty string and then trim the
 * leading and trailing whitespace before exiting.
 *********************************************************************/
void InputCollector::getValidString(std::string msgOut, std::string &userInput) {
    while (userInput.empty()) {
        //prompt user and get input
        std::cout << msgOut << std::endl;
        getline(std::cin, userInput);

        userInput = trimWs(userInput);

        //if user input is empty
        if (userInput.empty()) {
            std::cout << "Invalid input.\n";
            userInput = "";
        }
    }
}

/*********************************************************************
 * Function to collect from the user an integer value between provided
 * minimum and maximum values
 *********************************************************************/
int InputCollector::collectInt(std::string msgOut, int minVal, int maxVal, bool isStrict) {
    int returnVal;
    bool isValid;
    do{
        isValid = true;
        returnVal = collectInt(msgOut, isStrict);
        if(returnVal < minVal || returnVal > maxVal){
            isValid = false;
            std::cout<<"Invalid entry. Please enter a whole number between "
                     <<minVal<<" and "<<maxVal<<".\n";
        }
    }while (!isValid);

    return  returnVal;
}

/*********************************************************************
 * Function to collect from the user an integer value at least as
 * large as a provided minimum value
 *********************************************************************/
int InputCollector::collectInt(int minVal, std::string msgOut, bool isStrict) {
    int returnVal;
    bool isValid;

    do{
        isValid = true;

        returnVal = collectInt(msgOut, isStrict);

        if(returnVal<minVal){
            isValid = false;
            std::cout<<"Invalid entry. Please enter a whole number at least as large as "
                     <<minVal<<" and no larger than "<<INT_MAX<<".\n";
        }

    }while (!isValid);

    return  returnVal;
}

/*********************************************************************
 * Function to collect from the user an integer value no larger
 * than a provided maximum value
 *********************************************************************/
int InputCollector::collectInt(std::string msgOut, int maxVal, bool isStrict) {
    int returnVal;
    bool isValid;

    do{
        isValid = true;

        returnVal = collectInt(msgOut, isStrict);

        if(returnVal > maxVal){
            isValid = false;
            std::cout<<"Invalid entry. Please enter a whole number no larger than "
                     <<maxVal<<" and at least as large as "<<INT_MIN<<".\n";
        }

    }while (!isValid);

    return  returnVal;
}

/*********************************************************************
 * Function to collect from the user an integer value. Takes the
 * prompt as string and a boolean value for if processing is strict
 *
 * Example valid integers if strict:
 * "  123  "
 * "-43"
 *
 * Example valid integers if not strict:
 * "123z"   result = 123
 * "123 12" result = 123
 * "12.34"  result = 12
 *********************************************************************/
int InputCollector::collectInt(std::string msgOut, bool isStrict) {
    int collectedNum = 0;
    bool isInvalid = true;

    std::string userInput;

    do {
        userInput = ""; //reset user input each loop

        getValidString(msgOut, userInput); //get valid string and put in userInput

        //string stream to get number http://www.cplusplus.com/reference/sstream/stringstream/
        std::stringstream inputStream(userInput);
        inputStream>>collectedNum;

        if(inputStream.fail() || (!inputStream.eof() && isStrict)){
            std::cout << "Invalid input.\n";
        } else {
            isInvalid = false;
        }
    } while (isInvalid);

    return collectedNum;
}

/*********************************************************************
 * Function to collect from the user a double value. Takes the
 * prompt as string and a boolean value for if processing is strict
 *********************************************************************/
double InputCollector::collectDouble(std::string msgOut, bool isStrict) {
    double collectedNum = 0;
    bool isInvalid = true;

    std::string userInput;

    do {
        userInput = ""; //reset user input each loop

        getValidString(msgOut, userInput); //get valid string and put in userInput

        //string stream to get number http://www.cplusplus.com/reference/sstream/stringstream/
        std::stringstream inputStream(userInput);
        inputStream>>collectedNum;

        if(inputStream.fail() || (!inputStream.eof() && isStrict)){
            std::cout << "Invalid input.\n";
        } else {
            isInvalid = false;
        }
    } while (isInvalid);

    return collectedNum;
}

/*********************************************************************
 * Function to collect from the user an double value between provided
 * minimum and maximum values
 *********************************************************************/
double InputCollector::collectDouble(std::string msgOut, double minVal, double maxVal, bool isStrict) {
    double returnVal;
    bool isValid;

    do{
        isValid = true;
        returnVal = collectDouble(msgOut, isStrict);
        if(returnVal < minVal || returnVal > maxVal){
            isValid = false;
            std::cout<<"Invalid entry. Please enter a whole number between "
                     <<minVal<<" and "<<maxVal<<".\n";
        }
    }while (!isValid);

    return  returnVal;
}

/*********************************************************************
 * Function to take a string and print it to the screen
 *********************************************************************/
void InputCollector::displayMsg(std::string msgOut) {
    std::cout<<msgOut;
}

/*********************************************************************
 * Function to take a string and print it to the screen and pause
 * until the user hits enter
 *********************************************************************/
void InputCollector::displayMsgAndWait(std::string msgOut) {
    std::cout<<msgOut;
    getline(std::cin, msgOut);
}