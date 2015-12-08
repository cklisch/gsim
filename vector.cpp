#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

int vector::max = 0;

vector::vector() {}

void vector::init_size(int m)
{
	max = m;
}

void vector::set(int x, int y)
{
	v_x = x;
	v_y = y;
}

int vector::get_x() 
{
	return v_x;
}

int vector::get_y()
{
	return v_y;
}

int vector::get_max()
{
	return max;
}



void vector::rand(int nonce, int m)
{
	std::srand(nonce * std::time(0));
	v_x = std::rand() % (2*m) - m;
	v_y = std::rand() % (2*m) - m;
}

void vector::print()
{
	std::cout << v_x << " " << v_y << std::endl;
}

vector& vector::operator+=(const vector &v)
{
	v_x += v.v_x;
	if (v_x >= max) {
		v_x -= (2*max);
	}
	else if (v_x < -max) {
		v_x += (2*max);
	}

	v_y += v.v_y;
	if (v_y >= max) {
		v_y -= (2*max);
	}
	else if (v_y < -max) {
		v_y += (2*max);
	}

	return *this;
}

vector& vector::operator-=(const vector &v)
{
	v_x -= v.v_x;
	if (v_x >= max) {
		v_x -= (2*max);
	}
	else if (v_x < -max) {
		v_x += (2*max);
	}

	v_y -= v.v_y;
	if (v_y >= max) {
		v_y -= (2*max);
	}
	else if (v_y < -max) {
		v_y += (2*max);
	}

	return *this;
}

vector& vector::operator/=(int d)
{
	v_x /= d;
	v_y /= d;
	return *this;
}
