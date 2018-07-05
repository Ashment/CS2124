
#include "std_lib_facilities.h"

int main(){
	string prev = "";
	string current ;
	while (cin >> current){
		if(prev == current)
			cout << "Repeated Word: " << current << "\n";
		prev = current;
	}
}

