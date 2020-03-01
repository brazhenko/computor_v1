//
// Created by Andrew Brazhenko on 01.03.2020.
//

#ifndef COMPUTOR_POLINOMIAL_H
#define COMPUTOR_POLINOMIAL_H

#include <string>
#include <map>

class polinomial
{
public:
	explicit polinomial() = default;

	void AddMonomial(int exponent, double coefficient);
	void PrintPolinomial() const;
	[[nodiscard]] int GetMaxExponent() const;
	[[nodiscard]] std::size_t MonomialCount() const;
private:
	std::string var_name;
	std::map<int, double> data;
};

#endif //COMPUTOR_POLINOMIAL_H
