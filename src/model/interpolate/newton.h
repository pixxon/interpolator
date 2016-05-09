#ifndef NEWTON_H
#define NEWTON_H

#include "interpolation.h"
#include <QVector>

class Newton : public Interpolation
{
    public:
        Newton();
        ~Newton();

        double calculate(double x, double y);
        void initialize();
        QString sampleData();

    private:
        QVector<double> diffs;

};

#endif // NEWTON_H
