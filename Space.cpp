/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "Space.hpp"

/******************************************************************************
 * Space Constructor
 ******************************************************************************/
Space::Space(std::string spaceName, std::string dirText, MessageProcessor *printer) {
    this->dirText = dirText;
    this->spaceName = spaceName;
    searchActive = false;
    this->processor = printer;

    parentDirectory = nullptr;
    for (int i = 0; i < 3; ++i) {
        subDirectory[i] = nullptr;
    }

    for (int j = 0; j < 2; ++j) {
        terminalNode[j] = nullptr;
    }
}

/******************************************************************************
 * Destructor for the Space class. It loops through the vectors of items and
 * deletes any items located there.
 ******************************************************************************/
Space::~Space() {
    for (int i = 0; i < availableItems.size(); ++i) {
        delete availableItems[i];
    }

    for (int j = 0; j < collectedItems.size(); ++j) {
        delete collectedItems[j];
    }
}

/******************************************************************************
 * Function to set the node pointer representing the next computer in the
 * network. It takes a pointer to a Space and an index to determine which
 * pointer to link that space to. If passed an index of 0 it will then call
 * the same function in the other node causing the Spaces to be linked to
 * each other
 ******************************************************************************/
void Space::setNextNode(Space *nextTerminalSpace, int dirIndex) {
    this->terminalNode[dirIndex] = nextTerminalSpace;

    if(dirIndex == 0) {
        nextTerminalSpace->setNextNode(this, 1);
    }
}

/******************************************************************************
 * Function to set the node pointer representing the subdirectory in the
 * network. It takes a pointer to a Space and an index to determine which
 * pointer to link that space to. This function will then call the setParent
 * function in the newly connected Space to link the two spaces together
 ******************************************************************************/
void Space::setSubDir(Space *subDirSpace, int dirIndex) {
    this->subDirectory[dirIndex] = subDirSpace;
    subDirSpace->setParent(this);
}

/******************************************************************************
 * Function to link a space to the current Space's parent pointer.
 *
 * NOTE: this function is called automatically by the setSubDir function
 ******************************************************************************/
void Space::setParent(Space *parentSpace) {
    this->parentDirectory = parentSpace;
}

/******************************************************************************
 * Function that returns the value pointed to by the pointer in the direction
 * indicated by the passed Direction value.
 ******************************************************************************/
Space* Space::getConnectedSpace(Direction checkDirection) {
    switch(checkDirection) {
        case PARENT:
            return parentDirectory;
        case SUB_ONE:
            return subDirectory[0];
        case SUB_TWO:
            return subDirectory[1];
        case SUB_THREE:
            return subDirectory[2];
        case NODE_ONE:
            return terminalNode[0];
        case NODE_TWO:
            return terminalNode[1];
    }
}

/******************************************************************************
 * Function to move the player character to a new Space
 *
 * For parameters it takes: a direction to move, a reference to a space pointer,
 * a reference to a Character Data, a reference to the remaining time, a reference
 * to another int, and a reference to a string which will store the any output as
 * a result of the move.
 *
 * This function does not protect against nullptrs, protection should be built
 * into the calling function.
 ******************************************************************************/
void Space::move(Direction moveDirection, Space *&playerSpace, CharacterData &playerData, int &timeRemaining,
                 int &tempTimeRemaining, std::string &spaceMsg) {

    //check if the player should be allowed to leave the space in the desired direction
    if(isLeaveLegal(playerData, spaceMsg, moveDirection)) {

        //if the player can leave in the des get the next space
        Space *nextSpace = getConnectedSpace(moveDirection);

        //if the next space would not reject the player
        if (nextSpace->activateSpace(playerSpace, playerData, timeRemaining, tempTimeRemaining, spaceMsg)) {

            //move the player
            playerSpace = nextSpace;
        }
    }


}

/******************************************************************************
 * Function to add an item to a space. It takes a pointer to an Item as
 * paarameter
 ******************************************************************************/
void Space::addItem(Item *itemToAdd) {
    availableItems.push_back(itemToAdd);
}

/******************************************************************************
 * Function to transfer an item from the space to the player. It takes an index
 * for the item as parameter and returns a pointer to that item to the calling
 * function
 ******************************************************************************/
Item* Space::collectItem(int index) {
    //transfer from available to collected to ease freeing memory
    collectedItems.push_back(availableItems[index]);

    //remove item from availableItems
    availableItems.erase(availableItems.begin() + index); //http://www.cplusplus.com/reference/vector/vector/erase/

    //return the item requested
    return collectedItems[collectedItems.size() - 1];
}

/******************************************************************************
 * Function to switch search to on if it was off and vise versa
 ******************************************************************************/
void Space::toggleSearch() {
    searchActive ^= 1;
}

/******************************************************************************
 * This function will link a variable in and Item to match the value of a
 * relevant data point in the player object. It takes a pointer to the variable
 * and the index of the item to link as parameters.
 ******************************************************************************/
void Space::linkInstalled(bool *boolToLink, int itemIndex) {
    availableItems[itemIndex]->setInstalled(boolToLink);
}

/******************************************************************************
 * Function to check if the player should be allowed to leave their current
 * Space in the direction chosen.
 ******************************************************************************/
bool Space::isLeaveLegal(CharacterData &playerData, std::string &spaceMsg, Direction targetDirection) {
    return true;
}

//accessors below this comment
std::string Space::getLocationName() {
    return spaceName;
}

bool Space::getSearchActive() {
    return searchActive;
}

int Space::getAvailableItemsSize() {
    return availableItems.size();
}

std::string Space::getDirText() {
    return dirText;
}

//mutators below this comment
Item * Space::getItem(int index, ItemLocation itemArray) {
    if(itemArray == SPACE) {
        return availableItems[index];
    } else {
        return collectedItems[index];
    }
}