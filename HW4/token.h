const char cInvalid = 'e';
const char cNum = '#';
const char cName = 'a';
const char cPrint = ';';
const char cQuit = 'q';


class Token{
	public: 
		char type;
		double value;
		//CONSTRUCTORS
		Token(char ch){
			type = ch;
			value = 2053;
		}
		Token(char ch, double val){
			type = ch;
			value = val;
		}
};

class TokenStream{
	public:
		Token get();
		void putback(Token t);
	private:
		Token buffer = Token('i', 2003);
		bool full{false};
};