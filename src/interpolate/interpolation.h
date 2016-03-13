#ifndef INTERPOLATION_H
#define INTERPOLATION_H

class Position
{
public:
	Position(double x, double y);
	~Position();

	bool operator<(const Position& other);
private:

	double _x;
	double _y;
};

class Interpolation
{
private:
	std::map<Position, double> _data;

public:
	Interpolation();
	~Interpolation();

	void addData(double x, double y, double z);
	void sortData();

	virtual std::string createPolynomial();

};


#endif // INTERPOLATION_H
