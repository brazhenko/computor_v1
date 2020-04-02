//
// Created by Andrew Brazhenko on 01.03.2020.
//

#include "tokenizer.h"
#include <regex>
#include <iostream>
#include <array>

#define PATTERN_VARIABLE	patterns[0]
#define PATTERN_INTEGER		patterns[1]
#define PATTERN_FLOATING	patterns[2]
#define PATTERN_CAP			patterns[3]
#define PATTERN_EQU			patterns[4]
#define PATTERN_MUL			patterns[5]
#define PATTERN_PLUS		patterns[6]
#define PATTERN_MINUS		patterns[7]
#define PATTERN_WHITESPACE	patterns[8]

namespace tokenizer
{

void PrintTokens(const std::vector<Token> &tokens)
{
	std::cout << "Tokens count: " << tokens.size() << std::endl;
	for (const auto& token: tokens)
		std::cout << "[ " << token.raw << ": " << token.token_type << " ]" << std::endl;
}

using std::regex_search;

[[nodiscard]] std::vector<Token> tokenize(const std::string &s)
{
	std::array<std::basic_regex<char>, 9> patterns{{
std::regex("X"),
std::regex("\\d+"),
std::regex("^[-+]{0}\\d+\\.\\d+"),
std::regex("\\^"),
std::regex("\\="),
std::regex("\\*"),
std::regex("\\+"),
std::regex("\\-"),
std::regex("[\n\t\v\r\f\\ ]+")
	}};

	std::vector<Token> vec;

	std::size_t i_current_pos = 0;
	while (i_current_pos < s.size())
	{
		std::cmatch match;

		if (regex_search(s.c_str() + i_current_pos,
			match,
			PATTERN_VARIABLE,
			std::regex_constants::match_continuous))
		{
			vec.push_back({match.str(), TokenType::Variable});
			i_current_pos += match.str().size();
		}
		else if (regex_search(s.c_str() + i_current_pos,
				match,
				PATTERN_CAP,
				std::regex_constants::match_continuous))
		{
			vec.push_back({match.str(), TokenType::Cap});
			i_current_pos += match.str().size();
		}
		else if (regex_search(s.c_str() + i_current_pos,
				match,
				PATTERN_EQU,
				std::regex_constants::match_continuous))
		{
			vec.push_back({match.str(), TokenType::Equ});
			i_current_pos += match.str().size();
		}
		else if (regex_search(s.c_str() + i_current_pos,
				match,
				PATTERN_MUL,
				std::regex_constants::match_continuous))
		{
			vec.push_back({match.str(), TokenType::Mul});
			i_current_pos += match.str().size();
		}
		else if (regex_search(s.c_str() + i_current_pos,
				match,
				PATTERN_PLUS,
				std::regex_constants::match_continuous))
		{
			vec.push_back({match.str(), TokenType::Plus});
			i_current_pos += match.str().size();
		}
		else if (regex_search(s.c_str() + i_current_pos,
				match,
				PATTERN_MINUS,
				std::regex_constants::match_continuous))
		{
			vec.push_back({match.str(), TokenType::Minus});
			i_current_pos += match.str().size();
		}
		else if (regex_search(s.c_str() + i_current_pos,
				match,
				PATTERN_WHITESPACE,
				std::regex_constants::match_continuous))
		{
			i_current_pos += match.str().size();
		}
		else if (regex_search(s.c_str() + i_current_pos,
				match,
				PATTERN_FLOATING,
				std::regex_constants::match_continuous))
		{
			vec.push_back({match.str(), TokenType::Floating});
			i_current_pos += match.str().size();
		}
		else if (regex_search(s.c_str() + i_current_pos,
				match,
				PATTERN_INTEGER,
				std::regex_constants::match_continuous))
		{
			vec.push_back({match.str(), TokenType::Integer});
			i_current_pos += match.str().size();
		}
		else
		{
			// PrintTokens(vec);
			throw std::runtime_error("Unknown sequence: " + std::string(s.c_str() + i_current_pos));
		}
	}
	return vec;
}

}