#include <iostream>
#include <string>
#include <stdint.h>

#ifndef SERIALIZE_H
# define SERIALIZE_H

struct Data
{
	int	num;
};

class Serialize
{
	private:
		Serialize();
		Serialize(const Serialize &other);
		Serialize	&operator=(const Serialize &other);
		~Serialize();
		
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};

#endif