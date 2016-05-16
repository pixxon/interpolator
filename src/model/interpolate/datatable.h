#ifndef DATATABLE_H
#define DATATABLE_H

#include <QVector>

namespace Model
{
    namespace Interpolate
    {
        /**
         * @brief The DataTable class stores the information for interpolation, so values are sorted and can be access by index.
         */
        class DataTable
        {
            public:
                /**
                 * @brief DataTable Creates an empty table.
                 */
                DataTable();
                /**
                 * @brief ~DataTable Deletes the table.
                 */
                ~DataTable();

                /**
                 * @brief addPoint Add a new point into the table. If needed inserts a new row or column.
                 */
                void addPoint(double, double, double);

                /**
                 * @brief sizeX Returns the number of bases on x axis.
                 */
                int sizeX();

                /**
                 * @brief sizeY Returns the number of bases on y axis.
                 */
                int sizeY();

                /**
                 * @brief clear Clears the table.
                 */
                void clear();

                /**
                 * @brief baseXAt Returns the value of the base at the given index.
                 */
                double baseXAt(int);

                /**
                 * @brief baseYAt Returns the value of the base at the given index.
                 */
                double baseYAt(int);

                /**
                 * @brief valueAt Returns the value at the given point.
                 */
                double valueAt(int, int);

            private:
                /**
                 * @brief _baseX Stores the bases on x axis.
                 */
                QVector<double> _baseX;

                /**
                 * @brief _baseY Stores the bases on y axis.
                 */
                QVector<double> _baseY;

                /**
                 * @brief _val Stores the values in a matrix.
                 */
                QVector<QVector<double*> > _val;
        };
    }
}
#endif // DATATABLE_H
