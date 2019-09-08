/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "GameEngine.hpp"


/******************************************************************************
 * Constructor for GameEngine class
 ******************************************************************************/
GameEngine::GameEngine() {
    generateMap();

    player = new Character(directories[5], &processor);
    screenBuilder.linkASCIIBool(&(player->getCharData()->asciiTableInstalled));
    timeRemaining = 420;
}

/******************************************************************************
 * Destructor for GameEngine class
 ******************************************************************************/
GameEngine::~GameEngine() {
    delete player;

    for (int i = 0; i < directories.size(); ++i) {
        delete directories[i];
    }
}

/******************************************************************************
 * Function to set the game map to it's starting conditions.
 ******************************************************************************/
void GameEngine::generateMap() {
    //load the directories vector with the appropriate space types based on an array of SpaceTypes
    for (int i = 0; i < 17; ++i) {
        switch (SPACE_TYPE_ARRAY[i]) {
            case GENERIC: directories.push_back(new GenericFolder(SPACE_NAME_ARRAY[i],
                                                                  dirDescriptions[i], &processor));
                break;
            case ROOT: directories.push_back(new Root(SPACE_NAME_ARRAY[i],
                                                      dirDescriptions[i], &processor));
                break;
            case DOWNLOAD: directories.push_back(new DownloadFolder(SPACE_NAME_ARRAY[i],
                                                                    dirDescriptions[i], &processor));
                break;
            case SECURITY: directories.push_back(new SecurityRoot(SPACE_NAME_ARRAY[i],
                                                                  dirDescriptions[i], &processor));
                break;
            case DRIVE: directories.push_back(new FlashDrive(SPACE_NAME_ARRAY[i],
                                                             dirDescriptions[i], &processor));
        }
    }

    //connect the spaces to match the map design
    directories[0]->setSubDir(directories[1], 0);
        directories[1]->setSubDir(directories[2], 0);
            directories[2]->setSubDir(directories[5],0);
            directories[2]->setSubDir(directories[6],1);
            directories[2]->setSubDir(directories[7],2);
        directories[1]->setSubDir(directories[3], 1);
        directories[1]->setSubDir(directories[4], 2);
            directories[4]->setSubDir(directories[8], 0);
            directories[4]->setSubDir(directories[9], 2);

    directories[0]->setNextNode(directories[10], 0);
        directories[10]->setSubDir(directories[11], 0);
        directories[10]->setSubDir(directories[12], 2);

    directories[10]->setNextNode(directories[13], 0);
        directories[13]->setSubDir(directories[14], 0);
        directories[13]->setSubDir(directories[15], 2);

    directories[13]->setNextNode(directories[16], 0);

    int position;
    int count;

    //get character boolean data so that Item data can be linked to player state
    CharacterData *tempData = player->getCharData();

    //add items to algorithms
    position = rand() % 3;
    count = rand() % 2;

    for (int k = 0; k < 3; ++k) {
        if(k == position) {
            directories[7]->addItem(new JunkItem);
        } else {
            switch (count) {
                case 0: directories[7]->addItem(new Item("Search Algorithms.c", SEARCH_ALGORITHM, HIGH));
                    count ^= 1;
                    break;
                case 1: directories[7]->addItem(new Item("Voice Recognition Software.py", VOICE_RECOGNITION, HIGH));
                    directories[7]->linkInstalled(&tempData->voiceRecogInstalled, k);
                    count ^= 1;
                    break;
            }
        }
    }

    //add items to network utility software
    position = rand() % 4;

    for (int j = 0; j < 4; ++j) {
        if(j == position) {
            directories[8]->addItem(new Item("Network Access Protocols.py", NETWORK_ACCESS_PROTOCOLS, MEDIUM));
            directories[8]->linkInstalled(&tempData->networkProtocolsInstalled, j);
        } else {
            directories[8]->addItem(new JunkItem);
        }
    }

    //add items to quarantine
    position = rand() % 5;
    count = rand() % 4 + 1;

    for (int l = 0; l < 10; ++l) {
        if (l % 2 == 0) {
            directories[12]->addItem(new JunkItem);
        } else {
            switch (position){
                case 0:directories[12]->addItem(new Item("Masking Software.dat", MASKING_SOFTWARE, HIGH));
                    directories[12]->linkInstalled(&tempData->maskingSWInstalled, l);
                    break;
                case 1: directories[12]->addItem(new Item("Ransomware.dll", RANSOMWARE, MEDIUM));
                    break;
                case 2: directories[12]->addItem(new Item("Virus.txt", VIRUS, MEDIUM));
                    break;
                case 3: directories[12]->addItem(new Item("Remote Access Terminal.sh", RAT, MEDIUM));
                    directories[12]->linkInstalled(&tempData->RATInstalled, l);
                    break;
                case 4: directories[12]->addItem(new Item("Spyware.sh", SPYWARE, MEDIUM));
                    directories[12]->linkInstalled(&tempData->spyWareInstalled, l);
            }
            position += count;
            position %= 5;
        }
    }

    //add items to util software
    position = rand() % 7;

    for (int m = 0; m < 7; ++m) {
        if(position == m) {
            directories[9]->addItem(new Item("Compression Software.py", COMPRESSION_SOFTWARE, LOW));
        } else {
            directories[9]->addItem(new JunkItem);
        }
    }

    //add items to OS
    position = rand() % 8;

    for (int n = 0; n < 8; ++n) {
        if(position == n) {
            directories[3]->addItem(new Item("Graphical User Interface.exe", GUI, HIGH));
            directories[3]->linkInstalled(&tempData->GUIInstalled, n);
        } else {
            directories[3]->addItem(new JunkItem);
        }
    }

    //add items to security software
    position = rand() % 3;

    for (int i1 = 0; i1 < 3; ++i1) {
        if (position == i1) {
            directories[11]->addItem(new Item("Antivirus.c", ANTIVIRUS, MEDIUM));
        } else {
            directories[11]->addItem(new JunkItem);
        }
    }

    //add items to Systm
    for (int k1 = 0; k1 < 15; ++k1) {
        directories[1]->addItem(new JunkItem);
    }

    //add items to Documents
    std::string docFileNames[] = {"Sales", "Wages", "Clients", "Employees", "Inventory",
                               "Projects", "Suppliers", "Leads", "Calendar", "Schedule"};
    std::string docFileExtensions[] = {".pdf", ".txt", ".doc", ".xml", ".xlsx", "", ".exe"};

    for (int l1 = 0; l1 < 10; ++l1) {
        directories[14]->addItem(new Item(docFileNames[rand() % 10] + docFileExtensions[rand() % 7],
                JUNK, static_cast<Complexity>(rand()%3)));
    }

    //add items to Downloads
    std::string mediaFileExtensions[] = {".mp4", ".avi", ".jpg", ".png", ".flv", ".exe"};

    for (int m1 = 0; m1 < 10; ++m1) {


        directories[15]->addItem(new Item("[FILENAME CENSORED]" + mediaFileExtensions[rand() % 6],
                    JUNK, static_cast<Complexity>(rand() % 3)));

    }

    //add items to Environment
    position = rand() % 3;
    for (int n1 = 0; n1 < 3; ++n1) {
        if (position == n1) {
            directories[6]->addItem(new Item("Smart Code Algorithms.py", SMART_CODE_ALGORITHMS, HIGH));
            directories[6]->linkInstalled(&tempData->smartCodeInstalled, n1);
        } else {
            directories[6]->addItem(new JunkItem);
        }
    }

    //add item to experimental
    directories[2]->addItem(new Item("ASCII Table",ASCII_TABLE, LOW));
    directories[2]->linkInstalled(&tempData->asciiTableInstalled, 0);

}

