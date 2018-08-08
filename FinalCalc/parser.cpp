#include "std_lib_facilities.h"
#include "Token.h"
#include "parser.h"
#include "vars.h"
#include "func.h"

//PARSER DEFINITIONS
double statement(TokenStream& tokenStream){
	Token t = tokenStream.get();
	if(t.type == cName){
		string vName = t.name;
//		cout << "statement() got var with name " << vName << endl;
		Token next = tokenStream.get();
		if(next.type == '='){
			double eRight = expression(tokenStream);
			set_value(vName, eRight);
			return eRight;
		}else if(next.type == ';'){
			tokenStream.putback(next);
			return get_value(vName);
		}else{
            tokenStream.putback(next);
        }
	}
	tokenStream.putback(t);
	return expression(tokenStream);
}

double expression(TokenStream& tokenStream){
	cout << "Calling expression()" << endl;
	double left = term(tokenStream);
	Token t = tokenStream.get();
	cout << "Initial left |> " << left << endl;
	while(true){
//		cout << "EXPRESSION LOOP" << endl;
		switch(t.type){
			case '+':
				cout << "Found +" << endl;
				left += term(tokenStream);
				break;
			case '-':
//				cout << "Found -" << endl;
				left -= term(tokenStream);
				break;
			default:
//				cout << "Returning left" << endl;
				tokenStream.putback(t);
				cout << "RETURNING FROM EXPRESSION |> " << left << endl;
				return left;
		}
		t = tokenStream.get();
	}
}


double term(TokenStream& tokenStream){
//	cout << "Calling term()" << endl;
	double left = expo(tokenStream);
	Token t = tokenStream.get();

	while(true){
//		cout << "TERM LOOP" << endl;
		switch(t.type){
			case '*':
			{
				left *= expo(tokenStream);
				t = tokenStream.get();
				break;
			}
			case '/':
			{
				double divisor = expo(tokenStream);
				if(divisor == 0)
					error("Division by zero.");
				left /= divisor;
				t = tokenStream.get();
				break;
			}
			case '%':
			{
				double next = expo(tokenStream);
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

double expo(TokenStream& tokenStream){
//	cout << "Calling expo()" << endl;
	double left = primary(tokenStream);
    cout << "Expo received value: " << left << endl;
	Token t = tokenStream.get();

	while(true){
//		cout << "EXPO LOOP" << endl;
		switch(t.type){
			case '^':
			{
//				cout << "GOT EXPO" << endl;
				left = pow(left, primary(tokenStream));
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
        case cName:
        {
            Token next = tokenStream.get();
            if(next.type == '('){
                double d = expression(tokenStream);
                next = tokenStream.get();
                if (next.type != ')') error("Closing bracket ')' expected but not found.");
                d = exec_func(t.name, d);
                return d;
            }else{
                tokenStream.putback(next);
                return get_value(t.name);
            }
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
