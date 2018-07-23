

enum Month{
	January = 1, February, March, April, May, June, 
	July, August, Septembber, October, November, December,
};

class Date {
	public:
		Date(int yy, int mm, int dd);
		Date(Month eMonth);

		void AddDay(int n);
		int getYear();
		int getMonth();
		int getDay();

		Month eMonth;

		void EMonthTest();

	private:
		int yy;
		int mm;
		int dd;

};
