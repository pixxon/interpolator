#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "../parseval/symbol.h"
#include "datatable.h"

#include <QString>

class Interpolation
{
public:
    Interpolation();
    virtual ~Interpolation();

    void addData(double x, double y, double z);
    void clear();

    virtual double calculate(double x, double y) = 0;
    virtual void initialize() = 0;
    virtual QString sampleData() = 0;

protected:
    DataTable _data;

    bool _needInitialize;
};


#endif // INTERPOLATION_H
