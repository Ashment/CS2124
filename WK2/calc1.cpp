#include "std_lib_facilities.h"

int main(){

	cout << "prompt\n";
	int lval = 0;
	int rval;

	char op;
	int res;

	cin >> lval >> op >> rval;
	if(op == '+'){
		res = lval + rval;
		cout << res << "\n";
	}else if(op == '-'){
		res = lval - rval;
		cout << res << "\n";
	}else{
		cout << "\nInvalid Expression.\n";
		return 1;
	}

	return 0;
}



