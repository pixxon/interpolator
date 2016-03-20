#ifndef LAGRANGE_H
#define LAGRANGE_H

#include "../parseval/evaluator.h"
#include "../parseval/symbol.h"
#include "interpolation.h"

#include <QVector>
#include <QString>

class Lagrange : public Interpolation
{
public:
    Lagrange(SymbolTable* table);
    ~Lagrange();

    double calculate(double x, double y);

private:
    QVector<Evaluator*> _polX;
    QVector<Evaluator*> _polY;

    QString createPolynomialX(int v);
    QString createPolynomialY(int k);

    void initialize();
};

#endif // LAGRANGE_H
