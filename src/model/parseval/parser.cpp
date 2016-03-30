#include "parser.h"

#include <iostream>


ParserException::ParserException(const QString& what):
    _what(what)
{
}

ParserException::~ParserException()
{
}

const char* ParserException::what() const throw()
{
    return ("Parser exception: " + _what.toStdString()).c_str();
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

Node* Node::getLeft() const
{
	return _left;
}

Node* Node::getRight() const
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

void Parser::setInput(const QString& str)
{
	_tokenizer.setInput(str);
}

Node* Parser::parse(const int& min_prec)
{
	Node* lhs = parse_primary();
	Node* rhs;

	Token peek = _tokenizer.peek();
    while((*_table)[peek.getType()].getArity() == ARITY_BINARY && (*_table)[peek.getType()].getPrecedence() >= min_prec)
	{
		if (!_tokenizer.hasNext())
		{
			throw ParserException("Unexpected end of input!");
		}
		_tokenizer.next();

        if ((*_table)[peek.getType()].getAssociativity() == ASSOCIATIVITY_LEFT)
		{
            rhs = parse((*_table)[peek.getType()].getPrecedence() + 1);
		}
        if ((*_table)[peek.getType()].getAssociativity() == ASSOCIATIVITY_RIGHT)
		{
            rhs = parse((*_table)[peek.getType()].getPrecedence());
        }
        if ((*_table)[peek.getType()].getAssociativity() == ASSOCIATIVITY_NONE)
        {
            throw ParserException("Associativity of binary operator is none.");
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
            throw ParserException("Unmatched parenthesis!" + _tokenizer.peek().getValue());
		}


		_tokenizer.next();
		return res;
	}

    if ((*_table)[peek.getType()].getArity() == ARITY_UNARY)
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
