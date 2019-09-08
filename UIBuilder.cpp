/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "UIBuilder.hpp"

/******************************************************************************
 * Function to add the top of the screen
 ******************************************************************************/
void UIBuilder::startScreen() {
    screenString = topBotString + blankLine;
}

/******************************************************************************
 * Function to add blank lines to the display
 ******************************************************************************/
void UIBuilder::addBlankLines(int numToAdd) {
    for (int i = 0; i < numToAdd; ++i) {
        screenString += blankLine;
    }
}

/******************************************************************************
 * Function to finish the screen by adding the bottom lines and the border
 ******************************************************************************/
void UIBuilder::endString() {
    screenString += blankLine + blankLine + topBotString;
    addBorder(screenString);
}

/******************************************************************************
 * Function to build the top part of the display for most menus
 ******************************************************************************/
void UIBuilder::buildMenuHeader(std::string locationStr, int timeRemaining) {
    std::string tempStr = "";

    //start screen and add 1 extra blank line
    startScreen();
    addBlankLines(1);

    //build line that displays Location and time remaining
    screenString += lineStart;
    screenString += buildSubSection("Current location: " + locationStr, 51);
    screenString += "Time remaining: ";
    screenString += buildSubSection(std::to_string(timeRemaining), 3, false);
    screenString += lineEnd;

    //add blank lines
    addBlankLines(3);
}

/******************************************************************************
 * Function that builds a subsection of the current line given a string to add
 * and a length of the section. It also has a pair of optional boolean values to
 * adjust slignment options.
 ******************************************************************************/
std::string UIBuilder::buildSubSection(std::string sectionTxt, int subSectionMaxLength, bool leftAlign, bool isStrict) {
    std::string tempStr = "";

    //if string is longer than max length and the UI is strict return the passed string
    if(isStrict && sectionTxt.length() >= subSectionMaxLength) {
        return sectionTxt;
    } else if ((subSectionMaxLength - sectionTxt.length()) > 0){ //if passed string is shorter than max length

        //fill temp string with eoungh spaces to reach maximum
        tempStr.assign(subSectionMaxLength - sectionTxt.length(), ' ');
    }

    if(leftAlign) { //if left align
        tempStr = sectionTxt + tempStr; //align string to left
    } else { //otherwise
        tempStr = tempStr + sectionTxt; //align string to right
    }

    return tempStr; //return processed string
}

/******************************************************************************
 * Function to create a line from the passed string.
 ******************************************************************************/
std::string UIBuilder::fillLineContent(std::string contentStr) {
    return (lineStart + contentStr + lineEnd);
}

/******************************************************************************
 * Function to build the map display
 ******************************************************************************/
std::string UIBuilder::buildMap() {
    std::string mapStr =
            "                                                                                          \n"
            "                                                                                          \n"
            "     ____///|              ____///|                                           ____///|    \n"
            "    | Docs  |             |  DLs  |                                         /|  AI   |    \n"
            "    |_______|             |_______|          _______                       / |_______|    \n"
            "             \\           /                  | Thumb |                     /               \n"
            "              \\         /            /======| Drive |             ____///|    ____///|    \n"
            "               \\_______/            /       |_______|           /| Exper |===| Envir |    \n"
            "               | Root  |           /                           / |_______|   |_______|    \n"
            "               |  Exec |==========/                           /           \\               \n"
            "               |_______|                                     /             \\  ____///|    \n"
            "                  |                                         /               \\| Algo  |    \n"
            "                  |                                        /                 |_______|    \n"
            "                  |                                ____///|       ____///|                \n"
            "                  |                               |  Sys  |======|  OS   |                \n"
            "                  |                               |_______|      |_______|                \n"
            "                  |                              /         \\                  ____///|    \n"
            "                _______                         /           \\               /|  Net  |    \n"
            "               |       |                       /             \\             / |_______|    \n"
            "               |  Sec  |===\\                  /               \\           /               \n"
            "               |_______|    \\                /                 \\  ____///|                \n"
            "               /       \\     \\              /                   \\|  Util |                \n"
            "              /         \\     \\            /                     |_______|                \n"
            "             /           \\     \\______    /                               \\               \n"
            "     ____///|      ____///|    |       | /                                 \\  ____///|    \n"
            "    | Quar  |     | SecSW |    | Root  |/                                   \\|  SW   |    \n"
            "    |_______|     |_______|    |_______|                                     |_______|    \n"
            "                                                                                          \n"
            "                                                                                          \n"
            "                                                                                          \n";

    addBorder(mapStr);
    return mapStr;

}

/******************************************************************************
 * Function to add a randomly generated border to the screen
 ******************************************************************************/
