/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_UIBUILDER_HPP
#define CS162_UIBUILDER_HPP

#include <string>
#include <iostream>
#include <vector>

#include "Constants.hpp"

/*********************************************************************
 * Class UIBuilder
 *
 * This class builds the UI for the menus and other displays printed
 * to the screen
 *********************************************************************/
class UIBuilder {
private:
    std::string screenString;
    bool* asciiInstalled;

    void startScreen();
    void endString();
    void addBlankLines(int numToAdd);

    std::string buildSubSection(std::string sectionTxt, int subSectionMaxLength, bool leftAlign = true,
                                bool isStrict = false);
    void buildMenuHeader(std::string locationStr, int timeRemaining);
    void buildLine(std::string lineContent);
    int integrateText(std::string);
    char getHexChar(int numToHexify);
public:
    void addBorder(std::string &screenStr);
    std::string buildMap();
    std::string fillLineContent(std::string contentStr);
    std::string buildMainMenu(bool *addSections, std::string locationStr, int timeRemaining, std::string msgToPrint);
    std::string buildMoveMenu(std::string *strings, std::string locationStr, int timeRemaining);
    std::string buildGenericListMenu(std::string menuDesc, std::vector<std::string> *menuItems, std::string locationStr,
                                     int timeRemaining);
    std::string buildTextWindow(std::string textToDisplay);
    std::string buildLogo();
    std::string buildEndGameScreen(std::string msgPartOne, bool isVictory, std::string msgPartTwo = "");
    void linkASCIIBool(bool *asciiInstalled);
};


#endif //CS162_UIBUILDER_HPP
