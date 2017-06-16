//
// Created by erick on 14/06/17.
//

#include "Master.h"


void Master::start() {
	
	bool flag = true;
	
	while(flag){
		
		Document petition;
		//d.Parse(json);
	
	}
	
	
}/*
/// Petition procesing and solving  \\\*
bool Master::processPetition(Document petition) {
	
	bool state = false;
	Value& type = petition["TYPE"];
	string petitionType = type.GetString();
	
	if(strcmp(type.GetString(),"SELECT")==0){

		bool isJoining;
		isJoining = strcmp( petition["JOIN"].GetString(),"true") == 0;
		
		if(isJoining){
			this->join(petition);
		}
		else{
			state = this->select(petition);
		}
		
	}
	
	else if(strcmp(type.GetString(),"CREATE")==0){
		
		try{
			state = this->create(petition);
		}
		catch (int e){
		
		
		}

	}
	else if(strcmp(type.GetString(),"CREATE INDEX")==0){
		try{
			state = this->createIndex(petition);
		}
		catch (int e){
		
		
		}

	}
	else if(strcmp(type.GetString(),"DROP TABLE")==0){
		try{
			state = dropTable(petition);
		}
		catch (int e){
		
		
		}
	}
	else if(strcmp(type.GetString(),"INSERT")==0){
		try{
			state = this->insert(petition);
		}
		catch (int e){
		
		
		}
	}
	else if(strcmp(type.GetString(),"DELETE")==0){
		try{
			state = this->remove(petition);
		}
		catch (int e){
		
		
		}
	
	}
	else if(strcmp(type.GetString(),"UPDATE")==0){
		try{
			state = this->update(petition);
		}
		catch (int e){
		
		
		}
	
	}
	else{
		state = false;
		cout << "Could not determine the requested petition" << endl;
	}
	
	if(state){
		cout << petitionType << " petition successful" << endl;
	}
	else{
		cout << petitionType << " petition gone wrong" << endl;
	}
	
	return state;
	
}

bool Master::select(Document petition) {
	bool result = false;
	
	try {
		
		// se solicita la tabla que se necesita al disk node
		
		// se recibe la tabla
		Document table;
		
		Value& col = petition["COL"];
		Value colsReq(kArrayType);
		colsReq = col.GetArray();
		
		Value& colum = table["COL"];
		Value colsEnc(kArrayType);
		colsEnc = colum.GetArray();
		
		result = !result;
		//d.Parse(json);
	
	}
	catch( int e){
	
	
	}
	
	return result;
}

bool Master::join(Document petition) {
	bool result = false;
	
	try {
	
	}
	catch( int e){
	
	
	}
	
	return result;
}

bool Master::create(Document petition) {
	bool result = false;
	try {
	
	}
	catch( int e){
	
	
	}
	
	return result;
}

bool Master::createIndex(Document petition) {
	bool result = false;
	try {
	
	}
	catch( int e){
	
	
	}
	
	return result;
}

bool Master::dropTable(Document petition) {
	bool result = false;
	try {
	
	}
	catch( int e){
	
	
	}
	
	return result;
}

bool Master::insert(Document petition) {
	bool result = false;
	try {
	
	}
	catch( int e){
	
	
	}
	
	return result;
}

bool Master::remove(Document petition) {
	bool result = false;
	try {
	
	}
	catch( int e){
	
	
	}
	
	return result;
}

bool Master::update(Document petition) {
	bool result = false;
	try {
	
	}
	catch( int e){
	
	
	}
	
	return result;
}
*/
