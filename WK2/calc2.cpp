#include "std_lib_facilities.h"

int main(){

	cout << "prompt\n";
	int lval = 0;
	int rval;

	int res;

	cin >> lval;
	if(!cin) error("E1");
	for(char op; cin>>op;){
		if(op != 'x'){
			cin>>rval;
			if(!cin) error("E2");

			switch(op){
			case '+':
				lval += rval;
				res = lval;
				cout << res << "\n";
				break;
			case '-':
				lval -= rval;
				res = lval;
				cout << res << "\n";
				break;
			case '*':
				lval *= rval;
				res = lval;
				cout << res << "\n";
				break;	
			case '/':
				lval /= rval;
				res = lval;
				cout <<	res << "\n";
				break;
			default:
				cout << "Invalid Expression.\n";
				return 1;
			}
		}else{
			cout << "Calculator Terminated.\n";
			return 0;
		}
	}
	return 0;
}
