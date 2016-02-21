#ifndef PARSER_H
#define PARSER_H


#include "tokenizer.h"
#include <functional>


class Node
	{
	private:
		std::function<double(double, double)> _func;

	public:
		Node* _left;
		Node* _right;

		Node(Node* left, Node* right, std::function<double(double, double)> func);
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

		Node* parse(Node* lhs, int min_prec);
		Node* parse_primary();
};


#endif // PARSER_H
