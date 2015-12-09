/*!
\brief A vector in a two dimensional torus space. With equal width and hight and max being absolut maximum.

*/

	enum type {
		BASE,
		POS,
		VEL
	};

class vector
{
private:
	int v_x;
	int v_y;
	static type t;

public:

	vector();
	void set(int, int);
	void print();
	int get_x();
	int get_y();
	virtual type get_type();
	virtual void check_torus();

	vector& operator+=(const vector&);
	vector& operator-=(const vector&);
	vector& operator/=(int);

};

class vel_vector : public vector
{
private:
	static int vel_max;
	static type t;

public:
	vel_vector();
	type get_type();
	void set_max(int);
	void rand();
};

class pos_vector : public vector
{
private:
	static int pos_max;
	static type t;

public:
	pos_vector();
	type get_type();
	void set_max(int);
	void check_torus();
	void rand();
};