void UIBuilder::addBorder(std::string &screenStr) {
    int options;

    if(*asciiInstalled) { //determine random range based on whether border is ascii or binary
        options = 16;
    } else {
        options = 2;
    }

    //fill first line of UI with random binary or hex characters
    for (int i = 0; i < 90; ++i) {

        int temp = (rand() % options) + 48; //raw ascii number

        if(temp > 57) { //adust if temp larger than ascii for '9'
            temp += 7;
        }

        //load character into string
        screenStr[i] = static_cast<char>(temp);
    }

    //add randomly generated character to beginning and end of line
    int startIndex = 91;
    for (int j = 0; j < 28; ++j) {
        int temp = (rand() % options) + 48;
        if(temp > 57) {
            temp += 7;
        }
        screenStr[startIndex] = static_cast<char>(temp);

        startIndex += 89;

        temp = (rand() % options) + 48;
        if(temp > 57) {
            temp += 7;
        }
        screenStr[startIndex] = static_cast<char>(temp);

        startIndex += 2;
    }

    //fill last line with randomly generated characters
    for (int k = startIndex; k < screenStr.length()-1; ++k) {
        int temp = (rand() % options) + 48;
        if(temp > 57) {
            temp += 7;
        }
        screenStr[k] = static_cast<char>(temp);
    }
}

/******************************************************************************
 * Function to build the main menu UI
 ******************************************************************************/
std::string UIBuilder::buildMainMenu(bool *addSections, std::string locationStr, int timeRemaining,
                                     std::string msgToPrint) {
    std::string tempStr = "";

    //build the top of the screen
    buildMenuHeader(locationStr, timeRemaining);

    //add variable number of blank lines depending on size of content
    addBlankLines(13 - integrateText(msgToPrint)); //build next section of text and calculate how many lines to add

    //add menu items to the display string
    for (int i = 0; i < 9; ++i) {
        if(i%3 == 0) { //ass spacer to start of line
            tempStr += "  ";
        }

        if(addSections[i+1]) { //build sections based on whether screen is to be displayed or not
            tempStr += buildSubSection(mainMenuOptions[i], mainMenuSectionLength);
        } else {
            tempStr += buildSubSection("", mainMenuSectionLength);
        }

        if((i + 1) % 3 == 0) { //add spacer to end of line build the line and add to UI string
            tempStr += "  ";
            screenString += fillLineContent(tempStr);
            addBlankLines(1);
            tempStr = "";
        }
    }

    tempStr = "  ";

    //add map option or blank if map available
    if(addSections[10]) {
        tempStr += buildSubSection(mainMenuOptions[9], 33);
    } else {
        tempStr += buildSubSection("", 33);
    }

    //add quit to menu
    if(addSections[0]) {
        tempStr += buildSubSection(mainMenuOptions[10] + "          ", 33, false);
    } else {
        tempStr += buildSubSection("", 33);
    }

    tempStr += "  ";
    screenString += fillLineContent(tempStr); //add last line

    //end the UI string
    endString();

    return screenString;
}

/******************************************************************************
 * Function to build the move menu
 ******************************************************************************/
std::string UIBuilder::buildMoveMenu(std::string *strings, std::string locationStr, int timeRemaining) {
    std::string tempStr = "";

    //build header and add blank lines
    buildMenuHeader(locationStr, timeRemaining);
    addBlankLines(13);

    //build lines for the movement option, add option it the move is available
    for (int i = 0; i < 6; ++i) {
        tempStr += buildSubSection(strings[i], 35);

        if((i + 1) % 2 == 0) {
            screenString += fillLineContent(tempStr);
            addBlankLines(1);
            tempStr = "";
        }
    }

    //add cancel option
    tempStr = buildSubSection("0. Return to previous Menu", 48);
    tempStr = buildSubSection(tempStr, 70, false);
    screenString += fillLineContent(tempStr);

    //end UI string
    endString();

    return screenString;
}



/******************************************************************************
 * Function to build a display window for the intro and ending.
 ******************************************************************************/
std::string UIBuilder::buildTextWindow(std::string textToDisplay) {
    std::string tempStr;
    screenString = "";

    //develop string for middle of UI and calculate spacing
    int numLines = integrateText(textToDisplay);
    int numBlankBufferLines = 24 - numLines;
    numBlankBufferLines /= 2;

    //save created string
    tempStr = screenString;

    //build UI
    startScreen();
    addBlankLines(1 + numBlankBufferLines);
    screenString += tempStr;
    addBlankLines(24-(numBlankBufferLines+numLines));
    endString();

    return screenString;
}

/******************************************************************************
 * Function to build screen for the end of the game
 ******************************************************************************/
std::string UIBuilder::buildEndGameScreen(std::string msgPartOne, bool isVictory, std::string msgPartTwo) {
    std::string tempStrOne, tempStrTwo, tempStrThree;
    screenString = "";

    int numLines = integrateText(msgPartOne);
    tempStrOne = screenString;
    screenString = "";

    numLines += integrateText(msgPartTwo);
    tempStrTwo = screenString;
    screenString = "";



    if(isVictory) {
        numLines += integrateText("                               YOU WIN!");
    }else {
        numLines += integrateText("                               GAME OVER");
    }

    tempStrThree = screenString;
    screenString = "";

    //Build screen by joining the strings created so far
    startScreen();
    screenString += tempStrOne;
    addBlankLines(1);
    screenString += tempStrTwo;
    addBlankLines(1);
    screenString += tempStrThree;
    addBlankLines(23-numLines);
    endString();

    return screenString;
}

