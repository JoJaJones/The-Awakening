/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_CHARACTER_HPP
#define CS162_CHARACTER_HPP

#include "Constants.hpp"
#include "Space.hpp"

#include <vector>

/*********************************************************************
 * Class Character
 *
 * This class represents the users avatar. It has variables to track
 * status and functions to modify player and/or game state
 *********************************************************************/
class Character {
private:
    Space *currentSpace;
    CharacterData thisChar;
    std::vector<Item*> inventory;
    std::vector<Item*> installedItems;
    MessageProcessor *processor;

    bool updateInstall(bool &itemToInstall, int itemIndex);
public:
    Character(Space *startSpace, MessageProcessor *printer);
    bool move(Direction moveDirection, int &timeRemaining, int &tempTimeRemaining, std::string &spaceMsg);
    bool useItem(int itemIndex);
    bool analyzeItem(int itemIndex, ItemLocation whichItem);
    bool revEngineerItem(int itemIndex, ItemLocation whichItem);

    bool installItem(int itemIndex, int &timeRemaining);
    bool isInstalled(ItemType itemToCheck);

    bool collectItem(int itemIndex);
    void flipTable();

    CharacterData* getCharData();
    std::string getLocationName();
    Space* getLocation();
    Item *getItem(int index, ItemLocation itemArray = INVENTORY);
    void deleteItem(int index, ItemLocation);
    int getInventorySize();
    int getInstalledSize();
};


#endif //CS162_CHARACTER_HPP
