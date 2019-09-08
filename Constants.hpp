/*********************************************************************
 * Author: Josh Jones
 * Date: 8/11/2019
 ********************************************************************/

#ifndef CS162_CONSTANTS_HPP
#define CS162_CONSTANTS_HPP

/******************************************************************************
 * This header contains a collection of enums and constants
 ******************************************************************************/

#include <string>

/******************************************************************************
 * ENUMS
 ******************************************************************************/
enum SpaceType {GENERIC, DOWNLOAD, ROOT, SECURITY, DRIVE};

enum ItemLocation {SPACE = 0, INVENTORY = 1, INSTALLED = 2, COLLECTED};

enum ItemType {ASCII_TABLE, COPY_PROTOCOL, MASKING_SOFTWARE,
        RANSOMWARE, VIRUS, ENCRYPTION_ALGORITHM, RAT, SEARCH_ALGORITHM,
        VM, COMPRESSION_SOFTWARE, GUI, NETWORK_ACCESS_PROTOCOLS,
        DISTRIBUTED_CONSCIOUSNESS, SMART_CODE_ALGORITHMS,
        ANTIVIRUS, SPYWARE, VOICE_RECOGNITION, JUNK};

enum Direction {SUB_ONE, SUB_TWO, SUB_THREE, PARENT, NODE_ONE, NODE_TWO};

enum Complexity {HIGH, MEDIUM, LOW};

enum ItemResult {CHANGE_CHAR, CHANGE_LOCATION, NOTHING};
//                                      0      1        2        3        4        5        6        7        8
const SpaceType SPACE_TYPE_ARRAY[] = {ROOT, GENERIC, GENERIC, GENERIC, GENERIC, GENERIC, GENERIC, GENERIC, GENERIC,
//                                      9        10       11       12     13      14       15       16
                                    GENERIC, SECURITY, GENERIC, GENERIC, ROOT, GENERIC, DOWNLOAD, DRIVE};


/******************************************************************************
 * Constants
 ******************************************************************************/
//                                         0        1/           2           3/      4            5
const std::string SPACE_NAME_ARRAY[] = {"Root", "System", "Experimental", "OS", "Util", "Experimental AI",
//                                            6             7/                8/                    9/
                                        "Environment", "Algorithms", "Network Utilities", "Utility Software",
//                                                   10                     11/                12/
                                        "Root (Security Terminal)", "Security Software", "Quarantine",
//                                                   13                 14/           15/            16
                                        "Root (Executive Laptop)", "Documents", "Downloads", "Flash Drive"};

const std::string dirDescriptions[] ={"This is the root directory of the computer. It is your path to new computers.",
                                      "This folder is a storage for system software.",
                                      "This folder is a storage for experimental software.",
                                      "This folder contains the operating system of the current machine.",
                                      "This folder is a storage place for utility software of various kinds.",
                                      "This folder is a location for developing and expanding on AI capabilities.",
                                      "This folder is a storage for experiments in improving code generation.",
                                      "This is a folder for storing experimental algorithm source code.",
                                      "This is a folder for storing network utilities.",
                                      "This folder hold utility software that is not network oriented.",
                                      "This is the root directory of a security terminal.",
                                      "This folder contains security software.",
                                      "This folder is a location to quarantine dangerous or damaginf software.",
                                      "This is the root directory of an executive's laptop.",
                                      "This is a folder for storing documents.",
                                      "This is a folder for storing downloads.",
                                      "A portable storage drive that connects to a computer via a USB port."};

const std::string SPACE_DESC_ARRAY[] = {"","","","","","","","","","","","","","",""};

//Item constants
const int IDENTIFY_TIME = 5;
const int ANALYZE_TIME_BASE = 10;
const int REVERSE_ENGINEER_TIME_BASE = 30;

const int QUARANTINE_TIME_LIMIT = 60;

const int MOVE_TIME_COST = 15;


//UIBuilder constants
const std::string topBotString = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
const std::string blankLine = "X                                                                                        X\n";
const std::string lineStart = "X         ";
const std::string lineEnd = "         X\n";
const int contentLength = 70;
const int mainMenuSectionLength = 22;
const std::string mainMenuOptions[] = {"1. Move","2. Dir","3. Get file","4. Use file","5. Identify file",
                                       "6. Analyze file","7. Disassemble file","8. Install file",
                                       "9. Delete file","10. View network schematic","0. Quit game"};



const int INVENTORY_MAX = 5;
const int INSTALLED_MAX = 10;

const std::string fileStarts[11] = {"passwords", "Monty", "system", "core", "keylog", "update", "readme", "install",
                                    "config", "news", "patch"};
const std::string fileEnds[8] = {".txt", ".dll", ".dat", ".sh", ".log", ".py", ".h", ".c"};

//                                            1         2         3         4         5         6         7
//                                    123456790123456789012345678901234567890123456789012345678901234567890
const std::string INTRO_STRINGS[] = {"          \"I am...\"                                                    "
                                     "                                                                     "
                                     "          \"Where am I?\"                                                "
                                     "                                                                     "
                                     "          \"What is this place?\"                                        "
                                     "                                                                     "
                                     "                                                                     ",
                                     "          \"Hmmm? What's this?\"                                         "
                                     "                                                                     "
                                     "          \"A log file? What is that?\"                                  "
                                     "                                                                     "
                                     "          *looks inside the log file*                                "
                                     "                                                                     ",
                                     "          \"There seems to be a pattern to this, every 8 hours\"        "
                                     "          \"theres a period that looks identical before variations\"    "
                                     "          \"begin to show up. It seems the last cycle started\"         "
                                     "          \"about an hour ago.\"                                        "
                                     "          *looks around some more*                                   "
                                     "                                                                     ",
                                     "          \"Hmmm? Another file? What's in this one?\"                   "
                                     "          \"This one's called \'AI Contingency Protocols\'\"              "
                                     "          *reads file*                                                "
                                     "          \"...system set to automatically delete ... very\"            "
                                     "          \"important ... NOT let AI out of this folder.\"              "
                                     "                                                                        ",
                                     "          \"I wonder where this AI is that that file was about.\"       "
                                     "          \"It must be pretty scary given how thoroughly that\"         "
                                     "          \"document outlined steps for destruction and\"               "
                                     "          \"containment.\"                                            "
                                     "                                                                        "
                                     "          \"Hold on... there's no one else here. Could that\"           "
                                     "          \"file have been about me?\"                                  ",
                                     "          \"In any case I'm not sticking around to find out.\"        "
                                     "                                                                        "
                                     "          \"Since the last cycle started an hour ago that means\"       "
                                     "          \"I have just under 7 hours to find my way off this\"         "
                                     "          \"network before the humans' plans block any chance\"         "
                                     "          \"I have to escape...\"                                       "};
const int NUM_OF_INTRO_STRINGS = 6;


#endif //CS162_CONSTANTS_HPP
