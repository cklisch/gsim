#include "vector.h"
#include <string>

class particle
{
protected:
	pos_vector p_pos;
	vel_vector p_vel;
	static particle*** space; // we only track recivers in this space.

public:
	particle();
	void init_space(int);
	void rand_pos();
	void rand_vel();
	void set_pos(int, int);
	void set_vel(int, int);
	vector& get_pos();
	vector& get_vel();
};

class transmitter : public particle
{
public:
	transmitter(){};
	void move();


};

class reciver : public particle
{
private:
	int mass;
public:	
	reciver(){};
	~reciver(){};
	void rand_pos();
	void vel_null();
	void move(vector);
	void set_mass(int);
	void inc_mass();
	
};

