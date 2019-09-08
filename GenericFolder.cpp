/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "GenericFolder.hpp"

/******************************************************************************
 * Constructor for the GenericFolder class
 ******************************************************************************/
GenericFolder::GenericFolder(std::string spaceName, std::string dirText, MessageProcessor *printer)
              : Space(spaceName, dirText, printer) {

}

/******************************************************************************
 * Function to activateSpace. Does nothing.
 ******************************************************************************/
bool GenericFolder::activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining,
                                    int &tempTimeRemaining, std::string &spaceMsg) {
    return true;
}