# variable for output file name
FILENAME = The_Awakening

# source files
OBJS = UIBuilder.o Space.o SecurityRoot.o MessageProcessor.o main.o JunkItem.o Item.o InputCollector.o GenericFolder.o GameEngine.o FlashDrive.o DownloadFolder.o Character.o Root.o Menu.o
SRCS = UIBuilder.cpp Space.cpp SecurityRoot.cpp MessageProcessor.cpp main.cpp JunkItem.cpp Item.cpp InputCollector.cpp GenericFolder.cpp GameEngine.cpp FlashDrive.cpp DownloadFolder.cpp Character.cpp Root.cpp Menu.cpp
HEADERS = UIBuilder.hpp Space.hpp SecurityRoot.hpp MessageProcessor.hpp Constants.hpp JunkItem.hpp Item.hpp InputCollector.hpp GenericFolder.hpp GameEngine.hpp FlashDrive.hpp DownloadFolder.hpp Character.hpp Root.hpp Menu.hpp

# compiler variables
CC = gcc
CFLAGS = -std=c99

# c++ compilation configurations
CXX = g++
# CXXFLAGS = -std=c++0x
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

DEBUG = -g
OPTIMIZE = -03

LDFLAGS =

# leak check variables
LEAK = valgrind
FULL = --leak-check=full

# basic compilation
${FILENAME}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${FILENAME}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

# leak checks
leak:
	${LEAK} ./${FILENAME}

full:
	${LEAK} ${FULL} ./${FILENAME}

# clean
clean:
	rm *.o ${FILENAME}

# zip
zip:
	zip ${FILENAME} ${SRCS} ${HEADERS}