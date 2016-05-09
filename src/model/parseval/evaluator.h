#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "parser.h"
#include "tokenizer.h"
#include "symbol.h"

#include <QMap>
#include <QSet>
#include <QTextStream>

class TreePrinter
{
    public:
        TreePrinter();
        ~TreePrinter();

        QString toString(Node* root);
    private:
        QSet<int> set;

        void indent(QTextStream& out, int level);
        void tee(QTextStream& out, int level);
        void ell(QTextStream& out, int level);
        void print(QTextStream& out, Node* node, int level);
};

class Evaluator
{
	public:
        Evaluator();
		~Evaluator();

        void setExpression(const QString& str);
        double calculate(const double& x, const double& y);
        QString toString() const;

	private:
		Parser _parser;
		SymbolTable* _table;
		Node* _root;

        QMap<double, QMap<double, double> > _cache;


        double calculateAt(const Node* node, const double& x, const double& y);
};


#endif // EVALUATOR_H
