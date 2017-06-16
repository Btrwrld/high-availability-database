cmake_minimum_required(VERSION 3.6)
project(HADB)

set(CMAKE_CXX_FLAGS "-O0 -std=c++14")

set(SOURCE_FILES main.cpp DataStructures/DoubleNode.h DataStructures/DoublyLinkedList.h DataStructures/Queue.h DataStructures/QueueNode.h
        DataStructures/Stack.h DataStructures/BtreeNode.h DataStructures/Tuple.h DataStructures/Btree.h Parsers/XMLManager.h Parsers/XMLManager.cpp
        DataStructures/BtreeTest.h Connections/client.h Connections/client.cpp Connections/server.h Connections/server.cpp MasterEngine/Master.cpp
        MasterEngine/Master.h
        Parsers/JSONManager.cpp Parsers/JSONManager.h)

# Find RapidXML header
find_path(RapidXML_INCLUDE_DIR rapidxml-1.13/rapidxml.hpp ${HEADER_SEARCH_PATH})
# Find RapidXML library
find_library(RapidXML_LIBRARIES rapidxml-1.13 ${LIBRARY_SEARCH_PATH})


# Include directories for this project
set(INCLUDE_PATH
        ${RapidXML_INCLUDE_DIR}
        )
# Libraries needed on all platforms for this project
set(LIBRARIES
        ${RapidXML_LIBRARIES}
        )

add_executable(HADB ${SOURCE_FILES})

# Libraries to be linked
target_link_libraries(HADB
        ${LIBRARIES}
        )