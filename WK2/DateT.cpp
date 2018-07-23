
#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today{1999, 5, 22};

	cout << "Today: "
		<< today.getYear() << "/"
		<< today.getMonth() << "/"
		<< today.getDay() << "\n";

	Date emm{Month{January}};
	emm.EMonthTest();
}
