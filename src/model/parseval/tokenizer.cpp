#include "tokenizer.h"

#include <QDebug>

LexicalException::LexicalException(const QString& what):
    _what(what)
{
}

LexicalException::~LexicalException() throw()
{
}

const char* LexicalException::what() const throw()
{
    return ("Lexikális hiba: " + _what.toStdString()).c_str();
}


void LexicalException::raise() const
{
    throw *this;
}


Token::Token(const QString& type, const QString& value):
    _type(type),
    _value(value)
{
}

Token::~Token()
{
}

const QString& Token::getType() const
{
	return _type;
}

const QString& Token::getValue() const
{
	return _value;
}


Tokenizer::Tokenizer():
	_current("", ""),
	_input(""),
    _table(SymbolTable::getInstance())
{
}

Tokenizer::~Tokenizer()
{
}

void Tokenizer::setInput(const QString& input)
{
	_input = input;
}

const Token Tokenizer::peek() const
{
	return _current;
}

void Tokenizer::next()
{
	if (_input == "")
	{
        _current = Token("", "");
		return;
	}

	SymbolTable::const_iterator it = _table->begin();
	while(it != _table->end())
    {
        if (it->getRegex().indexIn(_input) >= 0)
		{
			break;
		}
		++it;
	}
	if (it == _table->end())
	{
        throw LexicalException("Hibás bemenet: " + _input);
	}

    _current = Token(it->getName(), it->getRegex().cap(0));
    _input.remove(0, it->getRegex().cap(0).length());
}

bool Tokenizer::hasNext() const
{
	return _input != "";
}
