#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "particle.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include "bmp.h"

#define SIZE 10
#define SPEED 5
#define TRANS 10
#define REC 10
#define ITER 100

uint64_t** init_matrix()
{
	uint64_t** matrix = (uint64_t**) malloc(2*SIZE*8);
	for (int i = 0; i < 2*SIZE; i++) {
		matrix[i] = (uint64_t*) malloc(2*SIZE*8);
		for (int j = 0; j < 2*SIZE; j++) {
			matrix[i][j] = WHITE;
		}
	}
	return matrix;
}

void destroy_matrix(uint64_t** matrix)
{
	for (int i = 0; i < 2*SIZE; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void write2matrix(std::vector<particle> part, uint64_t** matrix, uint64_t color)
{
	for (auto p : part) {
		vector pos = p.get_pos();
		matrix[pos.get_x()][pos.get_y()] = color;
	}
}


int main () {

	pos_vector v_pos;
	v_pos.set_max(SIZE); // set the size of the torus space
	vel_vector v_vel;
	v_vel.set_max(SPEED); // set max speed of a particle
	particle p1;
	p1.init_space(SIZE);

	
	std::vector<transmitter> tm;
	std::vector<reciver> rc;

	reciver* r = new reciver[REC];

	for (int i = 0; i< REC; i++) {
		r[i].rand_pos();
		r[i].vel_null();
		r[i].set_mass(1);
		rc.push_back(r[i]);
	}

	std::cout << std::endl;

	transmitter* t = new transmitter[TRANS];
	for (int i = 0; i < TRANS; ++i)
	{	
		t[i].rand_pos();
		t[i].rand_vel();
		tm.push_back(t[i]);
	}

	// the transmitter particles move around and interact with recivers
	for (int i = 0; i < ITER; i++) {
		for (int j = 0; j < TRANS; j++) {
			t[j].move();
		}
	}

	return 0;
}