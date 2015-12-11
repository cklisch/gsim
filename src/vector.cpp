#include "vector.h"
#include <math>
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

int Vector::get_x() 
{
	return _x;
}

int Vector::get_y()
{
	return _y;
}

void Vector::print()
{
	std::cout << "(" << _x << "," << _y << ")" << std::endl;
}

void Vector::wrap(int x, int y)
{
	if (_x < 0 || _x > x):
	{
		_x = _x % x;
	}
	if (_y < 0 || _y > y):
	{
		_y = _y % y;
	}
}

bool Vector::null()
{
	return _x == 0 && _y == 0;
}
double Vector::get_length()
{
	return std::sqrt(x^2 + y^2);
}


void Vector::operator+=(const Vector &v)
{
	_x += v.get_x();
	_y += v.get_y();
}

void Vector::operator+=(const Vector &v)
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