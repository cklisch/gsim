#include "particle.h"
#include <cmath>
#include <iostream>


Particle::Particle(int e, const Vector& pos)
	: _energy(e), _position(pos) {}

Particle::~Particle() {}

const Vector& Particle::get_pos() const
{
	return _position;
}

void Particle::set_pos(const Vector& v)
{
	_position = v;
}

int Particle::get_energy() const
{
	return _energy;
}

void Particle::set_energy(int e)
{
	_energy = e;
}

void Particle::move() {};
void Particle::print() const {};

Massless::Massless(int e, const Vector& pos, const double dir)
	: Particle(e, pos), _direction(dir) {}

Vector Massless::_velocity() const
{
	return Vector(std::cos(_direction),std::sin(_direction));
}

Vector Massless::get_energy() const
{
	Vector e = _velocity();
	e *= Particle::get_energy();
	return e;
}

void Massless::move()
{
	Vector displace = _velocity();
	displace *= Particle::c;
	set_pos(displace);
}

void Massless::print() const
{
	std::cout <<
		"Massless e=" <<
		Particle::get_energy() << " p=";
		//  << " " <<
		// Particle:: <<
		// get_direction() <<
	get_pos().print();
	std::cout << std::endl;
}

Massive::Massive(int e, const Vector& pos)
	: Particle(e, pos), _displace(Vector(0,0)) {}

const Vector& Massive::get_displace() const
{
	return _displace;
}

double Massive::_lorentz(double e)
{
	int c = Particle::c;
	int m = get_energy();
	return c * std::sqrt(1 - ((m * std::pow(c,2))/std::pow(e + m * std::pow(c,2),2)));
}

void Massive::operator+=(const Massive& p)
{
	set_energy(get_energy() + p.get_energy());
}

void Massive::interact(const Massless& p)
{

	_displace += p.get_energy();
}

bool Massive::collide(Massive& p) const
{
	if (p.get_displace().null())
	{
		// give energy to colliding particle
		p += *this;
		return true;
	}
	else
	{
		return false;
	}
}

void Massive::move()
{
	// compute compensated impulse
	double e = _lorentz(_displace.get_length());
	// compensate displace vector length
	_displace *= e/_displace.get_length();
	set_pos(get_pos() + _displace);
	_displace.set(0,0);
}

void Massive::print() const
{
	std::cout <<
		"Massive e=" <<
		get_energy() << " p=";
	get_pos().print();
	std::cout << " d=";
	get_displace().print();
	std::cout << std::endl;
}