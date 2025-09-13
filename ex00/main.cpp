#include "ScalarConverter.hpp"

int	main()
{
	ScalarConverter::convert("inff");
	std::cout << std::endl;
	ScalarConverter::convert("1");
	std::cout << std::endl;
	ScalarConverter::convert("'c'");
	std::cout << std::endl;
	ScalarConverter::convert("22.05f");
	std::cout << std::endl;
	ScalarConverter::convert("44.01");
	std::cout << std::endl;
	ScalarConverter::convert("ciao");
	std::cout << std::endl;
	ScalarConverter::convert("0.0");
}