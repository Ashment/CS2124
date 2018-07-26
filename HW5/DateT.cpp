
#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today{1999, 5, 22, false};

    cout << today;
	
	cout << "Enter Date(YYYY/MM/DD): ";
	cin >> today;
	cout << today;
	cout << "Enter Date(YYYY/MM/DD): ";
	cin >> today;
	cout << today;
}
