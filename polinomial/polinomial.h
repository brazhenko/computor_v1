//
// Created by Andrew Brazhenko on 01.03.2020.
//

#ifndef COMPUTOR_POLINOMIAL_H
#define COMPUTOR_POLINOMIAL_H

#include <string>
#include <map>
#include <iostream>
#include <cmath>

template <typename Exp, typename Coef>
class polinomial
{
public:
	explicit polinomial() = default;

	void AddMonomial(Exp exponent, Coef coefficient)
	{
		// std::cout << __FUNCTION__ << "  exp: " << exponent << " coef: " << coefficient << std::endl;

		data[exponent] += coefficient;
		if (data[exponent] == 0)
			data.erase(exponent);
	}

	void PrintPolinomial() const
	{
		for (auto it = data.begin(); it != data.end(); it++)
		{
			if (it == data.begin())
			{
				if (it->first == 0)
					std::cout << it->second;
				else if (it->first == 1)
					std::cout << it->second << " * " << "X";
				else
					std::cout << it->second << " * " << "X^" << it->first;
			}
			else
			{
				if (it->second > 0)
				{
					std::cout << " + " ;//<< it->second << " * " << "X^" << it->first;
				}
				else
					std::cout << " - " ;//<< -it->second << " * " << "X^" << it->first;

				///
				if (it->first == 0)
					std::cout << std::fabs(it->second);
				else if (it->first == 1)
					std::cout << std::fabs(it->second) << " * " << "X";
				else
					std::cout << std::fabs(it->second) << " * " << "X^" << it->first;
			}
		}
		std::cout << " = 0" << std::endl;
	}


	[[nodiscard]] Exp GetMaxExponent() const
	{
		Exp rc = 0;

		if (data.empty())
			return rc;

		const auto rit = data.rbegin();
		rc = rit->first;

		return rc;
	}

	[[nodiscard]] std::size_t MonomialCount() const
	{
		return data.size();
	}

	[[nodiscard]] Coef GetCoefByExponent(Exp exp) const
	{
		try
		{
			return data.at(exp);
		}
		catch (...)
		{
			return 0;
		}
	}
private:
	std::string var_name;
	std::map<Exp, Coef> data;
};

#endif //COMPUTOR_POLINOMIAL_H
