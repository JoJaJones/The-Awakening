/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "DownloadFolder.hpp"
/******************************************************************************
 * Constructor for the DownloadFolder class
 ******************************************************************************/
DownloadFolder::DownloadFolder(std::string spaceName, std::string dirText, MessageProcessor *printer)
               : Space(spaceName, dirText, printer) {

}

/******************************************************************************
 * Function to trigger special action on player entry to the space. It simply
 * results in a message display.
 ******************************************************************************/
bool DownloadFolder::activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining,
                                   int &tempTimeRemaining,
                                   std::string &spaceMsg) {
    std::string message = "This folder is full of porn, viruses and malware. It's probably best to not linger here.";
    spaceMsg = processor->print(message);
    playerData.visitedDownloads = true;
    return true;
}