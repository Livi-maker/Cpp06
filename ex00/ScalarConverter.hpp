#pragma once

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& ref);
		ScalarConverter& operator= (const ScalarConverter& ref);
		~ScalarConverter(void);

	public:
		static void convert(std::string literal);
};