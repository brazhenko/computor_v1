//
// Created by Andrew Brazhenko on 01.03.2020.
//

#include <iostream>
#include "polinom_solver.h"



int 	polinom_solver(const polinomial& pol)
{
	switch (pol.GetMaxExponent())
	{
		case 0:
			std::cout << "Solving 0" << std::endl;
			break;
		case 1:
			std::cout << "Solving 1" << std::endl;
			break;
		case 2:
			std::cout << "Solving 2" << std::endl;
			break;
		case 3:
			std::cout << "Solving 3" << std::endl;
			break;
		case 4:
			std::cout << "Solving 4" << std::endl;
			break;
		default:
			std::cerr << "exponent is to big...." << std::endl;
			break;
	}
	return (0);
}