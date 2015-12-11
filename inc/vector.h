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
	int get_x() const;
	int get_y() const;

	// wrap negative coordinates to stay inside a rectangle
	void wrap(int,int);
	bool null() const;

	// linear algebra
	double get_length() const;
	Vector operator+(const Vector&) const;
	Vector operator-(const Vector&) const;
	void operator+=(const Vector&);
	void operator-=(const Vector&);
	void operator*=(int);
	void operator/=(int);
	bool operator==(const Vector&);

	void print() const;
};

#endif // VECTOR_