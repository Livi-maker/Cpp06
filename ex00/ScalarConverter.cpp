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
	return (0);
}

int	ScalarConverter::isIntLiteral(std::string literal)
{
	int		sign = 1;
	long	number = 0;

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
		{
			if (literal[i] == '-')
				sign = -1;
		}
		else if (literal[i] < '0' || literal[i] > '9')
			return (0);
		if ((number * sign) > 2147483647 || (number * sign) < -2147483648)
			return (0);
		number = (number * 10) + (literal[i] - '0');
	}
	if ((number * sign) > 2147483647 || (number * sign) < -2147483648)
			return (0);
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
		if (dot != -1 && (second.length() == 2 || second.length() == 3))
		{
			second = second.substr(0, dot);
			if (isIntLiteral(first) && isIntLiteral(second))
				return (2);
		}
	}
	return (0);
}

int	ScalarConverter::isDouble(std::string literal)
{
	int	dot;
	std::string	first;
	std::string second;

	dot = literal.find('.');
	if (dot != -1)
	{
		first = literal.substr(0, dot);
		second = literal.substr(dot + 1);
		if (second.length() == 1 || second.length() == 2)
			if (isIntLiteral(first) == true && isIntLiteral(second) == true)
				return (3);
	}
	return (0);
}

void	ScalarConverter::print(int p)
{
	if (p < 32 || p > 127)
		std::cout << "CHAR: non displayable" << std::endl;
	else
		std::cout << "CHAR: '" << static_cast<char> (p) << "'" << std::endl;
	std::cout << "DOUBLE: " << static_cast<double> (p) << ".0" << std::endl;
	std::cout << "INT: " << static_cast<int> (p) << std::endl;
	std::cout << "FLOAT: " << static_cast<float> (p) << ".0f" << std::endl;
}

void	ScalarConverter::print(double p, std::string literal)
{
	std::string flag = "";
	int			pos;

	pos = literal.find(".");
	if (pos == -1 || literal.substr(pos) == ".0")
		flag = ".0";
	if (p < 32 || p > 127)
		std::cout << "CHAR: non displayable" << std::endl;
	else
		std::cout << "CHAR: '" << static_cast<char> (p) << "'" << std::endl;
	std::cout << "INT: " << static_cast<int> (p) << std::endl;
	std::cout << "DOUBLE: " << static_cast<double> (p) << flag << std::endl;
	std::cout << "FLOAT: " << static_cast<float> (p) << flag << "f" << std::endl;
}

void	ScalarConverter::print(float p, std::string literal)
{
	std::string flag = "";
	int			pos;

	pos = literal.find(".");
	if (pos == -1 || literal.substr(pos) == ".0f")
		flag = ".0";
	if (p < 32 || p > 127)
		std::cout << "CHAR: non displayable" << std::endl;
	else
		std::cout << "CHAR: '" << static_cast<char> (p) << "'" << std::endl;
	std::cout << "DOUBLE: " << static_cast<double> (p) << flag << std::endl;
	std::cout << "INT: " << static_cast<int> (p) << std::endl;
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
	int p = 0;
	float	floatNum;
	double	doubleNum;

	type += isStringLiteral(literal) + isIntLiteral(literal) + isDouble(literal) + isFloat(literal);
	switch (type)
	{
	case 1:
		p = std::atoi(literal.c_str());
		print(p);
		break;
	case 2:
		floatNum = atof(literal.c_str());
		print(floatNum, literal);
		break;
	case 3:
		doubleNum = std::strtod(literal.c_str(), NULL);
		print(doubleNum, literal);
		break;
	case 4:
		p = literal[1];
		print(p);
		break;
	default:
		exception(literal);
		break;
	}
}
