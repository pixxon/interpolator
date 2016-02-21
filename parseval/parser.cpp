#include "parser.h"
#include "symbol.h"
#include "tokenizer.h"


Node::Node(Node* left, Node* right, std::function<double(double, double)> func)
{
	_left = left;
	_right = right;
	_func = func;
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

Node* Parser::parse(Node* lhs, int min_prec)
{
	Token peek = _tokenizer.peekNextToken();
	while(SymbolTable::table[peek.getType()]._argc == binary && SymbolTable::table[peek.getType()]._prec > min_prec)
	{
		Token op = peek;
		_tokenizer.advanceNextToken();
		Node* rhs = parse_primary();
		peek = _tokenizer.peekNextToken();
		while(SymbolTable::table[peek.getType()]._argc == binary &&
			 	(SymbolTable::table[peek.getType()]._prec > SymbolTable::table[op.getType()]._prec ||
			 	(SymbolTable::table[peek.getType()]._asso == right && SymbolTable::table[peek.getType()]._prec == SymbolTable::table[op.getType()]._prec)))
		{
			rhs = parse(rhs, SymbolTable::table[peek.getType()]._prec);
			peek = _tokenizer.peekNextToken();
		}
		lhs = new Node(lhs, rhs, SymbolTable::table[op.getType()]._func);
	}
	return lhs;
}

Node* Parser::parse_primary()
{
	Token peek = _tokenizer.peekNextToken();
	if (peek.getType() == "num")
	{
		return new Node(nullptr, nullptr, [peek](double x, double y){ return std::stod(peek.getValue()); });
	}

	if (peek.getType() == "var")
	{
		if (peek.getValue() == "x")
		{
			return new Node(nullptr, nullptr, [](double x, double y){ return x; });
		}
		else
		{
			return new Node(nullptr, nullptr, [](double x, double y){ return y; });
		}
	}

	if (peek.getType() == "open")
	{
		_tokenizer.advanceNextToken();
		Node* res = parse(parse_primary(), 0);
		_tokenizer.advanceNextToken();

		return res;
	}

	if (SymbolTable::table[peek.getType()]._argc == unary)
	{
		_tokenizer.advanceNextToken();
		return new Node(parse_primary(), nullptr, SymbolTable::table[peek.getType()]._func);
	}
}

Node* Parser::getTree()
{
	return parse(parse_primary(), 0);
}
