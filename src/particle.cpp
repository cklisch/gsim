#include "particle.h"
#include <cstdlib>
#include "bmp.h"

particle*** particle::space = NULL;

particle::particle(){}

void particle::init_space(int size)
{
	space = (particle***) malloc(size * sizeof(particle**));

	for(int i = 0; i < size; i++) {
		space[i] = (particle**) malloc(size * sizeof(particle*));
		for(int j = 0; j < size; j++) {
			space[i][j] = NULL;
		}
	}
}

void particle::rand_pos()
{
	p_pos.rand();
}

void particle::rand_vel()
{
	p_vel.rand();
}

void particle::set_pos(int x, int y)
{
	p_pos.set(x, y);
}

void particle::set_vel(int x, int y)
{
	p_vel.set(x, y);
}

vector& particle::get_pos()
{
	return p_pos;
} 

vector& particle::get_vel()
{
	return p_vel;
}




void transmitter::move()
{
	p_pos += p_vel;

	particle* p = space[p_pos.get_x()][p_pos.get_y()];

	if (p != NULL) {
		reciver* r = static_cast <reciver*>(p);
		r->move(p_vel);
		rand_vel();
	}

}

void reciver::rand_pos()
{
	p_pos.rand();
	space[p_pos.get_x()][p_pos.get_y()] = this;
}

void reciver::vel_null()
{
	p_vel.set(0,0);
}

void reciver::inc_mass()
{
	mass++;
}

void reciver::set_mass(int m)
{
	mass = m;
}

void reciver::move(vector v)
{
	space[p_pos.get_x()][p_pos.get_y()] = NULL;
	p_vel -= v;
	p_vel /= 2;
	p_pos += p_vel;
	particle* p = space[p_pos.get_x()][p_pos.get_y()];
	if (p == NULL) {
		space[p_pos.get_x()][p_pos.get_y()] = this;
	}
	else {
		reciver* r = static_cast <reciver*>(p);
		r->inc_mass();
	}
}