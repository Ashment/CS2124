#include "std_lib_facilities.h"

int main(){
	double sDbl = 6666666666;
	int sInt = 242;
	char sChar = 'x';

	cout << "Now Converting Double to:\n";
	cout << "INITIAL DOUBLE VALUE: " << sDbl << "\n";

	int tInt = sDbl;
	cout << "int   |> " << tInt << "\n";
	double bDbl = tInt;
	cout << "Converted back |> " << bDbl << "\n";
	char tC = sDbl;
	cout << "char  |> " << tC << "\n";
	bDbl = tC;
	cout << "Converted back |> " << bDbl << "\n";
	cout << "******************\n"
		<< "Also beware conversion of decimal numbers, which char and int do not support."
		<< "\n******************\n";

	bool tB = sDbl;
	cout << "bool  |> " << tB << "\n";
	bDbl = tB;
	cout << "Converted back |> " << bDbl << "\n";


	cout << "\nNow Converting Int to:\n";
	cout << "INITIAL INT VALUE: " << sInt << "\n";
	char tCc = sInt;
	cout << "char  |> " << tCc << "\n";
	int bInt = tCc;
	cout << "Converted back |> " << bInt << "\n";

	bool tBb = sInt;
	cout << "bool  |> " << tBb << "\n";
	bInt = tBb;
	cout << "Converted back |> " << bInt << "\n";

	cout << "\nNow Converting Char to:\n";
	cout << "INITIAl CHAR VALUE: " << sChar << "\n";
	bool tBbb = sChar;
	cout << "bool  |> " << tBbb << "\n";
	char bChar = tBbb;
	cout << "Converted back |> " << bChar << "\n";

	cout << "\nDONE\n";

}


