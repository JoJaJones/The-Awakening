/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#include "SecurityRoot.hpp"

/******************************************************************************
 * Function to implement the actions specific to this derived class. Overrides
 * the abstract function in Space.
 *
 * It takes a reference to a Space pointer, a reference to a CharacterData,
 * a reference to the time remaining, a reference to another int, and a reference
 * to a string that will store any output that needs to be printed.
 ******************************************************************************/
bool SecurityRoot::activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining,
        int &tempTimeRemaining, std::string &spaceMsg) {

    if(!playerData.maskingSWInstalled) { //if player doesn't have masking software installed
        playerSpace = subDirectory[2]; //move player to quarantine folder


        if(timeRemaining > 60) { //prevent infinite time cheat
            tempTimeRemaining = timeRemaining; //backup the time remaining for if the player escapes death
            timeRemaining = QUARANTINE_TIME_LIMIT; //activate SUDDEN DEATH
            quarantineInEffect = true;
        }

        //process and set message to be printed
        std::string message = "The machine you tried to enter detected your infiltration and mistaken you for a virus. "
                              "It has moved you to a quarantine folder";
        spaceMsg = processor->print(message);

        return false; //reject user entry;
    } else {

        if(quarantineInEffect) { //prevent second infinite time cheat

            //restore time to what it was minus any used during quarantine
            timeRemaining = tempTimeRemaining - (60 - timeRemaining);
            quarantineInEffect = false;
        }
        return true;
    }

}

/******************************************************************************
 * Constructor for the SecurityRoot class
 ******************************************************************************/
SecurityRoot::SecurityRoot(std::string spaceName, std::string dirText, MessageProcessor *printer)
             : Root(spaceName, dirText, printer) {
}