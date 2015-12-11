/**
 * @brief 2D vectors
 */

#ifndef VECTOR_
#define VECTOR_

class Vector
{
private:
	int _x;
	int _y;

public:
	Vector(int,int);

	void set(int, int);
	int get_x();
	int get_y();

	// wrap negative coordinates to stay inside a rectangle
	void wrap(int,int);
	bool null();

	// linear algebra
	double get_length();
	void operator+=(const vector&);
	void operator-=(const vector&);
	void operator*=(int);
	void operator/=(int);
	bool operator==(const vector&)

	void print();
};

#endif // VECTOR_