#include "datatable.h"

namespace Model
{
    namespace Interpolate
    {
        DataTable::DataTable():
            _baseX(),
            _baseY(),
            _val()
        {
        }


        DataTable::~DataTable()
        {
            _baseX.clear();
            _baseY.clear();

            for (int i = 0; i < _val.size(); i++)
            {
                for (int j = 0; j < _val[i].size(); j++)
                {
                    if (_val[i][j] != 0)
                    {
                        delete _val[i][j];
                    }
                }
                _val[i].clear();
            }
            _val.clear();
        }

        void DataTable::addPoint(double x, double y, double z)
        {
            int i = 0;
            while (i < _baseX.size() && _baseX[i] < x)
            {
                i++;
            }
            if (i == _baseX.size() || x != _baseX[i])
            {
                _baseX.insert(i, x);

                _val.insert(i, QVector<double*>(_baseY.size()));
            }

            int j = 0;
            while (j < _baseY.size() && _baseY[j] < y)
            {
                j++;
            }
            if (j == _baseY.size() || y != _baseY[j])
            {
                _baseY.insert(j, y);

                for (int k = 0; k < _baseX.size(); k++)
                {
                    _val[k].insert(j, 0);
                }
            }

            _val[i][j] = new double(z);
        }

        void DataTable::clear()
        {
             _baseX.clear();
             _baseY.clear();

             for (int i = 0; i < _val.size(); i++)
             {
                 for (int j = 0; j < _val[i].size(); j++)
                 {
                     if (_val[i][j] != 0)
                     {
                         delete _val[i][j];
                     }
                 }
                 _val[i].clear();
             }
             _val.clear();
        }

        int DataTable::sizeX()
        {
            return _baseX.size();
        }

        int DataTable::sizeY()
        {
            return _baseY.size();
        }

        double DataTable::baseXAt(int x)
        {
            return _baseX[x];
        }

        double DataTable::baseYAt(int y)
        {
            return _baseY[y];
        }


        double DataTable::valueAt(int x, int y)
        {
            return *(_val[x][y]);
        }
    }
}
