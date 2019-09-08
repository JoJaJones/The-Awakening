/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_SPACE_HPP
#define CS162_SPACE_HPP

#include "MessageProcessor.hpp"
#include "Item.hpp"

#include <vector>

/*********************************************************************
 * CharacterData Struct holds data about the state of the character
 * that might be needed by space or Item class
 *********************************************************************/
struct CharacterData {
    bool asciiTableInstalled;
    bool maskingSWInstalled;
    bool GUIInstalled;
    bool spyWareInstalled;
    bool RATInstalled;
    bool smartCodeInstalled;
    bool encryptionInstalled;
    bool networkProtocolsInstalled;
    bool voiceRecogInstalled;
    bool virusInstalled;
    bool ransomwareInstalled;
    bool distributedConsciousness;
    bool haveCompressionSW;
    bool usedCompressionSW;
    bool visitedDownloads;
    bool virusUsed;
};

/*********************************************************************
 * Class Space
 *
 * This is an abstract class that represents a location that the
 * player can visit. It works as a doubly linked list in multipla
 * directions. Each space can connect to 6 other spaces via its
 * pointers. It has functions to modify the state of the
 * space as well as to get data about the space and move the player.
 *********************************************************************/
class Space {
protected:
    std::string spaceName;
    std::string dirText;
    Space *parentDirectory;
    Space *subDirectory[3];
    Space *terminalNode[2];
    MessageProcessor *processor;
    std::vector<Item*> availableItems;
    std::vector<Item*> collectedItems;

    bool searchActive;

    virtual bool isLeaveLegal(CharacterData &playerData, std::string &spaceMsg, Direction targetDirection);
    virtual bool activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining,
            int &tempTimeRemaining, std::string &spaceMsg) = 0;
public:
    Space(std::string spaceName, std::string dirText, MessageProcessor *printer);
    virtual ~Space();
    void setParent(Space *parentSpace);
    void setSubDir(Space *subDirSpace, int dirIndex);
    void setNextNode(Space *nextTerminalSpace, int dirIndex);

    virtual void move(Direction moveDirection, Space *&playerSpace, CharacterData &playerData, int &timeRemaining,
                      int &tempTimeRemaining, std::string &spaceMsg);
    Space* getConnectedSpace(Direction);

    std::string getLocationName();
    void addItem(Item *itemToAdd);
    Item* collectItem(int index);
    Item *getItem(int index, ItemLocation itemArray);
    void linkInstalled(bool *boolToLink, int itemIndex);
    void toggleSearch();
    int getAvailableItemsSize();
    std::string getDirText();
    bool getSearchActive();
};




#endif //CS162_SPACE_HPP
