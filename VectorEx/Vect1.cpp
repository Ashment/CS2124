#include "std_lib_facilities.h"


//This class has memory management issues as a demonstration.
class vect{
	int sz;
	double* elem;

	public:
	vect(int s):sz{s}, elem{new double [s]} {}
	~vect() {delete[] elem;}
	double get(int i) {return elem[i];}
	void set(int i, double d){
		elem[i]=d;
	}
};
