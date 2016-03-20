#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "parser.h"
#include "tokenizer.h"
#include "symbol.h"

#include <QMap>

class Evaluator
{
	public:
		Evaluator(SymbolTable* table);
		~Evaluator();

		void setExpression(const std::string& str);
        double calculate(const double& x, const double& y);

	private:
		Parser _parser;
		SymbolTable* _table;
		Node* _root;

        QMap<double, QMap<double, double>> _cache;


        double calculateAt(const Node* node, const double& x, const double& y);
};


#endif // EVALUATOR_H
