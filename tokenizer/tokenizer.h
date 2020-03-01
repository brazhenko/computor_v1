//
// Created by Andrew Brazhenko on 01.03.2020.
//

#ifndef COMPUTOR_TOKENIZER_H
#define COMPUTOR_TOKENIZER_H

#include <string>
#include <vector>

namespace tokenizer
{

enum TokenType
{
	Undefined = 0,
	Variable,
	Integer,
	Floating,
	Cap,
	Equ,
	Mul,
	Plus,
	Minus
};

struct Token
{
	std::string raw;
	TokenType token_type;
};

std::vector<Token> tokenize(const std::string &s);
void PrintTokens(const std::vector<Token> &tokens);

}

#endif //COMPUTOR_TOKENIZER_H
