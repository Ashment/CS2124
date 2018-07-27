#include <iostream>
#include <string>
using namespace std;

//Not really useful.
enum Month{
    jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Date {
	public:
        //CONSTRUCTORS
		Date(int yy, int mm, int dd, bool overrideValidity = false);

        //GETTERS AND SETTERS
		void AddDay(int n);
		int getYear();
		int getMonth();
		int getDay();
		void setYear(int n);
		void setMonth(int n);
		void setDay(int n);
        void addYear(int n);
        void addMonth(int n);
        void addDay(int n);
		void printFull();

        //UTILITY FUNCTIONS
        string toString() const;
        bool isValid();
        void ForceValid();

        //OPERATOR OVERLOADS
        friend ostream& operator << (ostream &out, const Date &d);
		friend istream& operator >> (istream &in, Date &d);

	private:
		int yy;
		int mm;
		int dd;

};