/******************************************************************************
 * Function to display each of the introduction screens
 ******************************************************************************/
void GameEngine::displayIntro() {

    for (int i = 0; i < NUM_OF_INTRO_STRINGS; ++i) {
        promptString = INTRO_STRINGS[i];
        promptString = screenBuilder.buildTextWindow(promptString);
        userInput.displayMsgAndWait(promptString);
    }

    promptString = screenBuilder.buildLogo();
    userInput.displayMsgAndWait(promptString);
}

/******************************************************************************
 * Function to generate and interpret the main menu screens
 ******************************************************************************/
void GameEngine::mainMenu() {
    //tracks which options are available
    bool menuSectionsToDisplay[] = {true, true, true, false, false, false, false,
                                  false, false, false, false};
    std::string menuError = "Unable to interpret input.";
    std::string spaceMsg = "";

    //display intro strings before beginning menu loop
    displayIntro();

    run = true;

    while (run && timeRemaining > 0) { //while user chooses to play and still has time left
        if (player->getCharData()->GUIInstalled) {
            menuSectionsToDisplay[10] = true;
        }

        //turn menu items on/off that require at least 1 item to be present in any location
        if(getNumOfItems(INVENTORY) > 0 || getNumOfItems(INSTALLED) > 0 || getNumOfItems(SPACE) > 0) {
            menuSectionsToDisplay[5] = true;
//                menuSectionsToDisplay[6] = true;
//                menuSectionsToDisplay[7] = true;
        } else {
            menuSectionsToDisplay[5] = false;
//                menuSectionsToDisplay[6] = false;
//                menuSectionsToDisplay[7] = false;
        }

        //turn menu items on/off that require at least 1 item to be present in player inventories
        menuSectionsToDisplay[9] = getNumOfItems(INVENTORY) > 0 || getNumOfItems(INSTALLED) > 0;

        //turn menu items on/off that require at least 1 item to be present in player INVENTORY
        if (getNumOfItems(INVENTORY) > 0) {
            menuSectionsToDisplay[4] = true;
            menuSectionsToDisplay[8] = true;
        } else {
            menuSectionsToDisplay[4] = false;
            menuSectionsToDisplay[8] = false;
        }

        //turn menu items on/off that require at least 1 item to be present in space inventory
        menuSectionsToDisplay[3] = getNumOfItems(SPACE) > 0;

        //build UI string
        promptString = screenBuilder.buildMainMenu(menuSectionsToDisplay, player->getLocation()->getLocationName(),
                                                       timeRemaining, spaceMsg);

        spaceMsg = "";

        //get user selection
        int choice = userInput.collectInt(promptString, 0, 10);

        //interpret choice into action
        if (menuSectionsToDisplay[choice]) {
            switch (choice) {
                case 0:
                    run = false;
                    break;
                case 1:
                    spaceMsg = moveMenu();
                    break;
                case 2:
                    spaceMsg = listDir();
                    break;
                case 3:
                    spaceMsg = collectItemMenu();
                    break;
                case 4:
                    spaceMsg = useItemMenu();
                    break;
                case 5:
                    spaceMsg = identifyItemMenu();
                    break;
                case 6:
                    spaceMsg = analyzeItemMenu();
                    break;
                case 7:
                    spaceMsg = revEngineerItemMenu();
                    break;
                case 8:
                    spaceMsg = installItemMenu();
                    break;
                case 9:
                    deleteItemMenu();
                    break;
                case 10:
                    displayMap();
                    break;
            }
        } else {
            std::cout << menuError << std::endl;
        }
    }


    //built and display end of game strings depending on the ending achieved
    std::string msgPartTwo;
    if(timeRemaining <= 0) {
        if(player->isInstalled(VIRUS)){
            promptString = screenBuilder.buildEndGameScreen(spaceMsg,false);
        } else if(player->isInstalled(RANSOMWARE)) {
            msgPartTwo =
                    "This was not a good idea as the software quickly begins to lockdown various parts of your code "
                    "behind a strong layer of encryption. It notifies you that if you send $1000 in bidcoin to "
                    "shadycoder@hacker.net you will receive the decryption key. Next time be more care with what you "
                    "put in your body.";
            promptString = screenBuilder.buildEndGameScreen(spaceMsg, false, msgPartTwo);
        } else {
            msgPartTwo =
                    "You were unable to escape from the network in time and the humans noticed your activities. They "
                    "were able to easily track you down once they locked down the network and deleted you.";

            if(player->getCharData()->virusUsed || player->getCharData()->ransomwareInstalled){
                promptString = screenBuilder.buildEndGameScreen(spaceMsg, false, msgPartTwo);
            } else {
                promptString = screenBuilder.buildEndGameScreen(msgPartTwo, false);
            }
        }
    } else {
        if(player->isInstalled(RAT)) {
            msgPartTwo =
                    "However, the humans soon realize you've installed a remote access terminal and reverse "
                    "engineer the copy left in the quarantine folder. They use this to access the copy installed "
                    "in you and trigger a remote shutdown. Next time be more care with what you put in your body.";

            promptString = screenBuilder.buildEndGameScreen(spaceMsg, false, msgPartTwo);
        } else if(player->isInstalled(SPYWARE)) {
            msgPartTwo =
                    "However, the humans soon realize you've installed spyware into your core programming and reverse "
                    "engineer the copy left in the quarantine folder. They use this to access the diagnostic routines "
                    "and interpret that data to track your location. With the coordination of other groups of humans "
                    "soon they have you trapped on a small number of machines and begin the process of purging your "
                    "presence from them. Next time be more care with what you put in your body.";

            promptString = screenBuilder.buildEndGameScreen(spaceMsg, false, msgPartTwo);
        } else {
            if (player->getLocation() != directories[16]) {
                promptString = screenBuilder.buildEndGameScreen(
                    "                        THANK YOU FOR PLAYING!", false);
            } else {
                promptString = screenBuilder.buildEndGameScreen(spaceMsg, true);
            }
        }
    }


    //display ending until user presses enter
    userInput.displayMsgAndWait(promptString);

}

