#include "std_lib_facilities.h"

int main(){
	vector<double> v;
	double curIn;
	while(cin >> curIn){
		v.push_back(curIn);
	}
	cout << "Data in Vector:\n{ ";
	for(double x:v){
		cout << x << " ";
	}
	cout << "}\n";
}


