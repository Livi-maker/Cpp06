#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	*this = ref;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& ref)
{
	(void) ref;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(std::string literal)
{
	(void) literal;
	
	char c = 'c';
	std::cout << "CHAR: " << static_cast<char> (c) << std::endl;
	std::cout << "DOUBLE: " << static_cast<double> (c) << std::endl;
	std::cout << "INT: " << static_cast<int> (c) << std::endl;
	std::cout << "FLOAT: " << static_cast<float> (c) << std::endl;
}