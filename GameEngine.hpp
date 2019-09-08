/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_GAMEENGINE_HPP
#define CS162_GAMEENGINE_HPP

#include <vector>

#include "Character.hpp"
#include "GenericFolder.hpp"
#include "SecurityRoot.hpp"
#include "DownloadFolder.hpp"
#include "FlashDrive.hpp"
#include "MessageProcessor.hpp"
#include "InputCollector.hpp"
#include "JunkItem.hpp"

#include <cstdlib>
#include <ctime>

/*********************************************************************
 * Class GameEngine
 *
 * This class provides an interface between the User and the logic and
 * coordinates the actions of the player with appropriate changes in
 * the world
 *********************************************************************/
class GameEngine {
private:
    Character *player;
    MessageProcessor processor;
    InputCollector userInput;
    UIBuilder screenBuilder;
    std::vector<Space*> directories;
    std::string promptString;
    int timeRemaining;
    int timeBackup;

    bool run;

    Item* getItem(int index, ItemLocation itemArray);

    void getItemStrList(std::vector<std::string> *itemList, ItemLocation itemArray);
    void getItemList(std::vector<Item*> *itemList, ItemLocation itemArray);
    ItemLocation generateMenuItemList(std::vector<std::string> *itemList, std::string menuDesc = "");
    void generateMap();

    void displayIntro();
public:
    GameEngine();

    void mainMenu();
    ~GameEngine();

    std::string identifyItemMenu();
    std::string analyzeItemMenu();
    std::string revEngineerItemMenu();
    std::string useItemMenu();
    std::string installItemMenu();
    std::string deleteItemMenu();
    std::string collectItemMenu();
    void displayMap();
    std::string moveMenu();
    std::string listDir();

    int getNumOfItems(ItemLocation itemArray);
    int getTotalNumAvailFile();
    int getNumAvailPlayerFile();
    int getNumAvailSpaceFile();
};


#endif //CS162_GAMEENGINE_HPP
