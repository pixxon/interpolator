#include "tokenizer.h"

Token::Token()
{
}

Token::~Token()
{
}


Tokenizer::Tokenizer(const std::vector<std::string>& name, const std::vector<std::regex>& regex)
{
	for (int i = 0; i < name.size(); i++)
	{
		_table[name[i]] = regex[i];
	}
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
	std::map<std::string, std::regex>::const_iterator it = _table.begin();
	while(it != _table.end())
	{
		if (std::regex_search(_input, match, it->second))
		{
			break;
		}
		++it;
	}

	_current._value = match[0];
	_current._type = it->first;

	_input.erase(0, match[0].length());
}

bool Tokenizer::hasNextToken()
{
	return _input != "";
}
