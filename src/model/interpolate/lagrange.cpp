#include "lagrange.h"

#include <QStringList>
#include <QDebug>

Lagrange::Lagrange():
    Interpolation()
{

}

Lagrange::~Lagrange()
{
    for (int i = 0; i < _polX.size(); i++)
    {
        delete _polX[i];
    }
    _polX.clear();

    for (int j = 0; j < _polY.size(); j++)
    {
        delete _polY[j];
    }
    _polY.clear();
}

double Lagrange::calculate(double x, double y)
{
    if (_needInitialize)
    {
        initialize();
    }

    double result = 0;

    for (int i = 0; i < _polX.size(); i++)
    {
        for (int j = 0; j < _polY.size(); j++)
        {
            result += _data.valueAt(i, j) * _polX[i]->calculate(x, y) * _polY[j]->calculate(x, y);
        }
    }

    return result;
}

void Lagrange::initialize()
{
    for (int i = 0; i < _polX.size(); i++)
    {
        delete _polX[i];
    }
    _polX.clear();

    for (int j = 0; j < _polY.size(); j++)
    {
        delete _polY[j];
    }
    _polY.clear();

    for (int i = 0; i < _data.sizeX(); i++)
    {
        Evaluator* evaluator = new Evaluator();
        evaluator->setExpression(createPolynomialX(i));
        _polX.push_back(evaluator);
    }

    for (int j = 0; j < _data.sizeY(); j++)
    {
        Evaluator* evaluator = new Evaluator();
        evaluator->setExpression(createPolynomialY(j));
        _polY.push_back(evaluator);
    }

    _needInitialize = false;
}

QString Lagrange::createPolynomialX(int v)
{
    double denominator = 1;
    QStringList numerator;

    for (int i = 0; i < _data.sizeX(); i++)
    {
        if (i != v)
        {
            if (!numerator.empty())
            {
                numerator << "*";
            }

            numerator << "(x-" << QString::number(_data.baseXAt(i), 'f', 10) << ")";
            denominator *= (_data.baseXAt(v) -_data.baseXAt(i));
        }
    }

    return "(" + numerator.join("") + ")/(" + QString::number(denominator, 'f', 10) + ")";
}

QString Lagrange::createPolynomialY(int v)
{
    double denominator = 1;
    QStringList numerator;

    for (int i = 0; i < _data.sizeY(); i++)
    {
        if (i != v)
        {
            if (!numerator.empty())
            {
                numerator << "*";
            }

            numerator << "(y-" << QString::number(_data.baseYAt(i), 'f', 10) << ")";
            denominator *= (_data.baseYAt(v) -_data.baseYAt(i));
        }
    }

    return "(" + numerator.join("") + ")/(" + QString::number(denominator, 'f', 10) + ")";
}

