#include <iostream>

enum RetType {
	dbl,
	mat,
	und,
};

class RetVal{
	public:
		//ERRORS
		class BadOp {};
		class BadRet {};

	
		//CONSTRUCTORS
		RetVal() {};
		RetVal(double d) {dval = d; rType = dbl;}
		//___MATRIX CONSTRUCTOR HERE___


		//GETTERS AND SETTERS
		double get_dval() {return dval;}
		void set_dval(double d) {dval = d;}
		//___MATRIX GET/SET HERE___
		bool isDouble() const {return rType == dbl;}
		bool isMatrix() const {return rType == mat;}


		//OPERATIONS
		RetVal operator+=(const RetVal& other);
		RetVal operator-=(const RetVal& other);
		RetVal operator*=(const RetVal& other);
		RetVal operator/=(const RetVal& other);
		//OVERLOADS
		friend std::ostream& operator<<(std::ostream& os, const RetVal& rv);


	private:
		double dval = 0.0;
		//Matrix mat;
		RetType rType = und;

};
