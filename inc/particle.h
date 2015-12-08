#include "vector.h"
#include <string>

class particle
{
protected:
	vector p_pos;
	vector p_vel;
	static particle*** space; // we put only recivers in this space.

public:
	particle();
	void init_space(int);
	void draw(const char*);
	vector& get_pos();
	vector& get_vel();
};

class transmitter : public particle
{
private:
	static int speed;

public:
	transmitter();
	void init_speed(int); // call once to set speed of transmitter
	void rand_pos(int);
	void rand_vel(int);
	void move();


};

class reciver : public particle
{
private:
	int mass;
public:	
	reciver(){};
	~reciver(){};
	void rand_pos(int);
	void vel_null();
	void move(vector);
	void inc_mass();
	
};

