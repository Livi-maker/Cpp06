#include "Serializer.hpp"

int main()
{
	Data* data = new Data;

	data->number = 42;
	data->string = "hello";

	std::cout << data->string << " " << data->number << std::endl;
	std::cout << data << std::endl;
	uintptr_t	adress= Serializer::serialize(data);
	std::cout << adress << std::endl;
	Data* ptr = Serializer::deserialize(adress);
	std::cout << ptr->string << " " << ptr->number << std::endl;
}

