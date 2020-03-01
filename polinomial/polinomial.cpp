//
// Created by Andrew Brazhenko on 01.03.2020.
//

#include "polinomial.h"
#include <iostream>

void polinomial::AddMonomial(int exponent, double coefficient)
{
	std::cout << __FUNCTION__ << "  exp: " << exponent << " coef: " << coefficient << std::endl;

	data[exponent] += coefficient;
	if (data[exponent] == 0)
		data.erase(exponent);
}

int polinomial::GetMaxExponent() const
{
	int rc = 0;

	if (data.empty())
		return rc;

	const auto rit = data.rbegin();
	rc = rit->first;

	return rc;
}

[[nodiscard]] std::size_t polinomial::MonomialCount() const
{
	return data.size();
}

void polinomial::PrintPolinomial() const
{
	for (const auto& mon: data)
	{
		std::cout << mon.second << " * X" << var_name << "^" << mon.first << ", ";
	}
	std::cout << std::endl;
}