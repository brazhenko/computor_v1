#include <iostream>
#include "computorv1/computorv1.h"

#define REQUIREMENT_ARGV_COUNT (2)

int main(int ac, char **av)
{
	if (ac == REQUIREMENT_ARGV_COUNT)
	{
		try
		{
			std::string expression {av[1]};
			ComputorV1(expression);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
	else
	{
		std::cerr << "usage: " << av[0] << " \"[expression]\"" << std::endl;
	}

	return 0;
}
