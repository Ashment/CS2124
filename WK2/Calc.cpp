#include "std_lib_facilities.h"

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

//NON-CLASS FUNCTIONS

Vector<Token> tokens;
TokenStream tokenStream;

int main(){

	for(Token t=tokenStream.get(); t.type != 'q'; t=tokenStream.get()){
		tokens.push_back(t);
	}

	for(Token t : tokens){
		cout << t.type << "|" << t.value << "\n";
	}

}