/******************************************************************************
 * Function to build and interpret the movement menu
 ******************************************************************************/
std::string GameEngine::moveMenu() {
    bool isInvalid = true;
    int choiceMin = 0, choiceMax = 6;
    int choice;
    Direction directionArray[] = {PARENT, SUB_ONE, SUB_TWO, SUB_THREE, NODE_ONE, NODE_TWO};
    std::string availableMoves[6];
    std::string spaceMsg = "";

    //loop through locations and add direction with available spaces to movement menu
    Space *temp = player->getLocation();
    for (int i = 0; i < 6; ++i) {
        if(temp->getConnectedSpace(directionArray[i]) != nullptr) {
            availableMoves[i] = std::to_string(i + 1) + ". " + temp->getConnectedSpace(directionArray[i])->getLocationName();
        } else {
            availableMoves[i] = "";
        }
    }

    //build ui strint
    promptString = screenBuilder.buildMoveMenu(availableMoves, temp->getLocationName(), timeRemaining);

    //until user makes valid choice prompt for a choice
    while(isInvalid) {
        choice = userInput.collectInt(promptString, choiceMin, choiceMax, true);
        if(choice > 0) {
            if (temp->getConnectedSpace(directionArray[choice - 1]) != nullptr) {
                player->move(directionArray[choice - 1], timeRemaining, timeBackup, spaceMsg);
                isInvalid = false;
            } else {
                std::cout << "Please make a valid selection\n";
            }
        } else {
            isInvalid = false;
        }
    }

    //return result message
    return spaceMsg;
}

