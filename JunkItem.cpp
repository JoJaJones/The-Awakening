/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "JunkItem.hpp"

/******************************************************************************
 * Constructor for JunkItem class.
 *
 * It randomly generates relevant data members.
 ******************************************************************************/
JunkItem::JunkItem() {
    Complexity itemComplexity = static_cast<Complexity>(rand()%3);

    generateName();
    this->unidentifiedItemName = generateUnidName();
    this->thisItem = JUNK;

    usable = true;
    installable = false;

    identified = false;
    analyzed = false;
    installed = nullptr;
    reverseEngineered = false;
    timeToIdentify = IDENTIFY_TIME;
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
 * Function to procedurally generate filenames from the available names and
 * extensions.
 ******************************************************************************/
void JunkItem::generateName() {
    itemName = "";
    itemName += fileStarts[rand() % 11];
    itemName += fileEnds[rand() % 8];
}

