#include "interpolation.h"

namespace Model
{
    namespace Interpolate
    {
        Interpolation::Interpolation():
            _needInitialize(false)
        {
        }

        Interpolation::~Interpolation()
        {
        }

        void Interpolation::addData(double x, double y, double z)
        {
            _data.addPoint(x, y, z);

            _needInitialize = true;
        }

        void Interpolation::clear()
        {
            _data.clear();
        }
    }
}
