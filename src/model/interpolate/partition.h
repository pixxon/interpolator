#ifndef PARTITION_H
#define PARTITION_H

#include <QVector>

class Partition
{
public:
    Partition();
    ~Partition();

    void setPartition(double min, double max, int count);
    int getCount();
    double at(int i);

private:
    QVector<double> _points;
};

#endif // PARTITION_H
