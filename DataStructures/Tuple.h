//
// Created by erick on 01/06/17.
//

#ifndef HADB_TUPLE_H
#define HADB_TUPLE_H


#include <cstddef>

template <class T , class U>
class Tuple{
	U value;
	T key;

public:
	Tuple(T key , U value ) : key(key), value(value) {}
	
};

#endif //HADB_TUPLE_H
