#include "std_lib_facilities.h"
#include "vars.h"

int main(){
	set_value("a", 3);
	set_value("b", 4);
	set_value("c", 5);

	double d;
	d = get_value("a");
	cout << "a = " << d << endl;
	d = get_value("b");
	cout << "b = " << d << endl;
	d = get_value("c");
	cout << "c = " << d << endl;

}



