//
// Created by erick on 15/06/17.
//


#include "JSONManager.h"
#include "../Connections/server.h"


///   Los errores son mantequilla porque si sirve
void JSONManager::toJSON() {

		// document is the root of a json message
		rapidjson::Document document;
		
		// define the document as an object rather than an array
		document.SetObject();
		
		// create a rapidjson array type with similar syntax to std::vector
		rapidjson::Value array(rapidjson::kArrayType);
		
		// must pass an allocator when the object may need to allocate memory
		rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
		
		// chain methods as rapidjson provides a fluent interface when modifying its objects
		array.PushBack("", allocator).PushBack("world", allocator);//"array":["hello","world"]
		
		document.AddMember("type", "SELECT", allocator);
		document.AddMember("NAME", "eLpUTOaMO", allocator);
		document.AddMember("COL", "a,HB,O", allocator);
		document.AddMember("DATATYPES", "e,UH,U", allocator);
		document.AddMember("PKEY", "25", allocator);
		document.AddMember("REF", "5", allocator);
		
		// create a rapidjson object type
		
		
		StringBuffer strbuf;
		Writer<StringBuffer> writer(strbuf);
		document.Accept(writer);
		
		std::cout << strbuf.GetString() << std::endl;
	
	server b(8);
	b.validate(strbuf.GetString());
}
