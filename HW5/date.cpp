#include "std_lib_facilities.h"
#include "date.h"


int mDays[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
int mDaysLeap[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31};

//CONSTRUCTOR
Date::Date(int y, int m, int d):yy{y}, mm{m}, dd{d}{
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
int Date::getYear(){
	return yy;}
int Date::getMonth(){
	return mm;}
int Date::getDay(){
	return dd;}


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
    if(!isValid()){
        if(dd > mDays[mm]){
            if(yy%4 == 0){
                if(dd > mDaysLeap[mm]){
                    mm += 1;
                    dd = 1;
                }
            }else{
                mm += 1;
                dd = 1;
            }
        }
        if(mm > 12){
            yy += 1;
            mm = 1;
        }
    } 
}



//OPERATOR OVERLOADS
std::ostream& operator << (std::ostream &out, const Date &d){
    out << d.toString() << endl;
    return out;
}


















