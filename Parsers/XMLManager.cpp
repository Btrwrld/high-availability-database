//
// Created by erick on 13/06/17.
//

#include "XMLManager.h"


 void XMLManager::parse(const char *archive) {
	
	cout << "Parsing my beer journal..." << endl;
	
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (archive);
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("MyBeerJournal");
	// Iterate over the brewerys
	for (xml_node<> * brewery_node = root_node->first_node("Brewery"); brewery_node; brewery_node = brewery_node->next_sibling())
	{
		printf("I have visited %s in %s. ",
		       brewery_node->first_attribute("name")->value(),
		       brewery_node->first_attribute("location")->value());
		// Interate over the beers
		for(xml_node<> * beer_node = brewery_node->first_node("Beer"); beer_node; beer_node = beer_node->next_sibling())
		{
			printf("On %s, I tried their %s which is a %s. ",
			       beer_node->first_attribute("dateSampled")->value(),
			       beer_node->first_attribute("name")->value(),
			       beer_node->first_attribute("description")->value());
			printf("I gave it the following review: %s", beer_node->value());
		}
		cout << endl;
	}
	
}

 void XMLManager::generateTableMetadata(const char* json) {
	 
	 Document petition;
	 petition.Parse(json);
	 xml_document<> doc;
	 
	ofstream writer;
	ostringstream reader("");
		
	ifstream archive;
	archive.open("/home/erick/CLionProjects/HADB/master.metadata");
	 if(archive.is_open()){
		 string text = "";
		
		 getline(archive, text);
		 while(text != "</DatabaseMetadata>" ){
			 reader << text << endl;
			 getline(archive, text);
		 }
	 }
	 else{
		
		
		 cout << "Could not find any `master.metadata` creating new archive...." << endl;
		
		 reader << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<DatabaseMetadata>\n";
		 
	 }
	
	
	archive.close();
	remove("/home/erick/CLionProjects/HADB/master.metadata");
	 
	 reader << "\t"<< "<TABLE>" << "\n";
	 
	//write the table´s name
	reader << "\t\t"<< "<NAME>" << petition["NAME"].GetString() << "</TABLE>" <<"\n";
	
	//write table`s data name
	reader << "\t\t<COL>" << petition["COL"].GetString() << "</COL>\n";
	
	//write table`s datatype
	reader << "\t\t<DATATYPES>" << petition["DATATYPES"].GetString() << "</DATATYPES>\n";
	
	//write table`s primary key
	reader << "\t\t<PK>" << petition["PK"].GetString() << "</PK>\n";
	
	//write table`s primary key
	reader << "\t\t<REF>" << petition["REF"].GetString() << "</REF>\n";
	
	//close table
	reader << "\t</TABLE>\n";
	
	reader << "</DatabaseMetadata>";
	
	writer.open("/home/erick/CLionProjects/HADB/master.metadata");
	writer << reader.str();
	writer.close();
	
	
}
