/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_ITEM_HPP
#define CS162_ITEM_HPP

#include "Constants.hpp"
#include "MessageProcessor.hpp"
#include <string>

/*********************************************************************
 * Class Item
 *
 * This class represents an item in the game that the user can interact
 * with. It has various variables that reflect the state of the item
 * and modifications it can do to the player of space.
 *********************************************************************/
class Item {
protected:
    std::string itemName;
    std::string unidentifiedItemName;
    bool identified;
    bool analyzed;
    bool reverseEngineered;
    bool *installed;
    bool usable;
    bool installable;
    bool needsRevEngineer;
    int timeToIdentify;
    int timeToAnalyze;
    int timeToReverseEngineer;
    ItemType thisItem;
public:
    Item(std::string itemName, ItemType thisItem, Complexity itemComplexity);
    Item();

    std::string useItem(int &timeRemaining, bool activationFlag = false);

    void identifyItem(int &timeRemaining, std::string &identifyMsg);
    void analyzeItem(int &timeRemaining);
    void reverseEngineerItem(int &timeRemaining);

    std::string generateUnidName();

    void setUnidName(std::string unidName);
    void setName(std::string itemName);
    void setInstalled(bool *isInstalled);

    std::string getItemName();
    std::string getUnidName();
    std::string toString();
    ItemType getItemType();
    bool isUsable();
    bool isInstallable();
    bool isIdentified();
    bool isAnalyzed();
    bool isReverseEngineered();
};


#endif //CS162_ITEM_HPP
