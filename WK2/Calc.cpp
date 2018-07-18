#include "std_lib_facilities.h"
#include "parser.h"

class Token{
	public: 
		char type;
		double value;
};

class TokenStream{
	public:
		Token get();
		void putback(Token t);
	private:
		Token buffer;
		bool full{false};
};

//TOKEN STREAM FUNCTIONS
void TokenStream::putback(Token t){
	buffer = t;
	full = true;
}
Token TokenStream::get(){
	if(full){
		full = false;
		return buffer;
	}else{	
		Token eToken = Token{'e', 0};
		
		char ch;
		cin >> ch;
		switch(ch){
			case ';': case 'q': case '(': case '+': case '-':
			case '/': case '*': case ')': case '%': case 'h':
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
}

Vector<Token> tokens;
TokenStream tokenStream;

//DEBUG FUNCTIONS
void PrintToken(Token t, string s){
	cout << s << t.type << "|" << t.value << endl;
	return;
}

//PARSER DEFINITIONS
double expression(){
	double left = term();
	Token t = tokenStream.get();
//	PrintToken(t, "EXPRESSION SCOPE TOKEN |> ");
	while(true){
		switch(t.type){
			case '+':
				left += term();
				break;
			case '-':
				left -= term();
				break;
			default:
				tokenStream.putback(t);
				return left;
		}
		t = tokenStream.get();
	}
}
double term(){
	return primary();
}
double primary(){
	Token t = tokenStream.get();
//	PrintToken(t, "PRIMARY SCOPE TOKEN |> ");
	return t.value;
}

int main(){	

	try{
		double val = 0.0;
		while(cin){
			Token t = tokenStream.get();
//			PrintToken(t, "MAIN SCOPE TOKEN |> ");
			if(t.type == 'q') break;
			if(t.type == ';') 
				cout << '=' << val << '\n';
			else
				tokenStream.putback(t);
			val = expression();
//			cout << "VAL RETURNED: " << val << endl;
		}
	}catch(std::error_code){
		return 1;
	}


	/*STREAM AND TOKEN TESTING
	for(Token t=tokenStream.get(); t.type != 'q'; t=tokenStream.get()){
		tokens.push_back(t);
	}

	for(Token t : tokens){
		cout << t.type << "|" << t.value << "\n";
	}
	*/

}

