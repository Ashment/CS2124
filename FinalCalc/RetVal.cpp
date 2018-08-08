#include "RetVal.h"
#include <iostream>
#include "std_lib_facilities.h"


//RetVal OPERATIONS
RetVal RetVal::operator+=(const RetVal& other){
	if(this->isDouble()){
		if(other.isDouble()){
			this->dval = this->dval + other.dval;
		}else{
			throw runtime_error("Incompatible Operation.");
		}
	}
	return *this;
}
RetVal RetVal::operator-=(const RetVal& other){
	if(this->isDouble()){
		if(other.isDouble()){
			this->dval = this->dval - other.dval;
		}else{
			throw runtime_error("Incompatible Operation.");
		}
	}
	return *this;
}
RetVal RetVal::operator*=(const RetVal& other){
	if(this->isDouble()){
		if(other.isDouble()){
			this->dval = this->dval * other.dval;
		}else{
			throw runtime_error("Incompatible Operation.");
		}
	}
	return *this;
}
RetVal RetVal::operator/=(const RetVal& other){
	if(this->isDouble()){
		if(other.isDouble()){
			this->dval = this->dval + other.dval;
		}else{
			throw runtime_error("Incompatible Operation.");
		}
	}
	return *this;
}




