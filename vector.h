/*!
\brief A vector in a two dimensional torus space. With equal width and hight and max being absolut maximum.

*/

class vector
{
private:
	static int max;
	int v_x;
	int v_y;

public:
	vector();
	void init_size(int); // one call once to initialize the torus space
	void set(int, int);
	void rand(int nonce, int m = max); // default is whole space otherwise give max
	void print();
	int get_x();
	int get_y();
	int get_max();

	vector& operator+=(const vector&);
	vector& operator-=(const vector&);
	vector& operator/=(int);

};