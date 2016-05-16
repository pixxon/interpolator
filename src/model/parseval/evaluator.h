#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "parser.h"
#include "tokenizer.h"
#include "symbol.h"

#include <QMap>
#include <QSet>
#include <QTextStream>

namespace Model
{
    namespace Parseval
    {
        /**
         * @brief The TreePrinter class is used to create a string from a syntax tree.
         */
        class TreePrinter
        {
            public:
                TreePrinter();
                ~TreePrinter();

                /**
                 * @brief toString Returns a string containing the tree.
                 */
                QString toString(Node*);
            private:
                /**
                 * @brief set Stores current levels.
                 */
                QSet<int> set;

                /**
                 * @brief indent Sets spacing for the node.
                 */
                void indent(QTextStream&, int);

                /**
                 * @brief left Prints left child spacing.
                 */
                void left(QTextStream&, int);

                /**
                 * @brief right Prints right child spacing.
                 */
                void right(QTextStream&, int);

                /**
                 * @brief print Prints a node at given level.
                 */
                void print(QTextStream&, Node*, int);
        };

        /**
         * @brief The Evaluator class can store a syntax tree and calculate its value.
         */
        class Evaluator
        {
            public:
                /**
                 * @brief Evaluator Stores a pointer to the symboltable.
                 */
                Evaluator();

                /**
                 * @brief ~Evaluator Deletes the stored tree.
                 */
                ~Evaluator();

                /**
                 * @brief setExpression Creates a new tree and stores it.
                 */
                void setExpression(const QString&);

                /**
                 * @brief calculate Returns the value of the expression at given point.
                 */
                double calculate(const double&, const double&);

                /**
                 * @brief toString Returns the syntax tree in a string.
                 */
                QString toString() const;

            private:
                /**
                 * @brief _parser Parser to create syntax tree.
                 */
                Parser _parser;

                /**
                 * @brief _table Pointer to symboltable.
                 */
                SymbolTable* _table;

                /**
                 * @brief _root Root of the syntax tree.
                 */
                Node* _root;

                /**
                 * @brief _cache Stores previously calculated values.
                 */
                QMap<double, QMap<double, double> > _cache;

                /**
                 * @brief calculateAt Calculates value at given node recursivly.
                 */
                double calculateAt(const Node*, const double&, const double&);
        };
    }
}


#endif // EVALUATOR_H