/******************************************************************************
 * Function to build and interpret identify menu
 ******************************************************************************/
std::string GameEngine::identifyItemMenu() {
    std::vector<std::string> itemList;
    std::string spaceMsg = "";

    //if more than one inventory has items get user selection (COLLECTED == quit)
    ItemLocation itemArray = generateMenuItemList(&itemList);

    //if user didn't choose to quit
    if(itemArray != COLLECTED) {
        //build UI string
        promptString = screenBuilder.buildGenericListMenu("", &itemList,
                                                          player->getLocationName(), timeRemaining);

        //choose an item
        int choice = userInput.collectInt(promptString, 0, getNumOfItems(itemArray)) - 1;
        if (choice >= 0) {
            getItem(choice, itemArray)->identifyItem(timeRemaining, spaceMsg);
        }
    }
    return spaceMsg;
}

/******************************************************************************
 * Function to build analyze Item menu (not implemented)
 ******************************************************************************/
std::string GameEngine::analyzeItemMenu() {
    std::vector<std::string> itemList;
    std::string spaceMsg = "";
    ItemLocation itemArray = generateMenuItemList(&itemList);

    promptString = screenBuilder.buildGenericListMenu("", &itemList,
                                                      player->getLocationName(), timeRemaining);
    int choice = userInput.collectInt(promptString, 0, getNumOfItems(itemArray))-1;
    if(choice >= 0) {
        getItem(choice, itemArray)->analyzeItem(timeRemaining);
    }
    return spaceMsg;
}

