/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_DOWNLOADFOLDER_HPP
#define CS162_DOWNLOADFOLDER_HPP

#include "Space.hpp"

/*********************************************************************
 * Class DownloadFolder
 *
 * This class represents the download folder of the excutive's laptop
 *********************************************************************/
class DownloadFolder : public Space {
protected:
    bool activateSpace(Space *&playerSpace, CharacterData &playerData, int &timeRemaining, int &tempTimeRemaining,
                       std::string &spaceMsg);
public:
    DownloadFolder(std::string spaceName, std::string dirText, MessageProcessor *printer);
};


#endif //CS162_DOWNLOADFOLDER_HPP
