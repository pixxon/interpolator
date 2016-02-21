#include "tokenizer.h"
#include "symbol.h"

#include <iostream>

LexicalException::LexicalException(const std::string& what)
{
	_what = what;
}

LexicalException::~LexicalException()
{
}

const char* LexicalException::what() const throw()
{
	return _what.c_str();
}


Token::Token()
{
}

Token::Token(const std::string& type, const std::string& value)
{
	_type = type;
	_value = value;
}

Token::~Token()
{
}

std::string Token::getType() const
{
	return _type;
}

std::string Token::getValue() const
{
	return _value;
}


Tokenizer::Tokenizer()
{
}

Tokenizer::~Tokenizer()
{
}

void Tokenizer::setInput(const std::string& input)
{
	_input = input;
}

Token Tokenizer::peekNextToken()
{
	return _current;
}

void Tokenizer::advanceNextToken()
{
	std::smatch match;
	std::map<std::string, SymbolInfo>::const_iterator it = SymbolTable::table.begin();
	while(it != SymbolTable::table.end())
	{
		if (std::regex_search(_input, match, it->second._rgx))
		{
			break;
		}
		++it;
	}
	if (it == SymbolTable::table.end())
	{
		throw LexicalException("Wrong input: " + _input);
	}

	_current = Token(it->first, match[0]);

	_input.erase(0, match[0].length());
}

bool Tokenizer::hasNextToken()
{
	return _input != "";
}