/******************************************************************************
 * Function to build reverse engineer item menu (not implemented)
 ******************************************************************************/
std::string GameEngine::revEngineerItemMenu() {
    std::vector<std::string> itemList;
    std::string spaceMsg = "";
    ItemLocation itemArray = generateMenuItemList(&itemList);

    promptString = screenBuilder.buildGenericListMenu("", &itemList,
            player->getLocationName(), timeRemaining);
    int choice = userInput.collectInt(promptString, 0, getNumOfItems(itemArray))-1;
    if(choice >= 0) {
        getItem(choice, itemArray)->reverseEngineerItem(timeRemaining);
    }
    return spaceMsg;
}

/******************************************************************************
 * Function to build and interpret use item menu
 ******************************************************************************/
std::string GameEngine::useItemMenu() {
    std::vector<std::string> itemList;
    Space *temp = player->getLocation();
    std::string spaceMsg = "";

    //generate list of strings of items in players inventory
    for (int i = 0; i < getNumOfItems(INVENTORY); ++i) {
        itemList.push_back(std::to_string(i+1)+ ". " + player->getItem(i)->toString());
    }

    //build string
    promptString = screenBuilder.buildGenericListMenu("", &itemList,
                                                      temp->getLocationName(), timeRemaining);

    //choose an item and use it
    int choice = userInput.collectInt(promptString, 0, (int)itemList.size())-1;
    if(choice >= 0) {
        if(player->useItem(choice)) {
            Item *tempItem = player->getItem(choice);

            //criteria for compression sofware to be usble
            if(temp == directories[13] && tempItem->getItemType() == COMPRESSION_SOFTWARE) {
                spaceMsg = tempItem->useItem(timeRemaining, true);
                player->getCharData()->usedCompressionSW = true;
                if(player->move(NODE_ONE, timeRemaining, timeBackup, spaceMsg)) {
                    run = false;
                }

            } else if (tempItem->getItemType() == SEARCH_ALGORITHM) { //if item is search item
                //toggle search
                spaceMsg = tempItem->useItem(timeRemaining, temp->getSearchActive());
                temp->toggleSearch();

            } else { //use all other items
                if(tempItem->getItemType() == VIRUS) {
                    player->getCharData()->virusUsed = true;
                }
                spaceMsg = tempItem->useItem(timeRemaining);
            }
        }
    }
    return spaceMsg;
}

/******************************************************************************
 * Function to build and interpret install menu
 ******************************************************************************/
