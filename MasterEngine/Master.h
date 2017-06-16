//
// Created by erick on 14/06/17.
//

#ifndef HADB_MASTER_H
#define HADB_MASTER_H

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

#include "../DataStructures/DoublyLinkedList.h"


using namespace rapidjson;

class Master {

private:
	
	//DoublyLinkedList<DiskNode> disks;
	
	/// Petition procesing and solving  \\\*

	
public:
	
	bool processPetition(Document petition);
	bool select(Document petition);
	bool join(Document petition);
	bool create(Document petition);
	bool createIndex(Document petition);
	bool dropTable(Document petition);
	bool insert(Document petition);
	bool remove(Document petition);
	bool update(Document petition);
	
	void start();

};


#endif //HADB_MASTER_H
