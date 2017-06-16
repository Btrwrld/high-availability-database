//
// Created by erick on 13/06/17.
//

#ifndef HADB_XMLMANAGER_H
#define HADB_XMLMANAGER_H


#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "rapidxml-1.13/rapidxml.hpp"
#include <rapidjson/document.h>


using namespace rapidxml;
using namespace rapidjson;
using namespace std;

class XMLManager {

public:
	 void parse(const char *archive);
	
	 void generateTableMetadata(const char * json);

};


#endif //HADB_XMLMANAGER_H
