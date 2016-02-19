#include "tokenizer.h"

Token::Token()
{
}

Token::~Token()
{
}


Tokenizer::Tokenizer()
{
}

Tokenizer::~Tokenizer()
{
}

Token Tokenizer::peekNextToken()
{
	return _current;
}

void Tokenizer::getNextToken()
{
	int length = 1;
	while((_pos + length) <= _input.size() && anyMatch(_input.substr(_pos, length)))
	{
		length++;
	}

	_current._type = firstMatch(_input.substr(_pos, length - 1));
	_current._value = _input.substr(_pos, length - 1);
	_pos += length - 1;
}		

bool Tokenizer::anyMatch(std::string str)
{
	bool l = false;

	for(std::map<std::string, std::regex>::const_iterator it = _table.begin(); &l && it != _table.end(); ++it)
	{
		l = regex_match(str, it->second);
	}

	return l;
}

std::string Tokenizer::firstMatch(std::string str)
{
	for(std::map<std::string, std::regex>::const_iterator it = _table.begin(); it != _table.end(); ++it)
	{
		if(regex_match(str, it->second))
		{
			return it->first;
		}
	}
}
