#include <string>
#include <array>
#include <iostream>
#include <fstream>
#include "std_lib_facilities.h"
using namespace std;

struct InFormat {
	int hour;
	double low;
	double high;
};


int main(){

	string iFName;
	cout << "Enter name of (existing) input file: ";
	cin >> iFName;
	ifstream ist {iFName};
	if(!ist){
		cout << "Could not open specified input file.";
		return 1;
	}
	cout << endl;
	string oFName;
	cout << "Enter name of (existing) output file: ";
	cin >> oFName;
	ofstream ost {oFName};
	if(!ost){
		cout << "Could not open specified output file.";
		return 1;
	}
	cout << endl;

	vector<InFormat> fIn;
	int curHr;
	double curLow;
	double curHigh;
	char sep1;
	char sep2;

	while (ist >> curHr >> sep1 >> curLow >> sep2 >> curHigh){
		fIn.push_back(InFormat{curHr, curLow, curHigh});
	}
	for (InFormat i : fIn){
		ost << '(' << i.hour << "\t"
			<< i.low << "\t" << i.high
			<< ')' << endl;
	}
	return 0;
}




