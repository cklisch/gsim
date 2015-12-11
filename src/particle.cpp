#include "particle.h"
#include <math>
#include <iostream>


Particle::Particle() {}

Vector& Particle::get_pos()
{
	return _position;
}

Massless::Massless(int e, const Vector& pos, const double dir)
	: _energy(e), _posistion(pos), _direction(dir) {}

double Massless::get_direction()
{
	return _direction;
}

double Massless::get_energy()
{
	return _energy;
}

void Massless::move()
{
	displace = Vector(std::cos(_direction),std::sin(_direction)) *= c;
	_position += displace;
}

void Massless::print()
{
	cout <<
		"Massless " <<
		_pos.print() << " " <<
		_energy << " " <<
		_direction <<
	endl;
}

Massive::Massive(int e, const Vector& pos)
	: _energy(e), _position(pos)
{
	_displace = Vector(0,0);
}

Vector& Massive::get_displace()
{
	return _displace;
}
double _lorentz(double e)
{
	return _c * std::sqrt(1 - ((m * c^2)/(e + m * c^2))^2);
}
void Massive::operator+=(const Massive& p)
{
	_energy += p.get_energy();
}
void Massive::interact(const Massless& p)
{
	_displace += p.get_direction()
}

bool Massive::collide(const Massive& p)
{
	if (p.get_displace().null())
	{
		// give energy to colliding particle
		p += *this;
		// self-destruct
		delete this;
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
	double e = lorentz(_displace.get_length());
	_diplace *= e/_displace.get_length();
	_position += _displace;
	_displace.set(0,0);
}