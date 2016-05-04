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

    private:
        QVector<double> diffs;

        void initialize();
};

#endif // NEWTON_H
