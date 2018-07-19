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
	double left = primary(tokenStream);
	Token t = tokenStream.get();

	while(true){
		switch(t.type){
			case '*':
			{
				left *= primary(tokenStream);
				t = tokenStream.get();
				break;
			}
			case '/':
			{
				double divisor = primary(tokenStream);
				if(divisor == 0)
					error("Division by zero.");
				left /= divisor;
				t = tokenStream.get();
				break;
			}
			case '%':
			{
				double next = primary(tokenStream);
				if(next == 0)
					error("Division by zero.");
				left = fmod(left, next);
				t = tokenStream.get();
				break;
			}
			default:
			{
				tokenStream.putback(t);
				return left;
			}
		}
	}
}


double primary(TokenStream& tokenStream){
//	cout << "Calling primary()" << endl;
	Token t = tokenStream.get();
	switch(t.type){
		case '(':
		{
			double next = expression(tokenStream);
			t = tokenStream.get();
			if(t.type != ')')
				error("Closing bracket ')' expected but not found.");
			return next;
		}
		case '#':
		{
			return t.value;
		}
		case '-':
		{
			return -primary(tokenStream);
		}
		case '+':
		{
			return primary(tokenStream);
		}
		default:
		{
			error("Primary acquisition failure.");
		}


	}

	return t.value;
}