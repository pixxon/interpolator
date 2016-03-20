#include "interpolation.h"

Interpolation::Interpolation(SymbolTable* table)
{
    _table = table;
    _needInitialize = false;
}

Interpolation::~Interpolation()
{
}

void Interpolation::addData(double x, double y, double z)
{
    _data.addPoint(x, y, z);

    _needInitialize = true;
}
