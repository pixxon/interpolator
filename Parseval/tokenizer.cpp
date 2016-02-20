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

void Tokenizer::advanceNextToken()
{
	std::smatch match;
	for(int i = 0; i < regexes.size(); i++)
	{
		if (std::regex_search(input, match, regexes[i]))
		{
			break;
		}
	}

	_current._value = match[0];
	input.erase(0, match[0].length());
}

bool Tokenizer::hasNextToken()
{
	return _input != "";
}
