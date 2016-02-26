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


Node::Node(Node* left, Node* right, const Token& token):
	_left(left),
    _right(right),
    _token(token)
{
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

const Node* Node::getLeft() const
{
	return _left;
}

const Node* Node::getRight() const
{
	return _right;
}

const Token& Node::getToken() const
{
	return _token;
}

Parser::Parser(SymbolTable* table):
    _table(table),
    _tokenizer(table)
{
}

Parser::~Parser()
{
}

void Parser::setInput(const std::string& str)
{
	_tokenizer.setInput(str);
}

Node* Parser::parse(const int& min_prec)
{
	Node* lhs = parse_primary();
	Node* rhs;

	Token peek = _tokenizer.peek();
	while((*_table)[peek.getType()]._argc == binary && (*_table)[peek.getType()]._prec >= min_prec)
	{
		if (!_tokenizer.hasNext())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.next();

		if ((*_table)[peek.getType()]._asso == left)
		{
			rhs = parse((*_table)[peek.getType()]._prec + 1);
		}
		else
		{
			rhs = parse((*_table)[peek.getType()]._prec);
		}

		lhs = new Node(lhs, rhs, peek);
		peek = _tokenizer.peek();
	}

	return lhs;
}

Node* Parser::parse_primary()
{
	Token peek = _tokenizer.peek();
	if (peek.getType() == "num" || peek.getType() == "var")
	{
		_tokenizer.next();
		return new Node(nullptr, nullptr, peek);
	}

	if (peek.getType() == "min")
	{
		if (!_tokenizer.hasNext())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.next();
		return new Node(nullptr, parse_primary(), peek);
	}

	if (peek.getType() == "open")
	{
		if (!_tokenizer.hasNext())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.next();

		Node* res = parse(0);

		if (_tokenizer.peek().getType() != "close")
		{
			throw ParserException("Unmatched parenthesis!");
		}


		_tokenizer.next();
		return res;
	}

	if ((*_table)[peek.getType()]._argc == unary)
	{
		if (!_tokenizer.hasNext())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.next();

		return new Node(parse_primary(), nullptr, peek);
	}

	throw ParserException("Unexpected token: " + peek.getValue() + "!");
}

Node* Parser::getTree()
{
	_tokenizer.next();
	return parse(0);
}
