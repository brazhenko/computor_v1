//
// Created by Andrew Brazhenko on 01.03.2020.
//

#include "tokenizer/tokenizer.h"
#include "polinom_parser/polinom_parser.h"
#include "polinom_solver/polinom_solver.h"
#include <iostream>
#include <exception>

void	ComputorV1(const std::string& exp)
{
	try
	{
		std::vector<tokenizer::Token> tokens = tokenizer::tokenize(exp);
		// PrintTokens(tokens);
		polinomial<int, double>  Pol = polinom_parser(tokens);
		Pol.PrintPolinomial();
		polinom_solver(Pol);
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}