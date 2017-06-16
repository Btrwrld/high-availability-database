//
// Created by erick on 01/06/17.
//
#include <cstdint>
#include "Parsers/XMLManager.h"
#include "DataStructures/BtreeTest.h"
#include "Connections/server.h"
#include "Parsers/JSONManager.h"

int main(){
	
	/*
	XMLParser* a;
	a->parse("/home/erick/CLionProjects/HADB/beerJournal.xml");
	*/
	
	
	
	JSONManager a;
	a.toJSON();
	
	return 0;
}
