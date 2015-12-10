/**
 * @brief 2D vectors
 */

class Vector
{
private:
	int _x;
	int _y;

public:
	Vector();

	void set(int, int);
	void print();
	int get_x();
	int get_y();

	// wrap negative coordinates to stay inside a rectangle
	void wrap(int,int);

	// linear algebra
	void operator+=(const vector&);
	void operator-=(const vector&);
	void operator*=(int);
	void operator/=(int);
	bool operator==(const vector&)
};
