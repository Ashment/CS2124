#include "std_lib_facilities.h"

class Token{
	public: 
		char type;
		double value;
};

Token get_token(){
	Token eToken = Token{'e', 0};
	
	char ch;
	cin >> ch;
	switch(ch){
		case ';': case 'q': case '(': case '+': case '-':
		case '/': case '*': case ')': case '%':
			return Token{ch, 0};
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9': 
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{'#', val};
	}
	return eToken;
}

Vector<Token> tokens;

int main(){
	Token t = get_token();
	while(t.type != 'q'){
		tokens.push_back(t);
		t=get_token();
	}

	for(Token t : tokens){
		cout << t.type << "|" << t.value << "\n";
	}
}

