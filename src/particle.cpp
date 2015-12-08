#include "particle.h"
#include <cstdlib>
#include "bmp.h"

int transmitter::speed = 0;

particle*** particle::space = NULL;

particle::particle(){}

void particle::init_space(int size)
{
	space = (particle***) malloc(size * sizeof(particle**));

	for(int i = 0; i < size; i++) {
		space[i] = (particle**) malloc(size * sizeof(particle*));
	}
}

void particle::draw(const char* path)
{
	int max = p_pos.get_max();
	max*=2;
	FILE* file = fopen(path, "w");
	bitmap_file_header(file, max, max);
	bitmap_info_header(file, max, max);
	for (int x = 0; x < max; x++) {
		for (int y = 0; y < max; y++) {
			if (space[x][y] == NULL)
				write_N_byte(file, GREY, 4);
			else {
				write_N_byte(file, RED, 4);
			}

		}
	}
	fclose(file);

}

transmitter::transmitter(){}

void transmitter::init_speed(int s)
{
	speed = s;
}

void transmitter::rand_pos(int nonce)
{
	p_pos.rand(nonce);
}

void transmitter::rand_vel(int nonce)
{
	p_vel.rand(nonce, speed);
}

void transmitter::move()
{
	p_pos += p_vel;

	particle* p = space[p_pos.get_x()+p_pos.get_max()][p_pos.get_y()+p_pos.get_max()];

	if (p != NULL) {
		reciver* r = static_cast <reciver*>(p);
		r->move(p_vel);
		rand_vel(p_pos.get_x());
	}

}

vector& particle::get_pos()
{
	return p_pos;
} 

vector& particle::get_vel()
{
	return p_vel;
}

void reciver::rand_pos(int nonce)
{
	p_pos.rand(nonce);
	space[p_pos.get_x()+p_pos.get_max()][p_pos.get_y()+p_pos.get_max()] = this;
}

void reciver::vel_null()
{
	p_vel.set(0,0);
}

void reciver::inc_mass()
{
	mass++;
}

void reciver::move(vector v)
{
	space[p_pos.get_x()+p_pos.get_max()][p_pos.get_y()+p_pos.get_max()] = NULL;
	p_vel -= v;
	p_vel /= 2;
	p_pos += p_vel;
	particle* p = space[p_pos.get_x()+p_pos.get_max()][p_pos.get_y()+p_pos.get_max()];
	if (p == NULL) {
		space[p_pos.get_x()+p_pos.get_max()][p_pos.get_y()+p_pos.get_max()] = this;
	}
	else {
		reciver* r = static_cast <reciver*>(p);
		r->inc_mass();
	}
}