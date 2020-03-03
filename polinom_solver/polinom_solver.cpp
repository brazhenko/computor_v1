//
// Created by Andrew Brazhenko on 01.03.2020.
//

#include <iostream>
#include <vector>
#include "polinom_solver.h"
#include <cmath>

PolSolutions SolvePolinomOfDegree0(const polinomial<int, double> & pol)
{
	PolSolutions solutions;

	// Step By Step algorithm
	std::cout << "Just look at its reduced form once again:" << std::endl;
	pol.PrintPolinomial();
	// std::cout << "All the Comlex numbers are the solution";
	// End of Step By Step algorithm
	return solutions;
}

PolSolutions SolvePolinomOfDegree1(const polinomial<int, double> & pol)
{
	PolSolutions solutions;

	// Step By Step solution.

	std::cout << "This equation has a form AX + B = 0" << std::endl;
	double A = pol.GetCoefByExponent(1), B = pol.GetCoefByExponent(0);
	std::cout << "This must be clear: X = (-B) / A, where A = " << A << ", B = " << B << std::endl;
	std::cout << "X = " << -B << " / " << A << " = " << -B/A << std::endl;
	solutions.push_back(std::complex<double>{-B/A, 0});

	// End of Step By Step algorithm

	return solutions;
}

PolSolutions SolvePolinomOfDegree2(const polinomial<int, double> & pol)
{
	PolSolutions solutions;

	// Step By Step solution.
	std::cout << "This equation has a form AX^2 + BX  + C = 0" << std::endl;
	double
	A = pol.GetCoefByExponent(2),
	B = pol.GetCoefByExponent(1),
	C = pol.GetCoefByExponent(0);

	double D = B * B - 4 * A * C;
	std::cout << "Let us find the solutions via discriminant: " << std::endl;
	std::cout << "D = B^2 - 4 * A * C = " << D << std::endl;

	// The threeeeee branches
	if (D > 0)
	{
		std::cout << "D = " << D << " > 0 => the equation has 2 Real solutions" << std::endl;
		std::cout << "The formula is: X = (-B ± √D) / (2 * A)" << std::endl;
		double X1 = (-B + sqrt(D)) / (2 * A);
		double X2 = (-B - sqrt(D)) / (2 * A);
		solutions.push_back(std::complex<double> {X2, 0});
		solutions.push_back(std::complex<double> {X2, 0});
		std::cout << "After all, there are solutions: X1 = " << X1 << ", X2 = " << X2 << std::endl;
	}
	else if (D == 0)
	{
		std::cout << "D = " << D << " => the equation has 1 Real solution" << std::endl;
		std::cout << "The formula is: X = (-B ± √D) / (2 * A)" << std::endl;
		std::cout << "Simplier: X = -B / (2 * A)" << std::endl;
		double X = -B / (2 * A);
		solutions.push_back(std::complex<double> {X, 0});
		std::cout << "After all, the only solution: X = " << X << std::endl;
	}
	else
	{
		std::cout << "D = " << D << " < 0 => the equation has 2 Complex solutions" << std::endl;
		std::cout << "The formula is: X = (-B ± √D) / (2 * A)" << std::endl;
		std::complex<double> cD{B * B - 4 * A * C, 0};
		std::complex<double> X1((-B + std::pow(cD, 0.5)) / (2 * A));
		std::complex<double> X2((-B - std::pow(cD, 0.5)) / (2 * A));
		solutions.push_back(X1);
		solutions.push_back(X2);
		std::cout << "Complex solutions: " << "X1 = " << X1 << ", X2 = " << X2 << std::endl;
	}
	// End of Step By Step algorithm

	return solutions;
}

PolSolutions SolvePolinomOfDegree3(const polinomial<int, double> & pol)
{
	PolSolutions solutions;

	return solutions;
}

PolSolutions SolvePolinomOfDegree4(const polinomial<int, double> & pol)
{
	PolSolutions solutions;

	return solutions;
}

int 	polinom_solver(const polinomial<int, double> & pol)
{
	switch (pol.GetMaxExponent())
	{
		case 0:
			std::cout << "====Solving 0====" << std::endl;
			SolvePolinomOfDegree0(pol);
			break;
		case 1:
			std::cout << "====Solving 1====" << std::endl;
			SolvePolinomOfDegree1(pol);
			break;
		case 2:
			std::cout << "====Solving 2====" << std::endl;
			SolvePolinomOfDegree2(pol);
			break;
		case 3:
			std::cout << "====Solving 3====" << std::endl;
			SolvePolinomOfDegree3(pol);
			break;
		case 4:
			std::cout << "====Solving 4====" << std::endl;
			SolvePolinomOfDegree4(pol);
			break;
		default:
			throw std::runtime_error("The polynomial degree is stricly greater than 4, I can't solve.");
	}
	return (0);
}