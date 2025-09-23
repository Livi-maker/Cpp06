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

int	ScalarConverter::isStringLiteral(std::string literal)
{
	if (literal.length() == 3)
	{
		if (literal[0] == '\'' && literal[2] == '\'')
			return (4);
	}
	else if (literal.length() == 1)
		return (5);
	return (0);
}

int	ScalarConverter::isIntLiteral(std::string literal)
{
	int		sign = 1;
	long	number = 0;

	if (!literal[0])
		return (0);
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
		{
			if (literal[i] == '-')
				sign = -1;
		}
		else if (literal[i] < '0' || literal[i] > '9')
			return (0);
		number = (number * 10) + (literal[i] - '0');
	}
	if ((number * sign) > 2147483647 || (number * sign) < -2147483648)
			return (3);
	return (1);
}

int	ScalarConverter::isFloat(std::string literal)
{
	int	dot;
	std::string	first;
	std::string second;

	dot = literal.find('.');
	if (dot != -1)
	{
		first = literal.substr(0, dot);
		second = literal.substr(dot + 1);
		dot = second.find("f");
		if (dot != -1)
		{
			second = second.substr(0, dot);
			if (isIntLiteral(first) && isIntLiteral(second))
				return (2);
		}
		else if (isIntLiteral(first) == true && isIntLiteral(second) == true)
			return (3);
	}
	return (0);
}

void	ScalarConverter::print(double p, std::string literal)
{
	std::string flag = "";
	int			pos;

	pos = literal.find(".");
	if (pos == -1 || literal.substr(pos) == ".0" || literal.substr(pos) == ".00" || literal.substr(pos) == ".0f" || literal.substr(pos) == ".00f")
		flag = ".0";
	if (p < 32 || p > 127)
		std::cout << "CHAR: non displayable" << std::endl;
	else
		std::cout << "CHAR: '" << static_cast<char> (p) << "'" << std::endl;
	if (p > 2147483647 || p < -2147483648)
		std::cout << "INT: overflow or underflow" << std::endl;
	else
		std::cout << "INT: " << static_cast<int> (p) << std::endl;
	std::cout << "DOUBLE: " << static_cast<double> (p) << flag << std::endl;
	std::cout << "FLOAT: " << static_cast<float> (p) << flag << "f" << std::endl;
}

void	ScalarConverter::exception(std::string literal)
{
	if (literal == "inff" || literal == "inf" || literal == "-inf" || literal == "-inff" || literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff")
	{
		std::cout << "FLOAT: " << atof(literal.c_str()) << "f" << std::endl;
		std::cout << "DOUBLE: " << std::strtod(literal.c_str(), NULL) << std::endl;
		std::cout << "CHAR: impossible\n" << "INT: impossible\n";
	}
	else
		std::cout << "No conversion possible" << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	int	type = 0;
	double	doubleNum;

	type += isStringLiteral(literal) + isIntLiteral(literal) + isFloat(literal);
	switch (type)
	{
	case 1:
		doubleNum = std::atoi(literal.c_str());
		print(doubleNum, literal);
		break;
	case 2:
		doubleNum = atof(literal.c_str());
		print(doubleNum, literal);
		break;
	case 3:
		doubleNum = std::strtod(literal.c_str(), NULL);
		print(doubleNum, literal);
		break;
	case 4:
		doubleNum = literal[1];
		print(doubleNum, literal);
		break;
	case 5:
		doubleNum = literal[0];
		print(doubleNum, literal);
		break;
	default:
		exception(literal);
		break;
	}
}
