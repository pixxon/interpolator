#ifndef DATATABLE_H
#define DATATABLE_H

#include <QVector>

namespace Model
{
    namespace Interpolate
    {
        /**
         * @brief The DataTable class stores the information for interpolation.
         *
         * Values are sorted and can be access by index.
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
                 *
                 * @param x The points coordinate on x axis.
                 * @param y The points coordinate on y axis.
                 * @param z Value at the (x,y) point.
                 */
                void addPoint(double x, double y, double z);

                /**
                 * @brief sizeX Number of bases on x axis.
                 *
                 * @return Size of baseX vector.
                 */
                int sizeX();

                /**
                 * @brief sizeY Number of bases on y axis.
                 *
                 * @return Size of baseY vector.
                 */
                int sizeY();

                /**
                 * @brief clear Clears the table.
                 */
                void clear();

                /**
                 * @brief baseXAt Returns the value of the base at the given index.
                 *
                 * @param index Index of the base, starts at 0.
                 * @return The value of the base.
                 */
                double baseXAt(int index);

                /**
                 * @brief baseYAt Returns the value of the base at the given index.
                 *
                 * @param index Index of the base, starts at 0.
                 * @return The value of the base.
                 */
                double baseYAt(int index);

                /**
                 * @brief valueAt Returns the value at the given point.
                 *
                 * @param indX Index of the base on x axis.
                 * @param indY Index of the base on y axis.
                 * @return Value at the point.
                 */
                double valueAt(int indX, int indY);

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
