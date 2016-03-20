#include "interpolation.h"

Position::Position(double x, double y):
	_x(x),
	_y(y)
{
}

Position::~Position()
{
}

bool Position::operator<(const Position& other)
{
	if (_x > other._x)
	{
		return false;
	}
	if (_y > other._y)
	{
		return false;
	}
	return true;
}


Interpolation::Interpolation()
{
}

Interpolation::~Interpolation()
{
}

void Interpolation::addData(double x, double y, double z)
{
	_data.insert(std::pair<Position, double>(Position(x, y), z));
}

void Interpolation::sortData()
{
	for (std::map<Position, double>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		for (std::map<Position, double>::iterator it2 = _data.begin(); it2 != it; it2++)
		{
			if (it->first<it2->first)
			{
				double tmp = it->second;
				it->second = it2->second;
				it2->second = tmp;
			}
		}
	}
}
