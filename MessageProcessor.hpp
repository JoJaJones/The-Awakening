/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_MESSAGEPROCESSOR_HPP
#define CS162_MESSAGEPROCESSOR_HPP

#include <string>
#include <iostream>
#include "UIBuilder.hpp"

/*********************************************************************
 * Class MessageProcessor
 *
 * This class handles processing message into their hex equivalent if
 * if necessary
 *********************************************************************/
class MessageProcessor {
private:
    bool *asciiTableInstalled;
    UIBuilder screenBuilder;

public:
    std::string strToHex(std::string strToConvert);
    std::string print(std::string strToPrint, bool printActual = false);
    void linkASCIIboolean(bool *ASCIITableInstalled);
    void flipTable();
};


#endif //CS162_MESSAGEPROCESSOR_HPP
