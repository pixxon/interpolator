#include "evaluator.h"


Evaluator::Evaluator(SymbolTable* table):
	_parser(table),
	_root(0),
	_table(table)
{
}

Evaluator::~Evaluator()
{
	delete _root;
}

void Evaluator::setExpression(const std::string& str)
{
	_parser.setInput(str);
	_root = _parser.getTree();
}

double Evaluator::calculate(const double& x, const double& y) const
{
	return calculateAt(_root, x, y);
}

double Evaluator::calculateAt(const Node* node, const double& x, const double& y) const
{
	if (node == nullptr)
	{
		return 0;
	}

	if (node->getToken().getType() == "num")
	{
		return stod(node->getToken().getValue());
	}

	if (node->getToken().getType() == "var")
	{
		if (node->getToken().getValue() == "x")
		{
			return x;
		}
		if (node->getToken().getValue() == "y")
		{
			return y;
		}
	}

	double lhs = calculateAt(node->getLeft(), x, y);
	double rhs = calculateAt(node->getRight(), x, y);

	return (*_table)[node->getToken().getType()]._func(lhs, rhs);
}