#ifndef DATATABLE_H
#define DATATABLE_H

#include <QVector>

class DataTable
{
public:
    DataTable();
    ~DataTable();

    void addPoint(double x, double y, double z);

    int sizeX();
    int sizeY();

    void clear();

    double baseXAt(int);
    double baseYAt(int);
    double valueAt(int, int);

private:
    QVector<double> _baseX;
    QVector<double> _baseY;

    QVector<QVector<double*> > _val;

};

#endif // DATATABLE_H
