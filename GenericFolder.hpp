/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_GENERICSPACE_HPP
#define CS162_GENERICSPACE_HPP

#include "Space.hpp"

/******************************************************************************
 * Class GenericSpace
 *
 * This class represents the spaces with no special function.
 ******************************************************************************/
class GenericFolder : public Space {
protected:
    bool activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining, int &tempTimeRemaining,
                       std::string &spaceMsg);

public:
    GenericFolder(std::string spaceName, std::string dirText, MessageProcessor *printer);
};


#endif //CS162_GENERICSPACE_HPP
