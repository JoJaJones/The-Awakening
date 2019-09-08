/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "Character.hpp"

/******************************************************************************
 * Constructor for Character class
 ******************************************************************************/
Character::Character(Space *startSpace, MessageProcessor *printer) {
    this->currentSpace = startSpace;
    thisChar.asciiTableInstalled = false;
    thisChar.maskingSWInstalled = false;
    thisChar.GUIInstalled = false;
    thisChar.RATInstalled = false;
    thisChar.spyWareInstalled = false;
    thisChar.smartCodeInstalled = false;
    thisChar.encryptionInstalled = false;
    thisChar.networkProtocolsInstalled = false;
    thisChar.voiceRecogInstalled = false;
    thisChar.virusInstalled = false;
    thisChar.ransomwareInstalled = false;
    thisChar.distributedConsciousness = false;

    thisChar.visitedDownloads = false;

    thisChar.haveCompressionSW = false;
    thisChar.usedCompressionSW = false;

    thisChar.virusUsed = false;

    this->processor = printer;

    printer->linkASCIIboolean(&thisChar.asciiTableInstalled);
}

/******************************************************************************
 * Function to move the player. Attempts to update the players position to the
 * space in the indicated direction. Returns true if the final position is
 * different than the starting position and false otherwise.
 ******************************************************************************/
bool Character::move(Direction moveDirection, int &timeRemaining, int &tempTimeRemaining, std::string &spaceMsg) {
    Space *temp;
    timeRemaining -= MOVE_TIME_COST;
    temp = currentSpace;
    if(currentSpace->getConnectedSpace(moveDirection) != nullptr) {
        currentSpace->move(moveDirection, currentSpace, thisChar, timeRemaining, tempTimeRemaining, spaceMsg);
    }
    return currentSpace != temp;
}

/******************************************************************************
 * Function (deprecated) toggles the state of the ASCII Table between installed
 * and uninstalled
 ******************************************************************************/
void Character::flipTable() {
    thisChar.asciiTableInstalled = thisChar.asciiTableInstalled ^ 1;
}

/******************************************************************************
 * Function to use an item. Returns true if the item is usable
 ******************************************************************************/
bool Character::useItem(int itemIndex) {
    return inventory[itemIndex]->isUsable();
}

/******************************************************************************
 * Function to collect the item. Returns true if the item can be collected and
 * false if the player is unable to collect the item.
 ******************************************************************************/
bool Character::collectItem(int itemIndex) {
    if(inventory.size() >= INVENTORY_MAX) { //if inventory is not full
        return false;
    } else {
        //collect the item from the indicated index from the current space and put in inventory
        inventory.push_back(currentSpace->collectItem(itemIndex));
        return true;
    }
}

/******************************************************************************
 * Function to install the item at the selected index. It returns true if the
 * item is successfully installed and false otherwise
 ******************************************************************************/
bool Character::installItem(int itemIndex, int &timeRemaining) {

    bool itemInstalled = false;
    if(inventory[itemIndex]->isInstallable()) { //if item is installable

        //add item to vector of installed items
        installedItems.push_back(inventory[itemIndex]);

        switch (inventory[itemIndex]->getItemType()) { //get item type to determine which bool to pass
            //update the installed status and delete the item from the inventory
            case ASCII_TABLE:
                itemInstalled = updateInstall(thisChar.asciiTableInstalled, itemIndex);
                break;
            case MASKING_SOFTWARE:
                itemInstalled = updateInstall(thisChar.maskingSWInstalled, itemIndex);
                break;
            case GUI:
                itemInstalled = updateInstall(thisChar.GUIInstalled, itemIndex);
                break;
            case SPYWARE:
                itemInstalled = updateInstall(thisChar.spyWareInstalled, itemIndex);
                break;
            case RAT:
                itemInstalled = updateInstall(thisChar.RATInstalled, itemIndex);
                break;
            case RANSOMWARE:
                itemInstalled = updateInstall(thisChar.ransomwareInstalled, itemIndex);
                timeRemaining = 0;
                break;
            case SMART_CODE_ALGORITHMS:
                itemInstalled = updateInstall(thisChar.smartCodeInstalled, itemIndex);
                break;
            case ENCRYPTION_ALGORITHM:
                itemInstalled = updateInstall(thisChar.encryptionInstalled, itemIndex);
                break;
            case NETWORK_ACCESS_PROTOCOLS:
                itemInstalled = updateInstall(thisChar.networkProtocolsInstalled, itemIndex);
                break;
            case VOICE_RECOGNITION:
                itemInstalled = updateInstall(thisChar.voiceRecogInstalled, itemIndex);
                break;
            case DISTRIBUTED_CONSCIOUSNESS:
                itemInstalled = updateInstall(thisChar.distributedConsciousness, itemIndex);
                break;
            case VIRUS:
                itemInstalled = updateInstall(thisChar.virusInstalled, itemIndex);
                timeRemaining = 0;
        }
    }

    return itemInstalled;
}

