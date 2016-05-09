#ifndef PARTITION_H
#define PARTITION_H

#include <QVector>

enum PartitionType { PARTITION_TYPE_EVEN, PARTITION_TYPE_CHEBYSHEV };

class Partition
{
public:
    Partition();
    ~Partition();

    void setPartition(double min, double max, int count, PartitionType type);
    void setPoints(const QVector<double>&);
    int getCount();
    double at(int i);

private:
    QVector<double> _points;
};

#endif // PARTITION_H
