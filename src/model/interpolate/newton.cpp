#include "newton.h"

Newton::Newton()
{

}

Newton::~Newton()
{

}

#include <QDebug>

double Newton::calculate(double x, double y)
{
    Q_UNUSED(y);

    if (_needInitialize)
    {
        initialize();
    }

    double result = diffs[diffs.size() - 1];

    for (int i = _data.sizeX(); i > 1; i--)
    {
        result = diffs[i - 2] + result * (x-_data.baseXAt(i - 2));
    }

    return result;
}

void Newton::initialize()
{
    diffs.resize(_data.sizeX());
    for (int i = 0; i < _data.sizeX(); i++)
    {
        diffs[i] = _data.valueAt(i,0);
    }

    for (int k = 0; k < diffs.size() - 1; k++)
    {
        for (int j = diffs.size() - 1; j > k; j--)
        {
            diffs[j] = (diffs[j] - diffs[j-1]) / (_data.baseXAt(j) - _data.baseXAt(j - k - 1));
        }
    }

    _needInitialize = false;
}

QString Newton::sampleData()
{
    QString result = "Kiszámított osztott differenciák, a Newton-alakhoz: \n\n";
    for (int k = 0; k < diffs.size(); k++)
    {
        result.append("f[");
        for (int i = 0; i < k; i++)
        {
            result.append("x" + QString::number(i) + ",");
        }
        result.append("x" + QString::number(k) + "] = " + QString::number(diffs[k], 'f', 4) + "\n");
    }
    return result;
}

