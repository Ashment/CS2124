#include "std_lib_facilities.h"

const char cInvalid = 'e';
const char cNum = '#';
const char cName = 'a';
const char cPrint = ';';
const char cQuit = 'q';


class Token{
	public: 
		char type;
		double value;
		string name;
		//CONSTRUCTORS
		Token(char ch){
			type = ch;
			value = 2053;
		}
		Token(char ch, double val){
			type = ch;
			value = val;
		}
		Token(char ch, string n){
			type = ch;
			name = n;
		}
};

class TokenStream{
	public:
		Token get();
		void putback(Token t);
        void clearbuffer();
	private:
        vector<Token> buffer;
};
