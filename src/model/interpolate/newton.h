#ifndef NEWTON_H
#define NEWTON_H

#include "interpolation.h"
#include <QVector>

namespace Model
{
    namespace Interpolate
    {
        /**
         * @brief The Newton class creates an polinomial interpolation in Newton's form.
         */
        class Newton : public Interpolation
        {
            public:
                /**
                 * @brief Newton Creates an empty vector.
                 */
                Newton();
                /**
                 * @brief ~Newton Deletes diffs.
                 */
                ~Newton();

                /**
                 * @brief calculate Calculates value at given point.
                 */
                double calculate(double, double);

                /**
                 * @brief initialize Calculates diffs from given bases.
                 */
                void initialize();

                /**
                 * @brief sampleData Shows some information by telling the calculated diffs.
                 */
                QString sampleData();

            private:
                /**
                 * @brief _diffs Calculated divided differences.
                 */
                QVector<double> _diffs;

        };
    }
}

#endif // NEWTON_H
