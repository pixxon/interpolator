#include "partition.h"

#include <QtMath>

Partition::Partition():
    _points()
{
}

Partition::~Partition()
{
    _points.clear();
}

void Partition::setPartition(double min, double max, int count, Partition_Type type)
{
    if (type == PARTITION_TYPE_EVEN)
    {
        _points.clear();

        double diff = (max - min) / (count - 1);
        for (int i = 0; i < count; i++)
        {
            _points.push_back(min + i * diff);
        }
    }
    if (type == PARTITION_TYPE_CHEBYSHEV)
    {
        _points.clear();

        for (int i = 1; i <= count; i++)
        {
            double root;

            root = cos((2.f * i - 1.f) / (2.f * count) * 3.14159265359);
            root *= (max - min) / 2;
            root += min + ((max - min) / 2);

            _points.push_front(root);
        }
    }
}

void Partition::setPoints(const QVector<double>& points)
{
    _points.clear();
    _points += points;

    qSort(_points);
}

int Partition::getCount()
{
    return _points.size();
}

double Partition::at(int i)
{
    return _points[i];
}
