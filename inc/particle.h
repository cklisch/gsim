/**
 * @brief Relativistic particles
 *
 * In a crazy universe without momentum
 */

#ifndef PARTICLE_
#define PARTICLE_

#include "vector.h"

class Particle
{
private:
	Vector _position; // in toroidal space
	int _energy; // = mass
	static int _c; // speed of light

public:
	Particle();
	virtual ~Particle();
	Vector& get_pos();
	int get_energy();
	virtual void move();

	virtual void print();
};

class Massless : public Particle
{
private:
	double _direction; // in radians

public:
	Massless(int energy, const Vector& position, const double direction);
	double get_direction();
	// move to `direction` with distance `c`
};

class Massive : public Particle
{
private:
	// change information per round
	Vector _displace;
	// lorentz factor calculation
	static double _lorentz(double energy);

public:
	Particle(int energy, const Vector& position);
	Vector& get_displace();
	// add energy
	void operator+=(const Massive& collision);

	// receive impulse by transmitter
	void interact(const Massless& interaction);
	// collide with other particle if it won't move any more
	// give it all `energy` and self-destruct, return true
	bool collide(const Massive& collision);
	// move in direction of `displace`
	// with lorentz-compensated distance of `displace
};

#endif // PARTICLE_