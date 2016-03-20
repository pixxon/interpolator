#include "tokenizer.h"

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


Tokenizer::Tokenizer(SymbolTable* table):
	_current("", ""),
	_input(""),
	_table(table)
{
}

Tokenizer::~Tokenizer()
{
}

void Tokenizer::setInput(const std::string& input)
{
	_input = input;
}

Token Tokenizer::peek() const
{
	return _current;
}

void Tokenizer::next()
{
	if (_input == "")
	{
		return;
	}

	std::smatch match;
	SymbolTable::const_iterator it = _table->begin();
	while(it != _table->end())
	{
		if (std::regex_search(_input, match, it->_rgx))
		{
			break;
		}
		++it;
	}
	if (it == _table->end())
	{
		throw LexicalException("Wrong input: " + _input);
	}

	_current = Token(it->_name, match[0]);

	_input.erase(0, match[0].length());
}

bool Tokenizer::hasNext() const
{
	return _input != "";
}
