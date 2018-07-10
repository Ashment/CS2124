#include "std_lib_facilities.h"

int main(){
	cout << "Input temparatures separated by line break to find average.\n";

	vector<double> uInputs;
	for(double temp; cin>>temp;)
		uInputs.push_back(temp);
	double total=0.0;
	for(double temp:uInputs)
		total += temp;
	double mean = total / uInputs.size();
	cout << "The mean of the inputs is: " << mean << "\n";
	sort(uInputs);
	cout << "The median of the inputs is: " << uInputs[uInputs.size()/2] << "\n";
	
	return 0;
}
