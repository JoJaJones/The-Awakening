/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_SECURITYROOT_HPP
#define CS162_SECURITYROOT_HPP

#include "Root.hpp"

/******************************************************************************
 * Class SecurityRoot
 *
 * This class represents the root directory of the security terminal. It has a
 * special interaction when the player enters for the first time to trap the
 * player in the Quarantine directory until they install the Masking Software.
 ******************************************************************************/
class SecurityRoot : public Root {
protected:
    bool quarantineInEffect;

    bool activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining, int &tempTimeRemaining,
                       std::string &spaceMsg);

public:
    SecurityRoot(std::string spaceName, std::string dirText, MessageProcessor *printer);
};


#endif //CS162_SECURITYROOT_HPP
