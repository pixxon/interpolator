#include "parser.h"
#include "symbol.h"
#include "tokenizer.h"

#include <iostream>


Node::Node(Node* left, Node* right, Token token)
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


Parser::Parser(Tokenizer tokenizer)
{
	_tokenizer = tokenizer;
}

Parser::~Parser()
{
}

Node* Parser::parse(int min_prec)
{
	Node* lhs = parse_primary();

	Token peek = _tokenizer.peekNextToken();
	while(SymbolTable::table[peek.getType()]._argc == binary && SymbolTable::table[peek.getType()]._prec > min_prec && _tokenizer.hasNextToken())
	{
		_tokenizer.advanceNextToken();

		Node* rhs;
		if (SymbolTable::table[peek.getType()]._asso == left)
		{
			rhs = parse(min_prec + 1);
		}
		else
		{
			rhs = parse(min_prec);
		}

		lhs = new Node(lhs, rhs, peek);
		peek = _tokenizer.peekNextToken();
	}
	return lhs;
}

Node* Parser::parse_primary()
{
	Token peek = _tokenizer.peekNextToken();
	if (peek.getType() == "num" || peek.getType() == "var")
	{
		if (_tokenizer.hasNextToken())
		{
			_tokenizer.advanceNextToken();
		}
		return new Node(nullptr, nullptr, peek);
	}

	if (peek.getType() == "open")
	{
		if (_tokenizer.hasNextToken())
		{
			_tokenizer.advanceNextToken();
		}

		Node* res = parse(0);

		if (_tokenizer.hasNextToken())
		{
			_tokenizer.advanceNextToken();
		}

		return res;
	}

	if (SymbolTable::table[peek.getType()]._argc == unary)
	{
		if (_tokenizer.hasNextToken())
		{
			_tokenizer.advanceNextToken();
		}

		return new Node(parse_primary(), nullptr, peek);
	}
}

Node* Parser::getTree()
{
	_tokenizer.advanceNextToken();
	return parse(0);
}