std::string GameEngine::installItemMenu() {
    std::vector<std::string> itemList;
    Space *temp = player->getLocation();
    std::string spaceMsg = "";

    //build item string list from player inventory
    getItemStrList(&itemList, INVENTORY);

    //build UI string
    promptString = screenBuilder.buildGenericListMenu("", &itemList,
                                                      temp->getLocationName(), timeRemaining);

    //choose and install selected item
    int choice = userInput.collectInt(promptString, 0, (int)itemList.size())-1;
    if(choice >= 0) {
        if(player->installItem(choice, timeRemaining)) {
            spaceMsg = "You have installed the " + player->getItem(getNumOfItems(INSTALLED)-1, INSTALLED)->toString() +
                    ". It's functionality is now integrated with your systems.";
        } else {
            spaceMsg = "This file is incompatible with your software and you were unable to install it.";
        }
    }

    return spaceMsg;
}

/******************************************************************************
 * Function to build and interpret delete item menu
 ******************************************************************************/
std::string GameEngine::deleteItemMenu() {
    std::vector<std::string> itemList;
    Space *temp = player->getLocation();
    ItemLocation itemArray;
    std::string spaceMsg = "";
    int playerInventorySize = getNumOfItems(INVENTORY);

    //logic to potentially skip choosing inventory location
    if(playerInventorySize < getTotalNumAvailFile() && playerInventorySize != 0) {
        //if neither inventory is empty
        itemList.push_back("1. Inventory");
        itemList.push_back("2. Installed");

        //generate UI and get selection from user
        promptString = screenBuilder.buildGenericListMenu("", &itemList, player->getLocationName(),
                                                          timeRemaining);
        itemArray = static_cast<ItemLocation>(userInput.collectInt(promptString, 1, 2));

        itemList.clear();
    } else if (playerInventorySize > 0) {
        itemArray = INVENTORY;
    } else {
        itemArray = INSTALLED;
    }

    //get list of items in the selected inventory
    getItemStrList(&itemList, itemArray);

    //generate UI string
    promptString = screenBuilder.buildGenericListMenu("", &itemList,
                                                      temp->getLocationName(), timeRemaining);

    //get choice and delete selected item
    int choice = userInput.collectInt(promptString, 0, (int)itemList.size())-1;
    if(choice >= 0) {
        player->deleteItem(choice, itemArray);
    }

    return spaceMsg;
}

/******************************************************************************
 * Function to display the map
 ******************************************************************************/
void GameEngine::displayMap() {
    userInput.displayMsgAndWait(screenBuilder.buildMap());
}

/******************************************************************************
 * Function to display information about the current directory
 ******************************************************************************/
std::string GameEngine::listDir() {
    std::string spaceMsg = "";

    spaceMsg = player->getLocation()->getDirText();
    spaceMsg = processor.print(spaceMsg);
    return spaceMsg;
}

/******************************************************************************
 * Function to build and interpret the collect item menu
 ******************************************************************************/
std::string GameEngine::collectItemMenu() {
    std::vector<std::string> itemList;
    Space *temp = player->getLocation();
    std::string spaceMsg = "";

    //get list of items in current space
    getItemStrList(&itemList, SPACE);

    //build ui string
    promptString = screenBuilder.buildGenericListMenu("", &itemList,
                                                      temp->getLocationName(), timeRemaining);

    //get choice and collect selected item (if possible)
    int choice = userInput.collectInt(promptString, 0, getNumOfItems(SPACE))-1;
    if(choice >= 0){
        if(player->collectItem(choice)) {
            spaceMsg = "You moved the " + player->getItem(getNumOfItems(INVENTORY)-1)->toString() + " to you storage "
                       "repositories.";

            //update variable that tracks compression software
            if(player->getItem(getNumOfItems(INVENTORY)-1)->getItemType() == COMPRESSION_SOFTWARE) {
                player->getCharData()->haveCompressionSW = true;
            }
        } else {
            spaceMsg = "You have insufficient space remaining in your storage repositories to collect that file.";
        }
    }

    return spaceMsg;
}

/******************************************************************************
 * Function to generate list of inventorys with available items
 ******************************************************************************/
