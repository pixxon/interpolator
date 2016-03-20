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
		Node* _left;
		Node* _right;
		Token _token;

	public:
		Node(Node* left, Node* right, const Token&);
		~Node();

		const Node* getLeft() const;
		const Node* getRight() const;
		const Token& getToken() const;
};


class Parser
{
	public:
		Parser(SymbolTable*);
		~Parser();

		Node* getTree();
		void setInput(const std::string& str);

	private:
		SymbolTable* _table;
		Tokenizer _tokenizer;

		Node* parse(const int& min_prec);
		Node* parse_primary();
};


#endif // PARSER_H
