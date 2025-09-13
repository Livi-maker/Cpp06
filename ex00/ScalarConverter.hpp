#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& ref);
		ScalarConverter& operator= (const ScalarConverter& ref);
		~ScalarConverter(void);

		static int	isStringLiteral(std::string literal);
		static int	isIntLiteral(std::string literal);
		static int	isDouble(std::string literal);
		static int	isFloat(std::string literal);
		static void	print(int p);
		static void	print(float p, std::string literal);
		static void	print(double p, std::string literal);
		static void	exception(std::string literal);

	public:
		static void convert(std::string literal);
};