#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "particle.h"
#include <cstdlib>
#include <ctime>
#include <string>

#define SIZE 360
#define SPEED 5
#define TRANS 2000
#define REC 2000
#define ITER 100


int main () {

	vector v1;
	v1.init_size(SIZE);
	particle p1;
	p1.init_space(2*SIZE);
	transmitter t1;
	t1.init_speed(SPEED);

	std::vector<transmitter> tm;
	std::vector<reciver> rc;

	reciver* r = new reciver[REC];


	for (int i = 0; i< REC; i++) {
		r[i].rand_pos(i);
		r[i].vel_null();
		rc.push_back(r[i]);
	}

	transmitter* t = new transmitter[TRANS];
	for (int i = 0; i < TRANS; ++i)
	{	
		t[i].rand_pos(i);
		t[i].rand_vel(2*i);
		tm.push_back(t[i]);
	}
	for (int i = 0; i < ITER; i++) {
		for (int j = 0; j < TRANS; j++) {
			t[j].move();
		}
		char s[9];
		sprintf(s, "%05d.bmp", i);
		p1.draw(s);

	}

	return 0;
}