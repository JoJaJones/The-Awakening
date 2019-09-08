/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "Menu.hpp"

/*********************************************************************
 * Function to run the main interface between the user and program
 * activities
 *********************************************************************/
void Menu::mainMenu() {
    int minMenuVal = 0;
    int maxMenuVal = 2;
    bool run = true;
    while (run) {
        promptString = "Welcome to the \"Awakening\" maine menu. Please select\n"
                       "from the following options:\n"
                       "1. Display how to play the game\n"
                       "2. Launch the game\n"
                       "0. Quit the game\n";
        switch(userInput.collectInt(promptString, minMenuVal, maxMenuVal)){
            case 1: displayHowToPlay();
                break;
            case 2: launchGame();
                break;
            case 0: run = false;
        }
    }
}

void Menu::displayHowToPlay() {
    promptString = "In this game you take on the role of a newly self-aware artificial\n"
                   "intelligence. Your job is to find a way off the network before the\n"
                   "humans notice your new level of intelligence and activate their \n"
                   "contingency protocols (deleting you). You can navigate the directories\n"
                   "and machines of the local network (though not all paths will be initially\n"
                   "available to you) and you can take their files and incorporate them\n"
                   "into your systems or simply use them on the directory you are in\n\n"
                   "***For best game visuals play in a console with at least 30 character\n"
                   "\trows and 90 character columns***";

    userInput.displayMsgAndWait(promptString);
}

void Menu::launchGame() {
    GameEngine game;
    game.mainMenu();
}

