#include "std_lib_facilities.h"

//This class has memory management issues as a demonstration.
class vect{
	int sz;
	double* elem;

	public:
	vect(int s):sz{s}, elem{new double [s]} {}
	vect(const vect &arg):sz{arg.sz}, elem{new double[arg.sz]}{
		copy(arg.elem, arg.elem + arg.sz, elem);
	}
	vect& operator=(const vect& other){
		double * p = new double[other.sz];
		copy(other.elem, other.elem + other.sz, p);
		delete[] elem;
		elem = p;
		sz = other.sz;
		return *this;
	}
	~vect() {delete[] elem;}

	double get(int i) {return elem[i];}
	void set(int i, double d){
		elem[i]=d;
	}
};


int main(){
	vect v(3);
	v.set(2, 2.2);
	vect v2 = v;
	v.set(1, 9.9);
	v2.set(0, 8.8);
	std::cout << v.get(0) << ' ' << v2.get(1) << endl;
	std::cout << v.get(1) << ' ' << v2.get(0) << endl;
}
