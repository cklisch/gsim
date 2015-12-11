#include <iostream>
#include "particle.h"
#include "vector.h"
#include "bmp.h"

#define SIZE 10
#define SPEED 5
#define TRANS 10
#define REC 10
#define ITER 100

// void rand()
// {
//	std::random_device seed;
//     std::mt19937 gen(seed());
//     std::uniform_int_distribution<int> dist(-vel_max, vel_max-1);
//	int a = dist(gen);
//	int b;
//	if (dist(gen) < 0) {
//		 b = vel_max;
//	}
//	else {
//		b = -vel_max;
//	}
//	if (dist(gen) < 0) {
//		set(a,b);
//	}
//	else {
//		set(b,a);
//	}

// }



// uint64_t** init_matrix()
// {
//	uint64_t** matrix = (uint64_t**) malloc(2*SIZE*8);
//	for (int i = 0; i < 2*SIZE; i++) {
//		matrix[i] = (uint64_t*) malloc(2*SIZE*8);
//		for (int j = 0; j < 2*SIZE; j++) {
//			matrix[i][j] = WHITE;
//		}
//	}
//	return matrix;
// }

// void destroy_matrix(uint64_t** matrix)
// {
//	for (int i = 0; i < 2*SIZE; i++) {
//		free(matrix[i]);
//	}
//	free(matrix);
// }

// void write2matrix(std::vector<particle> part, uint64_t** matrix, uint64_t color)
// {
//	for (auto p : part) {
//		vector pos = p.get_pos();
//		matrix[pos.get_x()][pos.get_y()] = color;
//	}
// }

int main () {

	Massless p = Massless(1,Vector(0,0),0);
	Massive m = Massive(1,Vector(10,0));

	p.print();
	m.print();

	p.move();

	p.print();
	m.print();

	m.interact(p);

	m.print();

	m.move();

	m.print();

	return 0;
}