
#include "std_lib_facilities.h"

int main(){
	string prev = "";
	string current ;
	int number_of_words = 0;
	while (cin >> current){
		++number_of_words;
		if(prev == current){
			cout << "Word Number: " << number_of_words << "\n";
			cout << "Repeated Word: " << current << "\n";
		}
		prev = current;
	}
}

