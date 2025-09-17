#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int		id;
	time_t	timestamp;

	std::srand(time(&timestamp));
	id = (std::rand() % 3 + 1);
	switch (id)
	{
	case 1:
		return (new(A));

	case 2:
		return (new(B));

	case 3:
		return (new(C));
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A class" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B class" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C class" << std::endl;
	else
		std::cout << "type not recognized\n";
}

void	identify(Base& p)
{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A class" << std::endl;
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B class" << std::endl;
	else if (dynamic_cast<C *>(&p) != NULL)
		std::cout << "C class" << std::endl;
	else
		std::cout << "type not recognized\n";
}

int main()
{
	Base*	random = generate();

	identify(random);
	identify(*random);
	delete (random);

	identify(NULL);
}