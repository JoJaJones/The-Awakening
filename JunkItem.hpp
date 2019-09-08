/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_JUNKITEM_HPP
#define CS162_JUNKITEM_HPP

#include "Item.hpp"
#include "MessageProcessor.hpp"


/******************************************************************************
 * Class JunkItem
 *
 * class to represent decoy items. They have no function but can cost the player
 * time if identified or used.
 ******************************************************************************/
class JunkItem : public Item {
private:
    void generateName();
public:
    JunkItem();
};


#endif //CS162_JUNKITEM_HPP
