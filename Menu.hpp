/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_MENU_HPP
#define CS162_MENU_HPP

#include "GameEngine.hpp"

/*********************************************************************
 * Class to create a menu that allows the user to make selections from
 * available options using numerical choices.
 *********************************************************************/
class Menu {
private:
    InputCollector userInput;
    std::string promptString;

public:

    void mainMenu();
    void displayHowToPlay();
    void launchGame();
};


#endif //CS162_MENU_HPP
