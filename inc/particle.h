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
	int _energy; // = mass
	Vector _position; // in toroidal space
public:
	Particle(int energy, const Vector& position);
	virtual ~Particle();

	const Vector& get_pos() const;
	void set_pos(const Vector&);
	int get_energy() const;
	void set_energy(int);


	static const int c = 10; // speed of light

	virtual void move()=0;

	virtual void print() const =0;
};

class Massless : public Particle
{
private:
	double _direction; // in radians
	Vector _velocity() const;

public:
	Massless(int energy, const Vector& position, const double direction);
	Vector get_energy() const;
	// move to `direction` with distance `c`
	void move();

	void print() const;
};

class Massive : public Particle
{
private:
	// change information per round
	Vector _displace;
	// lorentz factor calculation
	double _lorentz(double energy);

public:
	Massive(int energy, const Vector& position);
	const Vector& get_displace() const;
	// add energy
	void operator+=(const Massive& collision);

	// receive impulse by transmitter
	void interact(const Massless& interaction);
	// collide with other particle
	// if it won't move any more, give it all `energy`, return true
	// return false otherwise
	bool collide(Massive& collision) const;
	// move in direction of `displace`
	// with lorentz-compensated distance of `displace`
	void move();

	void print() const;
};

#endif // PARTICLE_