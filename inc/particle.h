/**
 * @brief Relativistic particles
 *
 * In a crazy universe without momentum
 */

#include "vector.h"

class Particle
{
private:
	Vector _position; // in toroidal space
	int _energy; // = mass
	static int _c; // speed of light

public:
	Particle(int energy, const Vector& position);
	virtual ~Particle();
	Vector& get_pos();
};

class Massless : public Particle
{
private:
	double _direction; // 0 <= x < 2PI

public:
	Massless(int energy, const Vector& position, const double direction);
	double get_direction();
	void move(); // move to `direction` with distance `c`
};

class Massive : public Particle
{
private:
	Vector _displace;

public:
	Vector& get_displace();
	// receive relativistic impulse by transmitter
	// also emit more tranmitters
	void interact(const Massless& interaction);
	// collide with other particle if it won't move any more
	// give it all `energy` and self-destruct
	void collide(Massive& collision);
}