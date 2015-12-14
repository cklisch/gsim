/**
 * @brief 2D vectors
 */

#ifndef VECTOR_
#define VECTOR_

class Vector
{
private:
	double _x;
	double _y;

public:
	Vector(double,double);

	void set(double, double);
	double get_x() const;
	double get_y() const;

	// wrap negative coordinates to stay inside a rectangle
	void wrap(int,int);
	bool null() const;

	// linear algebra
	double get_length() const;
	Vector operator+(const Vector&) const;
	Vector operator-(const Vector&) const;
	void operator+=(const Vector&);
	void operator-=(const Vector&);
	void operator*=(double);
	void operator/=(double);
	bool operator==(const Vector&);

	// compiler cannot distinguish between
	// Vector::round() and round(x) from <math.h>
	void vround();

	void print() const;
};

#endif // VECTOR_