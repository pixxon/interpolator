#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "../parseval/symbol.h"
#include "datatable.h"

#include <QString>


namespace Model
{
    namespace Interpolate
    {
        /**
         * @brief The Interpolation abstract class provides an interface for interpolation methods.
         */
        class Interpolation
        {
            public:
                /**
                 * @brief Interpolation Creates an empty datarable.
                 */
                Interpolation();

                /**
                 * @brief ~Interpolation Deletes the datatable.
                 */
                virtual ~Interpolation();

                /**
                 * @brief addData Adds a new basepoint with given value.
                 *
                 * @param x Position on the x axis.
                 * @param y Position on the y axis.
                 * @param z Value at given point.
                 */
                void addData(double x, double y, double z);

                /**
                 * @brief clear Clears the table.
                 */
                void clear();

                /**
                 * @brief calculate Pure virtual method. Calculates value at given point.
                 *
                 * @param x Position on the x axis.
                 * @param y Position on the y axis.
                 * @return Interpolation value at point.
                 */
                virtual double calculate(double x, double y) = 0;

                /**
                 * @brief initialize Pure virtual method. Initializes the needed values.
                 */
                virtual void initialize() = 0;

                /**
                 * @brief sampleData Provides some information about the method.
                 * @return Information in a string.
                 */
                virtual QString sampleData() = 0;

            protected:
                /**
                 * @brief _data Stores the basepoints and values.
                 */
                DataTable _data;

                /**
                 * @brief _needInitialize Shows if initialization is needed or not.
                 */
                bool _needInitialize;
        };
    }
}

#endif // INTERPOLATION_H
