
#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today{1999, 5, 22, false};

    cout << today;
	
	cout << "Enter Date(YYYY/MM/DD): ";
	cin >> today;
	cout << today;
	cout << "Enter Date(YYYY/MM/DD): ";
	cin >> today;
	cout << today;

    cout << "Interact with Date class here.\n"
        << "type 'h' for help.\n";
    char cmd;
    while(cin){
        cout << "|> ";
        cin >> cmd;
        switch(cmd){
            case 'h':
                PrintHelp();
                break;
       }
    }

}

void PrintHelp(){
    cout << endl
        << "Below are commands for interacting with Date.\n"
        << "h : help\n" << "p : print date\n" << "s : set date\n"
        << "d : add days\n" << "m : add months\n" << "y : add years\n"
}
