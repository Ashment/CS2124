#include "std_lib_facilities.h"
#include "Token.h"

//DEBUG FUNCTIONS
void PrintToken(Token t, string s){
	cout << s << t.type << "|" << t.value << endl;
	return;
}
void Println(string s){
	cout << s << endl;
	return;
}

//TOKEN STREAM FUNCTIONS
void TokenStream::putback(Token t){
	buffer = t;
	full = true;
}

Token TokenStream::get(){
	if(full){
		full = false;
//		PrintToken(buffer, "Out from buffer |> ");
		return buffer;
	}else{	
		Token eToken = Token{'e', 0};
		Token outToken('e');
		
		char ch;
		cin >> ch;
		switch(ch){
			case ';': case 'q': case '(': case '+': case '-': case '^':
			case '/': case '*': case ')': case '%': case '=':
				outToken = Token(ch);
//				PrintToken(outToken, "OutToken |> ");
				return outToken;
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9': 
				cin.putback(ch);
				double val;
				cin >> val;
				outToken = Token('#', val);
//				PrintToken(outToken, "OutToken |> ");
				return outToken;
			default:
				if(isalpha(ch)){
					string vName;
					vName += ch;
					while(cin.get(ch) && (isalpha(ch) || isdigit(ch))){
						vName += ch;
					}
					cin.putback(ch);
//					cout << "VAR NAME | " << vName << endl;
					return Token{cName, vName};
				}else if(ch == '['){

				}
		}
	return eToken;
	}
}
