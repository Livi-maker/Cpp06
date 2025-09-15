#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	int number;
	std::string string;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& ref);
		Serializer& operator= (const Serializer& ref);
		~Serializer(void);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};