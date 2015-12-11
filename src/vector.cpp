#include "vector.h"
#include <math.h>
#include <iostream>

// #include <cstdlib>
// #include <ctime>

// #include <random>

Vector::Vector(int x, int y) : _x(x), _y(y) {}

void Vector::set(int x, int y)
{
	_x = x;
	_y = y;
}

int Vector::get_x() const
{
	return _x;
}

int Vector::get_y() const
{
	return _y;
}

void Vector::print() const
{
	std::cout << "(" << _x << "," << _y << ")";
}

void Vector::wrap(int x, int y)
{
	if (_x < 0 || _x > x)
	{
		_x = _x % x;
	}
	if (_y < 0 || _y > y)
	{
		_y = _y % y;
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

void Vector::operator*=(int a)
{
	_x *= a;
	_y *= a;
}

void Vector::operator/=(int a)
{
	_x /= a;
	_y /= a;
}

bool Vector::operator==(const Vector &v)
{
	return _x == v.get_x() && _y == v.get_y();
}