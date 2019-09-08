/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "MessageProcessor.hpp"


/******************************************************************************
 * Function to evaluate if a string needs to be converted to hexadecimal and
 * then returns the converted or unmodified string as appropriate.
 ******************************************************************************/
std::string MessageProcessor::print(std::string strToPrint, bool printActual) {
    if(!printActual && !(*asciiTableInstalled)) {
        strToPrint = strToHex(strToPrint);
    }

    return strToPrint;
}

/******************************************************************************
 * Function to convert a string to a hexadecimal representation of the same
 * string
 ******************************************************************************/
std::string MessageProcessor::strToHex(std::string strToConvert) {
    std::string convertedString = "";
    int rawASCII, chars[2];

    for (int i = 0; i < strToConvert.length(); ++i) { //for each character in the string

        rawASCII = static_cast<int>(strToConvert[i]); //get the integer representation of the ascii

        chars[0] = rawASCII/16; //store first half of  hex in decimal
        chars[1] = rawASCII%16; //store second half of hex in decimal

        for (int j = 0; j < 2; ++j) {//loop through the 2 hex values and add appropriate character to the string
            switch(chars[j]) {
                case 0: convertedString += "0";
                    break;
                case 1: convertedString += "1";
                    break;
                case 2: convertedString += "2";
                    break;
                case 3: convertedString += "3";
                    break;
                case 4: convertedString += "4";
                    break;
                case 5: convertedString += "5";
                    break;
                case 6: convertedString += "6";
                    break;
                case 7: convertedString += "7";
                    break;
                case 8: convertedString += "8";
                    break;
                case 9: convertedString += "9";
                    break;
                case 10: convertedString += "A";
                    break;
                case 11: convertedString += "B";
                    break;
                case 12: convertedString += "C";
                    break;
                case 13: convertedString += "D";
                    break;
                case 14: convertedString += "E";
                    break;
                case 15: convertedString += "F";
                    break;
            }

        }
        convertedString += " "; //add a space after each pair of characters
    }

    //return converted string
    return convertedString;
}

/******************************************************************************
 * Function (deprecated) to flip the ASCII table from installed to uninstalled
 * and vise versa
 ******************************************************************************/
void MessageProcessor::flipTable() {
    *asciiTableInstalled = *asciiTableInstalled ^ 1;
}

/******************************************************************************
 * Function to link the member variable for the ascii table in this class to the
 * state of the corresponding variable in the character class
 ******************************************************************************/
void MessageProcessor::linkASCIIboolean(bool *ASCIITableInstalled) {
    asciiTableInstalled = ASCIITableInstalled;
}