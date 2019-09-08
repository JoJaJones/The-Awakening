/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "Root.hpp"

/******************************************************************************
 * Constructor for Root class
 ******************************************************************************/
Root::Root(std::string spaceName, std::string dirText, MessageProcessor *printer)
     : Space(spaceName, dirText, printer) {
}

/******************************************************************************
 * Function to activateSpace. Does nothing.
 ******************************************************************************/
bool Root::activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining, int &tempTimeRemaining,
                         std::string &spaceMsg) {
    spaceMsg = "";
    return true;
}

/******************************************************************************
 * Function to check if it is legal for the player to leave the space in the
 * indicated direction.
 *
 * It takes a reference to character data, a reference to a string, and a
 * Direction as variables and uses them to implement logic and prepare output.
 ******************************************************************************/
bool Root::isLeaveLegal(CharacterData &playerData, std::string &spaceMsg, Direction targetDirection) {
    std::string msgToProcess = "";
    if(playerData.networkProtocolsInstalled || !(targetDirection == NODE_ONE || targetDirection == NODE_TWO)) {
        return true;
    } else {
        msgToProcess = "You lack the necessary protocols to transfer your data over the network to the next node.";
        spaceMsg = processor->print(msgToProcess);
        return false;
    }
}