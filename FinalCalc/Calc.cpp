#include "std_lib_facilities.h"
#include "Token.h"
#include "vars.h"
#include "parser.h"

const string prompt = "> ";
void PrintHelp();


int main(){	
	TokenStream ts;

	try{
		double val = 0.0;
        cout << "Calculator for Object Oriented Programming." << endl;
        cout << "Input Below. Type 'h' into prompt for help." << endl;
		while(cin){
			cout << prompt;
			Token t = ts.get();
//			cout << "Main got Token |> " << t.type << "|" << t.value << endl;
			if(t.type == 'q') break;
            if(t.type == 'h'){
                PrintHelp();
            }else if(t.type == ';'){
				cout << '=' << val << '\n';
                ts.clearbuffer();
            }else{
				ts.putback(t);
				val = statement(ts);
			}
//			cout << "VAL RETURNED: " << val << endl;
		}
	}catch(int e){
		return 1;
	}
	return 0;
}



void PrintHelp(){
    cout << "Available Operations: "
        << "+ - * / % ^" << endl
        << "\nAvailable Functions: "
        << "sin, cos, tan" << endl
        << "asin, acos, atan" << endl
        << "log, log2, log10" << endl
        << "e(^), sqrt" << endl
        << "\nFor Assigning Variable, use '=' (x=3)." << endl
        << "\nFor Print, use ';' (3+7;)." << endl
        << endl;
    return;
}

