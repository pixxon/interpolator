#include "evaluator.h"

#include <QDebug>


Evaluator::Evaluator(SymbolTable* table):
    _parser(table),
    _table(table),
    _root(0)
{
}

Evaluator::~Evaluator()
{
	delete _root;
}

void Evaluator::setExpression(const QString& str)
{
	_parser.setInput(str);
	_root = _parser.getTree();

    for (QMap<double, QMap<double, double>>::iterator it = _cache.begin(); it != _cache.end(); it++)
    {
        it->clear();
    }
    _cache.clear();
}

double Evaluator::calculate(const double& x, const double& y)
{
    if (_cache.contains(x) && _cache[x].contains(y))
    {
        return _cache[x][y];
    }

    double tmp = calculateAt(_root, x, y);
    _cache[x][y] = tmp;
    return tmp;
}

double Evaluator::calculateAt(const Node* node, const double& x, const double& y)
{
	if (node == nullptr)
	{
		return 0;
	}

	if (node->getToken().getType() == "num")
	{
        return (node->getToken().getValue()).toDouble();
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

    return (*_table)[node->getToken().getType()].getFunction()(lhs, rhs);
}
