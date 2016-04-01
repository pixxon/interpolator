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

    double diff = (max - min) / (count - 1);
    for (int i = 0; i < count; i++)
    {
        _points.push_back(min + i * diff);
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
