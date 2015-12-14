#include "particle.h"
#include <math.h>
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

void Particle::round()
{
	_position.vround();
}

void Particle::move() {};
void Particle::print() const {};

Massless::Massless(int e, const Vector& pos, const double dir)
	: Particle(e, pos), _direction(dir) {}

Vector Massless::_velocity() const
{
	return Vector(cos(_direction),sin(_direction));
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
	get_pos().print();
	std::cout << " v=";
	_velocity().print();
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
	return c * sqrt(1 - ((m * pow(c,2))/(e + m * pow(c,2))));
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
	if (_displace.get_length() != 0)
		{_displace *= e/_displace.get_length();}
	else
		{_displace *= 0;}
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