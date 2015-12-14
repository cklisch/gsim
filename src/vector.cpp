#include "vector.h"
#include <math.h>
#include <iostream>

// #include <cstdlib>
// #include <ctime>

// #include <random>

Vector::Vector(double x, double y) : _x(x), _y(y) {}

void Vector::set(double x, double y)
{
	_x = x;
	_y = y;
}

double Vector::get_x() const
{
	return _x;
}

double Vector::get_y() const
{
	return _y;
}

void Vector::wrap(int x, int y)
{
	if (_x < 0)
	{
		_x += x;
	}
	else if (_x > x)
	{
		_x -= x;
	}
	if (_y < 0)
	{
		_y += y;
	}
	else if(_y > y)
	{
		_y -= y;
	}
}

bool Vector::null() const
{
	return _x == 0 && _y == 0;
}
double Vector::get_length() const
{
	return sqrt(pow(_x,2) + pow(_y,2));
}

Vector Vector::operator+(const Vector &v) const
{
	return Vector(_x + v.get_x(), _y + v.get_y());
}

Vector Vector::operator-(const Vector &v) const
{
	return Vector(_x - v.get_x(), _y - v.get_y());
}

void Vector::operator+=(const Vector &v)
{
	_x += v.get_x();
	_y += v.get_y();
}

void Vector::operator-=(const Vector &v)
{
	_x -= v.get_x();
	_y -= v.get_y();
}

void Vector::operator*=(double a)
{
	_x *= a;
	_y *= a;
}

void Vector::operator/=(double a)
{
	_x /= a;
	_y /= a;
}

bool Vector::operator==(const Vector &v)
{
	return _x == v.get_x() && _y == v.get_y();
}

void Vector::vround()
{
	_x = round(_x);
	_y = round(_y);
}

void Vector::print() const
{
	std::cout << "(" << _x << "," << _y << ")";
}