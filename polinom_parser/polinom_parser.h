//
// Created by Andrew Brazhenko on 01.03.2020.
//

#ifndef COMPUTOR_POLINOM_PARSER_H
#define COMPUTOR_POLINOM_PARSER_H

#include "tokenizer/tokenizer.h"
#include "polinomial/polinomial.h"

enum ParseStates
{
	StartState,
	CoefficientState,
	MultiplicationState,
	VariableState,
	ExpCapState,
	ExpState,
	SignState,
};

enum MonomialSign
{
	SignPositive,
	SignNegative
};

enum EquStatus
{
	EquHsntAppeared,
	EquAppeared
};

polinomial polinom_parser(const std::vector<tokenizer::Token>& tokens);

#endif //COMPUTOR_POLINOM_PARSER_H
