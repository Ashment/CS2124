#include <string>
#include <array>
#include <iostream>
#include <fstream>
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

	array<InFormat, 24> fIn;
	//Using array to not remove dependency on std_lib_facilities.h.
	//Output will always have 24 rows because I'm too lazy to write a
	//dynamic array. Pease understand.
	size_t curIndex = 0;
	int curHr;
	double curLow;
	double curHigh;
	char sep1;
	char sep2;

	while (ist >> curHr >> sep1 >> curLow >> sep2 >> curHigh && curIndex < fIn.size()){
		fIn[curIndex] = InFormat{curHr, curLow, curHigh};
		curIndex += 1;
	}
	for (size_t i=0; i<fIn.size(); i++){
		ost << '(' << fIn[i].hour << "\t"
			<< fIn[i].low << "\t" << fIn[i].high
			<< ')' << endl;
	}
	return 0;
}




