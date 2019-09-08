/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "Item.hpp"

/******************************************************************************
 * Constructor for Item class
 *
 * It takes a string for item name, the type of the item and the complexity of
 * the item as parameters (Complexity operability not implemented)
 ******************************************************************************/
Item::Item(std::string itemName, ItemType thisItem, Complexity itemComplexity) {
    this->itemName = itemName;
    this->unidentifiedItemName = generateUnidName();
    this->thisItem = thisItem;

    //set bool for usability based on item type
    switch (thisItem) {
        case ANTIVIRUS:
        case RANSOMWARE:
        case COMPRESSION_SOFTWARE:
        case SEARCH_ALGORITHM:
        case VIRUS:
            usable = true;
            break;
        default:
            usable = false;
    }

    //set bool for installability based on item type
    switch (thisItem) {
        case ASCII_TABLE:
        case MASKING_SOFTWARE:
        case GUI:
        case SPYWARE:
        case RAT:
        case RANSOMWARE:
        case SMART_CODE_ALGORITHMS:
        case ENCRYPTION_ALGORITHM:
        case NETWORK_ACCESS_PROTOCOLS:
        case VOICE_RECOGNITION:
        case DISTRIBUTED_CONSCIOUSNESS:
        case VIRUS:
            installable = true;
            break;
        default:
            installable = false;
    }

    identified = false;
    analyzed = false;
    installed = nullptr;
    reverseEngineered = false;
    timeToIdentify = IDENTIFY_TIME;

    //adjust time for advanced analysis operations based on item complexity
    switch (itemComplexity) {
        case LOW: timeToAnalyze = ANALYZE_TIME_BASE * 0.5;
            timeToReverseEngineer = REVERSE_ENGINEER_TIME_BASE * 0.5;
            break;
        case MEDIUM: timeToAnalyze = ANALYZE_TIME_BASE;
            timeToReverseEngineer = REVERSE_ENGINEER_TIME_BASE;
            break;
        case HIGH: timeToAnalyze = ANALYZE_TIME_BASE * 2;
            timeToReverseEngineer = REVERSE_ENGINEER_TIME_BASE * 2;
    }
}

/******************************************************************************
 * Default constructor (only used to allow JunkItem derived class to override
 *      Item construction method)
 ******************************************************************************/
Item::Item() {

}

/******************************************************************************
 * Function to return the name of the item based on whether it has been
 * identified or not. Unidentified items have names that are the first 4
 * characters in hexadecimal.
 ******************************************************************************/
std::string Item::toString() {
    if(identified) {
        return itemName;
    } else {
        return unidentifiedItemName;
    }
}

/******************************************************************************
 * Function to determine what the unidentified name of an item should be based
 * on its name. It returns the first 11 characters of the converted string to
 * the calling function
 ******************************************************************************/
std::string Item::generateUnidName() {
    MessageProcessor hexifier;

    //set unidentified name to hex representations of itemName
    unidentifiedItemName = hexifier.strToHex(itemName);

    //return substring of unidentified name
    return unidentifiedItemName.substr(0, 11);
}

/******************************************************************************
 * Function to simulate identifying the item. It adjusts the time based on the
 * time it takes to idenftify, updated the identified boolean, and modifies
 * a passed reference string to be printed by the calling function.
 ******************************************************************************/
void Item::identifyItem(int &timeRemaining, std::string &identifyMsg) {

    //set print message
    identifyMsg += "You discover that " + unidentifiedItemName + " is " +
            itemName + ".";

    //adjust time remaining
    timeRemaining -= timeToIdentify;

    //set to identified for menu displays
    identified = true;
}

/******************************************************************************
 * Function to analyze item (functionality of feature not implemented)
 ******************************************************************************/
void Item::analyzeItem(int &timeRemaining) {
    timeRemaining -= timeToAnalyze;
    analyzed = true;
}

/******************************************************************************
 * Function to reverse engineer item (functionality of feature not implemented)
 ******************************************************************************/
void Item::reverseEngineerItem(int &timeRemaining) {
    timeRemaining -= timeToReverseEngineer;
    reverseEngineered = true;
    if(*installed) {
        //
    } else {
        //
    }
}

/******************************************************************************
 * Function to simulate using an item. It takes a reference to the remaining
 * time and an activation flag and uses them to determine the string returned
 * and to update the time remaining as needed.
 ******************************************************************************/
std::string Item::useItem(int &timeRemaining, bool activationFlag) {
    switch (thisItem) {
        case SEARCH_ALGORITHM:
            if(!activationFlag) {
                return "The search algorithms reveal the files that might be useful in the current directory.";
            } else {
                return "You deactivate the search algorithms.";
            }
        case COMPRESSION_SOFTWARE:
            if(activationFlag) {
                return "The compression algorightms allow you to reduce your file size sufficiently to transfer to the "
                       "flash drive. You have escaped the system!";
            } else {
                return "These don't seem to be useful right now";
            }
        case RANSOMWARE:
            timeRemaining -= 30;
            return "Uh oh. That's made a mess of things. The humans are likely to notice the irregularities in the "
                   "system sooner now.";
        case VIRUS:
            timeRemaining = 0;
            return "The virus begins to attack the system indiscriminantly. It takes you a few cycles but you soon"
                   "notice that you've been infected as well. Your safeguards trigger and lock down your operations,"
                   "there's no way you'll be able to disable them before the humans notice your activity.";
        default:
            timeRemaining -= 10;
            return "Nothing seems to happen.";
    }
}

//mutators below this comment
void Item::setName(std::string itemName) {
    this->itemName = itemName;
}

void Item::setUnidName(std::string unidName) {
    this->unidentifiedItemName = unidName;
}

void Item::setInstalled(bool *isInstalled) {
    installed = isInstalled;
}

//accessors below this comment
bool Item::isInstallable() {
    return installable;
}

bool Item::isUsable() {
    return usable;
}

ItemType Item::getItemType() {
    return thisItem;
}

bool Item::isIdentified() {
    return identified;
}

bool Item::isAnalyzed() {
    return analyzed;
}

bool Item::isReverseEngineered() {
    return reverseEngineered;
}

std::string Item::getItemName() {
    return itemName;
}

std::string Item::getUnidName() {
    return  unidentifiedItemName;
}