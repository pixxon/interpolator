#ifndef PARSER_H
#define PARSER_H

#include <exception>
#include "tokenizer.h"
#include "symbol.h"


class ParserException: public std::exception
{
	public:
		ParserException(const std::string& what);
		~ParserException();

		virtual const char* what() const throw();

	private:
		std::string _what;
};


class Node
	{
	private:

	public:
		Node* _left;
		Node* _right;
		Token _token;

		Node(Node* left, Node* right, const Token&);
		Node();
		~Node();
};


class Parser
{
	public:
		Parser(const SymbolTable&, const Tokenizer&);
		~Parser();

		Node* getTree();

	private:
		SymbolTable _table;
		Tokenizer _tokenizer;

		Node* parse(const int& min_prec);
		Node* parse_primary();
};


#endif // PARSER_H
