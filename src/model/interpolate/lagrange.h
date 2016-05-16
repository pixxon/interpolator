#ifndef LAGRANGE_H
#define LAGRANGE_H

#include "../parseval/evaluator.h"
#include "../parseval/symbol.h"
#include "interpolation.h"

#include <QVector>
#include <QString>

namespace Model
{
    namespace Interpolate
    {
        /**
         * @brief The Lagrange class creates an polinomial interpolation using the Lagrange base polinomials.
         */
        class Lagrange : public Interpolation
        {
            public:
                /**
                 * @brief Lagrange Empty constructor.
                 */
                Lagrange();

                /**
                 * @brief Deletes every created resource.
                 */
                ~Lagrange();

                /**
                 * @brief calculate Calculates value at given point.
                 *
                 * @param x Position on the x axis.
                 * @param y Position on the y axis.
                 * @return Interpolation value at point.
                 */
                double calculate(double x, double y);

                /**
                 * @brief initialize Creates the base polinomials and their evaluators.
                 */
                void initialize();

                /**
                 * @brief sampleData Shows some information by telling the used methods.
                 * @return Used methods in a string.
                 */
                QString sampleData();

            private:
                /**
                 * @brief _polX Evaluators used for base polinomials on x axis.
                 */
                QVector<Parseval::Evaluator*> _polX;

                /**
                 * @brief _polY Evaluators used for base polinomials on y axis.
                 */
                QVector<Parseval::Evaluator*> _polY;

                /**
                 * @brief createPolynomialX Creates a base polinomial on the x axis.
                 * @param v The index of the base.
                 * @return Function in a string.
                 */
                QString createPolynomialX(int v);

                /**
                 * @brief createPolynomialY Creates a base polinomial on the y axis.
                 * @param k The index of the base.
                 * @return Function in a string.
                 */
                QString createPolynomialY(int k);
        };
    }
}

#endif // LAGRANGE_H
