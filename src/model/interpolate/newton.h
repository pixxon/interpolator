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
                 *
                 * @param x Position on the x axis.
                 * @param y Position on the y axis.
                 * @return Interpolation value at point.
                 */
                double calculate(double x, double y);

                /**
                 * @brief initialize Calculates diffs from given bases.
                 */
                void initialize();

                /**
                 * @brief sampleData Shows some information by telling the calculated diffs.
                 *
                 * @return The calculated divided differences in a string.
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
