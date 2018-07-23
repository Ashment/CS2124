#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int y, int m, int d):yy{y}, mm{m}, dd{d}{
}
Date::Date(Month em):eMonth{em}{
}

void Date::EMonthTest(){
	int oInt = eMonth;
	cout << eMonth << "|" << oInt << endl;
}

void Date::AddDay(int n){
	cout << "Adding day:" << n << endl;

	return;
}

int Date::getYear(){
	return yy;
}

int Date::getMonth(){
	return mm;
}

int Date::getDay(){
	return dd;
}
