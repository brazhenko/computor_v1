//
// Created by Andrew Brazhenko on 01.03.2020.
//

#include <sstream>
#include "polinom_parser.h"
#include <iostream>

static void PushMonomial(
		polinomial<int, double>& Pol,
		enum MonomialSign sign,
		double coef,
		int exp,
		enum EquStatus equ
)
{
	// std::cout <<  std::endl << "SIGN: " << sign << "  Equ: " << equ << std::endl;
	if (
		(sign == SignPositive && equ == EquHsntAppeared) ||
		(sign == SignNegative && equ == EquAppeared)
	)
	{
		Pol.AddMonomial(exp, coef);
	}
	else if ((sign == SignPositive && equ == EquAppeared) ||
			(sign == SignNegative && equ == EquHsntAppeared)
	)
	{
		Pol.AddMonomial(exp, -coef);
	}
}

polinomial<int, double> polinom_parser(const std::vector<tokenizer::Token>& tokens)
{
	polinomial<int, double> Pol;

	ParseStates state = StartState;
	MonomialSign sign = SignPositive;
	EquStatus equ = EquHsntAppeared;

	// Temporary variables for parsing.
	int INTexp = 0;
	double DOUBcoef = 0;
	for (const auto& token: tokens)
	{
		// "Global" String stream for token parsing.
		std::stringstream ss(token.raw);

		switch (state)
		{
			// Start state
			case StartState:
			{
				INTexp = 0;
				DOUBcoef = 1;
				if (token.token_type == tokenizer::TokenType::Integer)
				{
					ss >> DOUBcoef;
					state = CoefficientState;
				}
				else if (token.token_type == tokenizer::TokenType::Floating)
				{
					ss >> DOUBcoef;
					state = CoefficientState;
				}
				else if (token.token_type == tokenizer::TokenType::Variable)
				{
					// Pass...
					INTexp = 1;
					DOUBcoef = 1;
					state = VariableState;
				}
				else if (token.token_type == tokenizer::TokenType::Minus)
				{
					sign = SignNegative;
					state = SignState;
				}
				else if (token.token_type == tokenizer::TokenType::Plus)
				{
					sign = SignPositive;
					state = SignState;
				}
				else
					throw std::runtime_error("Unexpected token near " + token.raw);
				break;
			}
			// Coefficient State
			case CoefficientState:
			{
				if (token.token_type == tokenizer::TokenType::Mul)
				{
					// Pass...
					state = MultiplicationState;
				}
				else if (token.token_type == tokenizer::TokenType::Variable)
				{
					INTexp = 1;
					state = VariableState;
				}
				else if (token.token_type == tokenizer::TokenType::Minus)
				{
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					sign = SignNegative;
					state = SignState;
				}
				else if (token.token_type == tokenizer::TokenType::Plus)
				{
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					sign = SignPositive;
					state = SignState;
				}
				else if (token.token_type == tokenizer::TokenType::Equ)
				{
					if (equ == EquAppeared)
						throw std::runtime_error("Repeating sign =");
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					equ = EquAppeared;
					state = StartState;
					sign = SignPositive;
				}
				else
					throw std::runtime_error("Unexpected token near " + token.raw);
				break;
			}
			// Multiplication State
			case MultiplicationState:
			{
				if (token.token_type == tokenizer::TokenType::Variable)
				{
					// Pass...
					INTexp = 1;
					state = VariableState;
				}
				else
					throw std::runtime_error("Unexpected token near " + token.raw);
				break;
			}
			// Variable State
			case VariableState:
			{
				if (token.token_type == tokenizer::TokenType::Cap)
				{
					// Pass...
					state = ExpCapState;
				}
				else if (token.token_type == tokenizer::TokenType::Plus)
				{
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					sign = SignPositive;
					state = SignState;
				}
				else if (token.token_type == tokenizer::TokenType::Minus)
				{
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					sign = SignNegative;
					state = SignState;
				}
				else if (token.token_type == tokenizer::TokenType::Equ)
				{
					if (equ == EquAppeared)
						throw std::runtime_error("Repeating sign =");
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					equ = EquAppeared;
					state = StartState;
					sign = SignPositive;
				}
				else
					throw std::runtime_error(
							"Unexpected token near " + token.raw);
				break;
			}
			// Exponential Cap State
			case ExpCapState:
			{
				if (token.token_type == tokenizer::TokenType::Integer)
				{
					ss >> INTexp;
					state = ExpState;
				}
				else
					throw std::runtime_error("Unexpected token near " + token.raw);
				break;
			}
			// Exponent State
			case ExpState:
			{
				if (token.token_type == tokenizer::TokenType::Minus)
				{
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					sign = SignNegative;
					state = SignState;
				}
				else if (token.token_type == tokenizer::TokenType::Plus)
				{
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					sign = SignPositive;
					state = SignState;
				}
				else if (token.token_type == tokenizer::TokenType::Equ)
				{
					if (equ == EquAppeared)
						throw std::runtime_error("Repeating sign =");
					PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);
					equ = EquAppeared;
					state = StartState;
					sign = SignPositive;
				}
				else
					throw std::runtime_error("Unexpected token near " + token.raw);
				break;
			}
			// Sign State
			case SignState:
			{
				DOUBcoef = 0;
				INTexp = 0;
				if (token.token_type == tokenizer::TokenType::Integer)
				{
					ss >> DOUBcoef;
					state = CoefficientState;
				}
				else if (token.token_type == tokenizer::TokenType::Floating)
				{
					ss >> DOUBcoef;
					state = CoefficientState;
				}
				else if (token.token_type == tokenizer::TokenType::Variable)
				{
					// Pass...
					INTexp = 1;
					DOUBcoef = 1;
					state = VariableState;
				}
				else
					throw std::runtime_error("Unexpected token near " + token.raw);
				break;
			}
		}
	}
	// Adding last monomial to polinomial
	PushMonomial(Pol, sign, DOUBcoef, INTexp, equ);

	return Pol;
}