#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<const string, function<double(double)> > dispTable {
    {"sin", [](double i) {return sin(i); }},
    {"cos", [](double i) {return cos(i); }},
    {"tan", [](double i) {return tan(i); }},
    {"asin", [](double i) {return asin(i); }},
    {"acos", [](double i) {return acos(i); }},
    {"atan", [](double i) {return atan(i); }},
    {"log", [](double i) {return log(i); }},
    {"log2", [](double i) {return log2(i); }},
    {"log10", [](double i) {return log10(i); }},
    {"e", [](double i) {return pow(M_E, i); }},
    {"sqrt", [](double i){return sqrt(i); }}
};

double exec_func(string fname, double arg){
    try{
        return dispTable[fname](arg);
    }catch(exception){
        cout << "Undefined Function " << fname << endl;
    }
    return 0.0;
}
