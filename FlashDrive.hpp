/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_FLASHDRIVE_HPP
#define CS162_FLASHDRIVE_HPP

#include "Space.hpp"

/******************************************************************************
 * Class FlashDrive
 *
 * This class represents the flash drive of the computer and reaching it is the
 * goal of the game.
 ******************************************************************************/
class FlashDrive : public Space {
protected:
    bool activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining, int &tempTimeRemaining,
                       std::string &spaceMsg);

public:
    FlashDrive(std::string spaceName, std::string dirText, MessageProcessor *printer);
};


#endif //CS162_FLASHDRIVE_HPP
