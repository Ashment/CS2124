#include "std_lib_facilities.h"

//This class has memory management issues as a demonstration.
class vect{
	int sz;
	double* elem;

	public:
	//Constructors
	vect(int s):sz{s}, elem{new double [s]} {}
	vect(const vect &arg):sz{arg.sz}, elem{new double[arg.sz]}{
		copy(arg.elem, arg.elem + arg.sz, elem);
	}

	//Operator Overloads
	vect& operator=(const vect& other){
		double * p = new double[other.sz];
		copy(other.elem, other.elem + other.sz, p);
		delete[] elem;
		elem = p;
		sz = other.sz;
		return *this;
	}
	double& operator[](int n) const {
		return elem[n];
	}

	//Getters and setters
	double get(int i) {return elem[i];}
	void set(int i, double d){
		elem[i]=d;
	}

	~vect() {delete[] elem;}
};


int main(){
	vect v(3);
	v.set(2, 2.2);
	vect v2 = v;
	v.set(1, 9.9);
	v2.set(0, 8.8);
	std::cout << v[0] << ' ' << v2[1] << endl;
	std::cout << v[1] << ' ' << v2[0] << endl;
}
