#ifndef PARSER_H
#define PARSER_H


#include "tokenizer.h"


class Node
	{
	private:

	public:
		Node* _left;
		Node* _right;
		Token _token;

		Node(Node* left, Node* right, Token);
		Node();
		~Node();
};


class Parser
{
	public:
		Parser(Tokenizer);
		~Parser();

		Node* getTree();

	private:
		Tokenizer _tokenizer;

		Node* parse(int min_prec);
		Node* parse_primary();
};


#endif // PARSER_H
