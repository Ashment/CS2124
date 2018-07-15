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
    cout << "Input Tokens. Use q to print and exit.\n";

	for(Token t=get_token(); t.type != 'q'; t=get_token()){
		tokens.push_back(t);
	}

    cout << "Type e is error token, type # is number token\n";
    cout << "TYPE | VALUE\n";

	for(Token t : tokens){
		cout << t.type << "|" << t.value << "\n";
	}
}

