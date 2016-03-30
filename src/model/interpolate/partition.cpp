#include "partition.h"

#include <QDebug>

Partition::Partition():
    _points()
{
}

Partition::~Partition()
{
    _points.clear();
}

void Partition::setPartition(double min, double max, int count)
{
    _points.clear();

    for (double i = min; i <= max; i+= (max - min) / (count - 1))
    {
        _points.push_back(i);
    }
}

int Partition::getCount()
{
    return _points.size();
}

double Partition::at(int i)
{
    return _points[i];
}
