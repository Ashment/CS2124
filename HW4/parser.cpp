#include "std_lib_facilities.h"
#include "token.h"
#include "parser.h"

//PARSER DEFINITIONS
double expression(TokenStream& tokenStream){
//	cout << "Calling expression()" << endl;
	double left = term(tokenStream);
	Token t = tokenStream.get();
//	cout << "Initial left |> " << left << endl;
//	cout << "Operator |> " << t.type << endl;
//	PrintToken(t, "EXPRESSION SCOPE TOKEN |> ");
	while(true){
		switch(t.type){
			case '+':
//				cout << "Found +" << endl;
				left += term(tokenStream);
				break;
			case '-':
//				cout << "Found -" << endl;
				left -= term(tokenStream);
				break;
			default:
//				cout << "Returning left" << endl;
				tokenStream.putback(t);
//				cout << "RETURNING FROM EXPRESSION |> " << left << endl;
				return left;
		}
		t = tokenStream.get();
	}
}

double term(TokenStream& tokenStream){
//	cout << "Calling term()" << endl;
	return primary(tokenStream);
}


double primary(TokenStream& tokenStream){
//	cout << "Calling primary()" << endl;
	Token t = tokenStream.get();
//	PrintToken(t, "PRIMARY SCOPE TOKEN |> ");
	return t.value;
}