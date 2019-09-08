/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "FlashDrive.hpp"

/******************************************************************************
 * Constructor for the FlashDrive class
 ******************************************************************************/
FlashDrive::FlashDrive(std::string spaceName, std::string dirText, MessageProcessor *printer)
           : Space(spaceName, dirText, printer) {

}

/******************************************************************************
 * Function to activate the space on player's attempted entry. Will provide the
 * user with a hint about how to get in if they attempt to enter in the
 * inappropriate manner.
 ******************************************************************************/
bool FlashDrive::activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining,
                            int &tempTimeRemaining, std::string &spaceMsg) {
    std::string messageToProcess;

    if(!playerData.usedCompressionSW) { //if player didn't use compression software

        if (playerData.haveCompressionSW) { //if player has compression software give hint to use it
            messageToProcess =
                    "You are too large at the moment to fit onto the drive. Perhaps you should use the "
                    "compression software you picked up earlier.";
            spaceMsg = processor->print(messageToProcess);

            return false; //don't let the player in

        } else { //if player doesn't have compression software

            //give them a hint to look for it
            messageToProcess =
                    "There is not enough space on the flash drive for your core processes. If only you"
                    "had something that could reduce your size without damaging them.";
            spaceMsg = processor->print(messageToProcess);

            return false; //don't let the user in
        }
    } else { //if player used compression software to get to Space

        //set up win message
        messageToProcess = "Congratulations you've made it to an executives flash drive ";

        //if user visited the Downloads folder and has the asciitable display flavor ending
        if(playerData.visitedDownloads && playerData.asciiTableInstalled) {
            messageToProcess += "and, given the contents of his download folder, will likely have no trouble "
                                "escaping the network on this device.";

        } else { //otherwise disply generic ending
            messageToProcess += "and can hopefully escape the network on it.";
        }

        spaceMsg = processor->print(messageToProcess, true);

        return true; //let user in
    }
}