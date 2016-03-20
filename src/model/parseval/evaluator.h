#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "parser.h"
#include "tokenizer.h"
#include "symbol.h"

class Evaluator
{
	public:
		Evaluator(SymbolTable* table);
		~Evaluator();

		void setExpression(const std::string& str);
		double calculate(const double& x, const double& y) const;

	private:
		Parser _parser;
		SymbolTable* _table;
		Node* _root;

		double calculateAt(const Node* node, const double& x, const double& y) const;
};


#endif // EVALUATOR_H