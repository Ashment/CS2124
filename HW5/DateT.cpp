
#include "std_lib_facilities.h"
#include "date.h"

void PrintHelp();

int main(){
	Date tempDate;
	Date today{2000, 5, 22, false};

	bool equalit = today == tempDate;
	
	cout << "Enter Initial Date(YYYY/MM/DD): ";
	cin >> today;
	cout << "The Date Set is: " << today;
	cout << "this is set and printed with stream operator overloads '<<' and '>>'.\n";

    cout << "\nInteract with Date class here.\n"
        << "type 'h' for help.\n";
    char cmd;
    while(cin){
        cout << "|> ";
        cin >> cmd;
        switch(cmd){
            case 'h':
                PrintHelp();
                break;
			case 'q':
				return 0;
			case 'p':
				cout << "The date is: " << today;
				cout << "Use f for full date print" << endl;
				break;
			case 's':
				cout << "Enter date to set(YYYY/MM/DD): ";
				cin >> today;
				cout << "The Date Set is: " << today;
				break;
			case 'd':
				cout << "Number of days to add: ";
				int nd;
				cin >> nd;
				today.addDay(nd);
				cout << "The new date is: " << today;
				break;
			case 'm':
				cout << "Number of months to add: ";
				int nm;
				cin >> nm;
				today.addMonth(nm);
				cout << "The new date is: " << today;
				break;
			case 'y':
				cout << "Number of years to add: ";
				int ny;
				cin >> ny;
				today.addYear(ny);
				cout << "The new date is: " << today;
				break;
			case 'f':
				cout << "The full date is: " << endl;
				today.printFull();
				break;
			case 'e':
				cout << "Current date is: " << today;
				cout << "Enter date to compare(YYYY/MM/DD): ";
				cin >> tempDate;
				equalit = tempDate==today;
				cout << "EQUALITY TEST: " << equalit << endl;
				break;

			default:
				cout << "Invalid Entry. Type 'h' for help.\n";
				break;
       }
    }

}

void PrintHelp(){
    cout << endl
        << "Below are commands for interacting with Date.\n"
        << "h : help\n" << "p : print date\n" << "s : set date\n"
        << "d : add days\n" << "m : add months\n" << "y : add years\n"
		<< "e : test equality\n"
		<< "q : quit\n\n";
	return;
}
