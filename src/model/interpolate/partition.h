#ifndef PARTITION_H
#define PARTITION_H

#include <QVector>
namespace Model
{
    namespace Interpolate
    {
        /**
         * @brief The PartitionType enum is used to determine which type of partition to be used.
         */
        enum PartitionType { PARTITION_TYPE_EVEN, PARTITION_TYPE_CHEBYSHEV };

        /**
         * @brief The Partition class provides interface to create basepoint automatically and manually.
         */
        class Partition
        {
            public:
                /**
                 * @brief Partition Creates an empty partition.
                 */
                Partition();

                /**
                 * @brief ~Partition Deletes every basepoints.
                 */
                ~Partition();

                /**
                 * @brief setPartition Sets the basepoints automatically.
                 *
                 * @param min Lower end of the interval.
                 * @param max Upper end of the interval.
                 * @param count Number of points in the interval.
                 * @param type Type of the partition.
                 */
                void setPartition(double min, double max, int count, PartitionType type);

                /**
                 * @brief setPoints Sets the points to the given ones.
                 *
                 * @param points The new base points.
                 */
                void setPoints(const QVector<double>& points);

                /**
                 * @brief getCount Getter for number of base points.
                 * @return Number of base points.
                 */
                int getCount();

                /**
                 * @brief at Returns the value of the base at given index.
                 *
                 * @param i Index of the base.
                 * @return Value of the base.
                 */
                double at(int i);

            private:
                /**
                 * @brief _points Basepoints stored in a vector.
                 */
                QVector<double> _points;
        };
    }
}

#endif // PARTITION_H
