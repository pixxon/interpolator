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
                 */
                double calculate(double, double);

                /**
                 * @brief initialize Creates the base polinomials and their evaluators.
                 */
                void initialize();

                /**
                 * @brief sampleData Returns some information by telling the used methods.
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
                 */
                QString createPolynomialX(int);

                /**
                 * @brief createPolynomialY Creates a base polinomial on the y axis.
                 */
                QString createPolynomialY(int);
        };
    }
}

#endif // LAGRANGE_H