/******************************************************************************
 * Function to build a line by adding the start, end and building the content
 * int the middle;
 ******************************************************************************/
void UIBuilder::buildLine(std::string lineContent) {
    screenString += lineStart;
    screenString += buildSubSection(lineContent, 70);
    screenString += lineEnd;
}

/******************************************************************************
 * Function to parse text for entry into a line to prevent words from being
 * broken
 ******************************************************************************/
int UIBuilder::integrateText(std::string textToIntegrate) {
    std::string tempStr = "";

    int numBlank = 13;
    int msgToPrintLength = textToIntegrate.length(), msgLines = 0;

    int totalCharIndex = 0, currentCharIndex;


    std::string subStr;
    if(msgToPrintLength > 0) { //if message is not empty

        while (msgToPrintLength > 0) { //while there are still characters left to process

            if(textToIntegrate.length() >= 70) { //if there is more than one section of text
                //create substring of appropriate size
                subStr = textToIntegrate.substr(totalCharIndex, 70);
                totalCharIndex += 69;
                currentCharIndex = 69;
            } else {
                //store text in string
                subStr = textToIntegrate;
                totalCharIndex = subStr.size() - 1;
                currentCharIndex = totalCharIndex+1;
            }

            //while the last character isn't a space drop the last character and update position tracking vars
            while (subStr[currentCharIndex] != ' ' && currentCharIndex < msgToPrintLength) {
                subStr = subStr.substr(0, subStr.length()-1);
                currentCharIndex--;
                totalCharIndex--;
            }

            //increment start index to avoid repeated prints
            totalCharIndex++;

            //add parsed string to UI string
            tempStr = buildSubSection(subStr, 70);
            screenString += lineStart + tempStr + lineEnd;
            msgLines++;
            msgToPrintLength -= subStr.length();
        }
    }

    return msgLines;
}

/******************************************************************************
 * Function to build a list menu from a vector of items available
 ******************************************************************************/
std::string UIBuilder::buildGenericListMenu(std::string menuDesc, std::vector<std::string> *menuItems,
                                            std::string locationStr, int timeRemaining) {
    std::string tempStr;
    int numBlank = 19 - menuItems->size();


    buildMenuHeader(locationStr, timeRemaining);

    numBlank -= integrateText(menuDesc);

    //for each item build a line
    for (int i = 0; i < menuItems->size(); ++i) {
        buildLine((*menuItems)[i]);
    }


    if(numBlank > 0) {
        addBlankLines(numBlank);
    }

    buildLine("0. Return to previous menu.");
    endString();

    return screenString;
}

/******************************************************************************
 * Function to build the Logo screen
 ******************************************************************************/
std::string UIBuilder::buildLogo() {
    int switchNum;
    screenString = "";
    bool borderCharacter;

    //fill screen with randomized hex of binary with increasing odds of closer to the lower right
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j <90; ++j) {
            borderCharacter = i == 0;
            borderCharacter = borderCharacter || i == 29;
            borderCharacter = borderCharacter || j == 0;
            borderCharacter = borderCharacter || j == 89;

            if(borderCharacter) {

                screenString += '*';
            } else if((rand() % (((30-i)*(90-j))+1)) > 300) {
                switchNum = rand() % 2;
            } else {
                switchNum = rand() % 16;
            }
            if(!borderCharacter) {
                if (j==38) {
                    if (i == 13) { //if middle print title in cyan
                        //https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal

                        screenString += "\033[1;36m    the    \033[0m";

                        j += 10;
                    } else if (i == 14) { //if middle print title in cyan

                        //https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
                        screenString += "\033[1;36m awakening \033[0m";
                        j += 10;
                    } else if (i == 12 || i == 15){ //print blank space around title
                        screenString += "           ";
                        j += 10;
                    } else {
                        screenString += getHexChar(switchNum);
                    }
                } else {
                    screenString += getHexChar(switchNum);
                }
            }
        }
        screenString += "\n";

    }

    return screenString;
}

/******************************************************************************
 * Function to convert a numeric value to a hex character
 ******************************************************************************/
char UIBuilder::getHexChar(int numToHexify) {
    switch(numToHexify) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
    }

}

/******************************************************************************
 * Function to link the object to a variable in the player class. This allows
 * the border to change from binary to ascii upon installation of the ASCII
 * table.
 ******************************************************************************/
void UIBuilder::linkASCIIBool(bool *asciiInstalled) {
    this->asciiInstalled = asciiInstalled;
}