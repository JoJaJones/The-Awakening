/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_ROOT_HPP
#define CS162_ROOT_HPP

#include "Space.hpp"
#include "Constants.hpp"

/******************************************************************************
 * Class Root
 *
 * This class represents the root directory of a computer and only allows
 * movement to other computers if the player has network protocols installed
 ******************************************************************************/
class Root : public Space {
protected:
    bool activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining, int &tempTimeRemaining,
                       std::string &spaceMsg);
    bool isLeaveLegal(CharacterData &playerData, std::string &spaceMsg, Direction targetDirection);
public:
    Root(std::string spaceName, std::string dirText, MessageProcessor *printer);
};


#endif //CS162_ROOT_HPP
