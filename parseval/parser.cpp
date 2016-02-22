#include "parser.h"

#include <iostream>


ParserException::ParserException(const std::string& what)
{
	_what = what;
}

ParserException::~ParserException()
{
}

const char* ParserException::what() const throw()
{
	return _what.c_str();
}


Node::Node(Node* left, Node* right, const Token& token)
{
	_left = left;
	_right = right;
	_token = token;
}

Node::Node()
{
	_left = nullptr;
	_right = nullptr;
}

Node::~Node()
{
	if (_left != nullptr)
	{
		delete _left;
	}
	if (_right != nullptr)
	{
		delete _right;
	}
}


Parser::Parser(const SymbolTable& table, const Tokenizer& tokenizer)
{
	_table = table;
	_tokenizer = tokenizer;
}

Parser::~Parser()
{
}

Node* Parser::parse(const int& min_prec)
{
	Node* lhs = parse_primary();
	Node* rhs;

	Token peek = _tokenizer.peekNextToken();
	while(_table[peek.getType()]._argc == binary && _table[peek.getType()]._prec >= min_prec)
	{
		if (!_tokenizer.hasNextToken())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.advanceNextToken();

		if (_table[peek.getType()]._asso == left)
		{
			rhs = parse(_table[peek.getType()]._prec + 1);
		}
		else
		{
			rhs = parse(_table[peek.getType()]._prec);
		}

		lhs = new Node(lhs, rhs, peek);
		peek = _tokenizer.peekNextToken();
	}

	if(_tokenizer.hasNextToken())
	{
		throw ParserException("Expected: binary, got: " + peek.getType());
	}

	return lhs;
}

Node* Parser::parse_primary()
{
	Token peek = _tokenizer.peekNextToken();
	if (peek.getType() == "num" || peek.getType() == "var")
	{
		_tokenizer.advanceNextToken();
		return new Node(nullptr, nullptr, peek);
	}

	if (peek.getType() == "min")
	{
		if (!_tokenizer.hasNextToken())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.advanceNextToken();
		return new Node(nullptr, parse_primary(), peek);
	}

	if (peek.getType() == "open")
	{
		if (!_tokenizer.hasNextToken())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.advanceNextToken();

		Node* res = parse(0);

		if (_tokenizer.peekNextToken().getType() != "close")
		{
			throw ParserException("Unmatched parenthesis!");
		}


		_tokenizer.advanceNextToken();
		return res;
	}

	if (_table[peek.getType()]._argc == unary)
	{
		if (!_tokenizer.hasNextToken())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.advanceNextToken();

		return new Node(parse_primary(), nullptr, peek);
	}

	throw ParserException("Unexpected token: " + peek.getValue() + "!");
}

Node* Parser::getTree()
{
	_tokenizer.advanceNextToken();
	return parse(0);
}
