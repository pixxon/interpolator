#include "evaluator.h"

namespace Model
{
    namespace Parseval
    {
        TreePrinter::TreePrinter()
        {

        }

        TreePrinter::~TreePrinter()
        {

        }

        QString TreePrinter::toString(Node* root)
        {
            QString result;
            QTextStream stream(&result);
            print(stream, root, 0);
            return result;
        }

        void TreePrinter::indent(QTextStream& out, int level)
        {
            for (int i = 0; i < level; i++)
            {
                if (set.contains(i))
                {
                    out << "   | ";
                }
                else
                {
                    out << "    ";
                }
            }
        }

        void TreePrinter::left(QTextStream& out, int level)
        {
            indent(out, level);
            out << "   |-";
            set.insert(level);
        }

        void TreePrinter::right(QTextStream& out, int level)
        {
            indent(out, level);
            out << "   `-";
            set.remove(level);
        }

        void TreePrinter::print(QTextStream& out, Node* node, int level)
        {
            out << "( " << node->getToken().getValue() << " )" << endl;

            if (node->getLeft() != nullptr && node->getRight() != nullptr)
            {
                left(out, level);
                print(out, node->getLeft(), level + 1);
                right(out, level);
                print(out, node->getRight(), level + 1);
            }
            else if (node->getLeft() != nullptr)
            {
                right(out, level);
                print(out, node->getLeft(), level + 1);
            }
            else if (node->getRight() != nullptr)
            {
                right(out, level);
                print(out, node->getRight(), level + 1);
            }
        }


        Evaluator::Evaluator():
            _parser(),
            _table(SymbolTable::getInstance()),
            _root(0)
        {
        }

        Evaluator::~Evaluator()
        {
            delete _root;
        }

        QString Evaluator::toString() const
        {
            TreePrinter printer;

            return printer.toString(_root);
        }

        void Evaluator::setExpression(const QString& str)
        {
            for (QMap<double, QMap<double, double> >::iterator it = _cache.begin(); it != _cache.end(); it++)
            {
                it->clear();
            }
            _cache.clear();

            _parser.setInput(str);
            _root = _parser.getTree();
        }

        double Evaluator::calculate(const double& x, const double& y)
        {
            if (_cache.contains(x) && _cache[x].contains(y))
            {
                return _cache[x][y];
            }

            double result = calculateAt(_root, x, y);
            _cache[x][y] = result;
            return result;
        }

        double Evaluator::calculateAt(const Node* node, const double& x, const double& y)
        {
            if (node == 0)
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

            return _table->operator[](node->getToken().getType()).getFunction()(lhs, rhs);
        }
    }
}
