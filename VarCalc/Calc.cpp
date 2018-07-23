#include "std_lib_facilities.h"
#include "Token.h"
#include "vars.h"
#include "parser.h"

const string prompt = "> ";

int main(){	
	TokenStream ts;

	try{
		double val = 0.0;
		while(cin){
			cout << prompt;
			Token t = ts.get();
//			cout << "Main got Token |> " << t.type << "|" << t.value << endl;
			if(t.type == 'q') break;
			if(t.type == ';') 
				cout << '=' << val << '\n';
			else{
				ts.putback(t);
				val = statement(ts);
			}
//			cout << "VAL RETURNED: " << val << endl;
		}
	}catch(int e){
		return 1;
	}

	/* STREAM AND TOKEN TESTING
	for(Token t=tokenStream.get(); t.type != 'q'; t=tokenStream.get()){
		tokens.push_back(t);
	}

	for(Token t : tokens){
		cout << t.type << "|" << t.value << "\n";
	}
	*/
	return 0;
}

