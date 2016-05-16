#include "newton.h"

namespace Model
{
    namespace Interpolate
    {
        Newton::Newton()
        {

        }

        Newton::~Newton()
        {

        }

        double Newton::calculate(double x, double y)
        {
            Q_UNUSED(y);

            if (_needInitialize)
            {
                initialize();
            }

            double result = _diffs[_diffs.size() - 1];

            for (int i = _data.sizeX(); i > 1; i--)
            {
                result = _diffs[i - 2] + result * (x-_data.baseXAt(i - 2));
            }

            return result;
        }

        void Newton::initialize()
        {
            _diffs.resize(_data.sizeX());
            for (int i = 0; i < _data.sizeX(); i++)
            {
                _diffs[i] = _data.valueAt(i,0);
            }

            for (int k = 0; k < _diffs.size() - 1; k++)
            {
                for (int j = _diffs.size() - 1; j > k; j--)
                {
                    _diffs[j] = (_diffs[j] - _diffs[j-1]) / (_data.baseXAt(j) - _data.baseXAt(j - k - 1));
                }
            }

            _needInitialize = false;
        }

        QString Newton::sampleData()
        {
            QString result = "Kiszámított osztott differenciák, a Newton-alakhoz: \n\n";
            for (int k = 0; k < _diffs.size(); k++)
            {
                result.append("f[");
                for (int i = 0; i < k; i++)
                {
                    result.append("x" + QString::number(i) + ",");
                }
                result.append("x" + QString::number(k) + "] = " + QString::number(_diffs[k], 'f', 4) + "\n");
            }
            return result;
        }
    }
}