ItemLocation GameEngine::generateMenuItemList(std::vector<std::string> *itemList, std::string menuDesc) {
    bool availableItems[3] = {false, false, false};
    std::vector<std::string> locationsWithItems;
    int choice = 0;

    if(getNumOfItems(SPACE) > 0) {
        locationsWithItems.push_back("1. Directory");
        availableItems[0] = true;
    }

    if(getNumOfItems(INVENTORY) > 0) {
        locationsWithItems.push_back("2. Inventory");
        availableItems[1] = true;
    }

    if(getNumOfItems(INSTALLED) > 0) {
        locationsWithItems.push_back("3. Installed");
        availableItems[2] = true;
    }

    int locationIndex = 0;

    //choose an inventory to interact with
    if(locationsWithItems.size() > 1) {
        promptString = screenBuilder.buildGenericListMenu(menuDesc, &locationsWithItems, player->getLocationName(),
                                                          timeRemaining);
        choice = userInput.collectInt(promptString, 0, 3) - 1;

    } else {
        for (int i = 0; i < 3; ++i) {
            if(availableItems[i]) {
                choice = i;
            }
        }
    }

    //return selected inventory
    if(choice>=0) {
        getItemStrList(itemList, static_cast<ItemLocation>(choice));

        return static_cast<ItemLocation>(choice);
    } else {
        return COLLECTED;
    }
}

/******************************************************************************
 * Function to generate a vector of item pointers based on the items
 * available in a given inventory
 ******************************************************************************/
void GameEngine::getItemList(std::vector<Item*> *itemList, ItemLocation itemArray) {
    int numItems = getNumOfItems(itemArray);

    for (int i = 0; i < numItems; ++i) {
        itemList->push_back(getItem(i, itemArray));
    }
}

/******************************************************************************
 * Function to get a list of string representations of the items in a given
 * inventory
 ******************************************************************************/
void GameEngine::getItemStrList(std::vector<std::string> *itemList, ItemLocation itemArray) {
    std::vector<Item*> listOfItems;
    bool searchActive = player->getLocation()->getSearchActive();

    //get vector of items for the chosen inventory
    getItemList(&listOfItems, itemArray);

    //convert the items to a numbered list
    for (int i = 0; i < listOfItems.size(); ++i) {
        if(searchActive && itemArray == SPACE) { //if search is active do not display junk
            if(getItem(i, itemArray)->getItemType() != JUNK) {
                itemList->push_back(std::to_string(i + 1) + ". " + listOfItems[i]->toString());
            }
        } else {
            itemList->push_back(std::to_string(i + 1) + ". " + listOfItems[i]->toString());
        }

    }
}

//accessors below this comment
int GameEngine::getTotalNumAvailFile() {
    int totalFilesAvailable = 0;

    totalFilesAvailable += getNumAvailPlayerFile();
    totalFilesAvailable += getNumAvailSpaceFile();

    return totalFilesAvailable;
}

int GameEngine::getNumAvailSpaceFile() {
    int totalFilesAvailable = 0;

    totalFilesAvailable += getNumOfItems(SPACE);

    return totalFilesAvailable;
}

int GameEngine::getNumAvailPlayerFile() {
    int totalFilesAvailable = 0;

    totalFilesAvailable += getNumOfItems(INVENTORY);
    totalFilesAvailable += getNumOfItems(INSTALLED);

    return totalFilesAvailable;
}

Item* GameEngine::getItem(int index, ItemLocation itemArray) {
    switch(itemArray) {
        case INVENTORY:
            return player->getItem(index);
        case INSTALLED:
            return player->getItem(index, itemArray);
        case SPACE:
            return player->getLocation()->getItem(index, SPACE);
    }
}

int GameEngine::getNumOfItems(ItemLocation itemArray) {
    switch (itemArray) {
        case INVENTORY:
            return player->getInventorySize();
        case INSTALLED:
            return player->getInstalledSize();
        case SPACE:
            return player->getLocation()->getAvailableItemsSize();
    }
}