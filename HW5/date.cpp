#include "std_lib_facilities.h"
#include "date.h"

int mDays[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
int mDaysLeap[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31};

string mLookup[13] =
{"invalid", "January", "February", "March", "April", 
	"May", "June", "July", "August", "September", 
	"October", "November", "December"};

//CONSTRUCTOR
Date::Date(int y, int m, int d, bool oV):yy{y}, mm{m}, dd{d}{
	if(!oV){
		if(!isValid()){
			ForceValid();
			cout << "Invalid Construction. Validy has been enforced.\n";
		}
	}
}


//GETTERS AND SETTERS
void Date::addDay(int n){
    dd += n;
    ForceValid();
	return;
}
void Date::addMonth(int n){
    mm += n;
    ForceValid();
    return;
}
void Date::addYear(int n){
    yy += n;
    ForceValid();
    return;
}
void Date::setYear(int n){
	yy = n;
}
void Date::setMonth(int n){
	Date tDate{yy, n, dd, false};
	if(!tDate.isValid()){
		cout << "Invalid date, date remains unchanged." << endl;
		return;
	}
	mm = n;
	return;
}
void Date::setDay(int n){
	Date tDate{yy, mm, n, false};
	if(!tDate.isValid()){
		cout << "Invalid date, date remains unchanged." << endl;
		return;
	}
	dd = n;
	return;
}
int Date::getYear(){
	return yy;}
int Date::getMonth(){
	return mm;}
int Date::getDay(){
	return dd;}
void Date::printFull(){
	cout << mLookup[mm] << " " << dd 
		<< ", " << yy << endl; 
	return;
}


//UTILITY FUNCTIONS
string Date::toString() const{
    string outS = std::to_string(yy);
    outS += "/" + std::to_string(mm);
    outS += "/" + std::to_string(dd);
    return outS;
}

bool Date::isValid(){
   if(mm > 12){
       return false;
   }
   if(dd > mDays[mm]){
        if(yy%4 == 0){
            if(dd > mDaysLeap[mm])
                return false;
        }else{
            return false;
        }
   }
   return true;
}

void Date::ForceValid(){
    while(!isValid()){
        if(dd > mDays[mm]){
            if(yy%4 == 0){
                if(dd > mDaysLeap[mm]){
                    dd -= mDaysLeap[mm];
                    mm += 1;
                }
            }else{
				dd -= mDaysLeap[mm];
				mm += 1;
            }
        }
        if(mm > 12){
            yy += 1;
            mm -= 12;
        }
    } 
}



//OPERATOR OVERLOADS
std::ostream& operator << (std::ostream &out, const Date &d){
    out << d.toString() << endl;
    return out;
}
std::istream& operator >> (std::istream &in, Date &d){
	int inY; int inM; int inD;
	char sep1; char sep2;
	in >> inY >> sep1 >> inM >> sep2 >> inD;
	Date tDate{inY, inM, inD, true};
	if(!tDate.isValid()){
		cout << "Invalid date, date remains unchanges.\nUse format YYYY/MM/DD.\n";
		return in;
	}
	d.setYear(inY);
	d.setMonth(inM);
	d.setDay(inD);
	return in;
}