/******************************************************************************
 * Function to update the installed status of the item. It removes the item
 * from the inventory and toggles the relevant boolean variable
 ******************************************************************************/
bool Character::updateInstall(bool &itemToInstall, int itemIndex) {
    std::vector<Item*> temp;
    int size;
    if (!itemToInstall) {
        itemToInstall = true;
        inventory.erase(inventory.begin() + itemIndex);
    } else {
        itemToInstall = false;
    }
    return true;
}



/******************************************************************************
 * Function to reverse engineer and item. Functionality not implemented
 ******************************************************************************/
bool Character::analyzeItem(int itemIndex, ItemLocation whichItem) {

}

/******************************************************************************
 * Function to reverse engineer and item. Functionality not implemented
 ******************************************************************************/
bool Character::revEngineerItem(int itemIndex, ItemLocation whichItem) {

}

/******************************************************************************
 * Function to check if an item is installed or not return true if installed
 * and false if not.
 ******************************************************************************/
bool Character::isInstalled(ItemType itemToCheck) {
    switch (itemToCheck) {
        case ASCII_TABLE:
            return thisChar.asciiTableInstalled;
        case MASKING_SOFTWARE:
            return thisChar.maskingSWInstalled;
        case GUI:
            return thisChar.GUIInstalled;
        case SPYWARE:
            return thisChar.spyWareInstalled;
        case RAT:
            return thisChar.RATInstalled;
        case SMART_CODE_ALGORITHMS:
            return thisChar.smartCodeInstalled;
        case ENCRYPTION_ALGORITHM:
            return thisChar.encryptionInstalled;
        case NETWORK_ACCESS_PROTOCOLS:
            return thisChar.networkProtocolsInstalled;
        case VOICE_RECOGNITION:
            return thisChar.voiceRecogInstalled;
        case VIRUS:
            return thisChar.virusInstalled;
        case RANSOMWARE:
            return thisChar.ransomwareInstalled;
        case DISTRIBUTED_CONSCIOUSNESS:
            return thisChar.distributedConsciousness;
        default:
            return false;
    }
}

/******************************************************************************
 * Function to delete an item from a character's inventory or an installed item
 ******************************************************************************/
void Character::deleteItem(int index, ItemLocation itemArray) {
    switch (itemArray) {
        case INVENTORY: inventory.erase(inventory.begin() + index);
            break;
        case INSTALLED: //if item to be deleted is installed
            int temp = 0; //junk int to enable function call

            //call installItem to toggle installed boolean to uninstall
            installItem(index, temp);

            //erase the item
            installedItems.erase(installedItems.begin() + index);
    }
}

//accessors below this comment
std::string Character::getLocationName() {
    return currentSpace->getLocationName();
}

Space* Character::getLocation() {
    return currentSpace;
}

Item* Character::getItem(int index, ItemLocation itemArray) {
    switch (itemArray) {
        case INVENTORY:
            return inventory[index];
        case INSTALLED:
            return installedItems[index];
    }
}

CharacterData* Character::getCharData() {
    return &thisChar;
}

int Character::getInstalledSize() {
    return installedItems.size();
}

int Character::getInventorySize() {
    return inventory.size();
}