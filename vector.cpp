#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <random>

type vector::t = BASE;

vector::vector() {}

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

type vector::get_type()
{
	return t;
}

void vector::print()
{
	std::cout << v_x << " " << v_y << std::endl;
}

void vector::check_torus()
{
	
}

vector& vector::operator+=(const vector &v)
{
	v_x += v.v_x;
	v_y += v.v_y;

	// if vector is a position vector this will keep it in the torus space
	if (get_type() == POS) {
		check_torus();
	}
	return *this;


}

vector& vector::operator-=(const vector &v)
{
	v_x -= v.v_x;
	v_y -= v.v_y;
	if (get_type() == POS) {
		check_torus();
	}	
	return *this;
}

vector& vector::operator/=(int a)
{
	v_x /= a;
	v_y /= a;
	return *this;
}

int vel_vector::vel_max = 0;
type vel_vector::t = VEL;

vel_vector::vel_vector(){}

type vel_vector::get_type()
{
	return t;
}

void vel_vector::set_max(int max)
{
	vel_max = max;
}

void vel_vector::rand()
{
	std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<int> dist(-vel_max, vel_max-1);
	int a = dist(gen);
	int b;
	if (dist(gen) < 0) {
		 b = vel_max;
	}
	else {
		b = -vel_max;
	}
	if (dist(gen) < 0) {
		set(a,b);
	}
	else {
		set(b,a);
	}

}

int pos_vector::pos_max = 0;
type pos_vector::t = POS;


pos_vector::pos_vector(){}

type pos_vector::get_type()
{
	return t;
}

void pos_vector::set_max(int max)
{
	pos_max = max;
}

void pos_vector::rand()
{
	std::random_device seed;
    std::mt19937 gen(seed());
	std::uniform_int_distribution<int> dist(0, pos_max-1);
	set(dist(gen), dist(gen));
}

void pos_vector::check_torus()
{
	int x = get_x();
	int y = get_y();

	if (x >= pos_max) {
		x -= pos_max;
	}
	else if (x < 0) {
		x += pos_max;
	}

	if (y >= pos_max) {
		y -= pos_max;
	}
	else if (y < 0) {
		y += pos_max;
	}
	set(x,y);
}

