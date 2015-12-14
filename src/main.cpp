#include <iostream>
#include <random>
#include <vector>

#include "particle.h"
#include "vector.h"
#include "bmp.h"


#define SIZE 128 // must be 2^n
#define SPEED 10
#define MSL 10 // # massless particles
#define MSV 10 // # massive particles
#define ITER 100
#define PI 3.14159265359

// void rand()
// {
//	std::random_device seed;
//     std::mt19937 gen(seed());
//     std::uniform_int_distribution<int> dist(0, SIZE);
//	int a = dist(gen);
//	int b;
//	if (dist(gen) < 0) {
//		 b = SIZE;
//	}
//	else {
//		b = -SIZE;
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

const int Particle::c = SPEED;

// create massive particles
std::vector<Particle*>* create_massive()
{
	std::vector<Particle*>* v = new std::vector<Particle*>;
	for (int i = 0; i < MSV; ++i)
	{
		Massive* a = new Massive(1,Vector(arc4random() % SIZE, arc4random() % SIZE));
		v->push_back(a);
	}
	return v;
}

// create massless particles
std::vector<Particle*>* create_massless()
{
	std::vector<Particle*>* v = new std::vector<Particle*>;
	for (int i = 0; i < MSL; ++i)
	{
		Massless* a = new Massless(1,Vector(arc4random() % SIZE, arc4random() % SIZE),arc4random());
		v->push_back(a);
	}
	return v;
}

// work through one time step
void iterate(std::vector<Particle*>* massive, std::vector<Particle*>* massless)
{
	// move massless particles and interact with massive ones if hit
	for (auto p : massless)
	{
		p->move(); p->round();
		for (auto m : massive)
		{
			// interact with a particle if at same position
			// then self-destruct
			if (p->get_pos() == m->get_pos())
			{
				m->interact(*p);
				massless->erase(p);
				delete p;
			}
		}
	}
	// move all interacted-with massive particles
	// interact with all colliding massive ones
	// emit number of massless particles as result
	for (auto m : massive)
	{
		if (!m->get_displace().null())
		{
			m->move(); m->round();
			for (auto k : massive)
			{
				if (k != m && m->collide(*k))
				{
					massless->erase(m);
					delete m;
				}
			}
		}
	}
}

int main () {
	std::vector<Particle*>* massive = create_massive();
	std::vector<Particle*>* massless = create_massless();

	// for (int i = 0; i < 10; ++i)
	// {
	//	Massless p = Massless(i,Vector(0,0),(PI/4)*i);
	//	Massive m = Massive(1,Vector(10,0));
	//	p.print();
	//	m.print();

	//	p.move();

	//	p.round();
	//	p.print();
	//	// m.print();

	//	m.interact(p);

	//	// m.print();

	//	m.move();

	//	m.round();
	//	m.print();
	//	std::cout << std::endl;
	// }



	return 0;
}