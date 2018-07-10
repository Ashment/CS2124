#include "std_lib_facilities.h"
#include <locale>

int main(){
	std::locale loc;
	vector<string> v;
	cout << "Input words separated by line break.\n";
	
	for(string curIn; cin>>curIn;){
		//conver all input to lowercase and push to vector.
		for(std::string::size_type i=0; i<curIn.size(); i++)
			curIn[i]=std::tolower(curIn[i],loc);
		v.push_back(curIn);	
	}
	
	sort(v);

	string prev=v[0];
	int curRep=0;
	for(string s:v){
		if(s==prev){
			//Increment counter.
			curRep += 1;
		}else{
			//Print stats and reset counters.
			cout << prev << ": " << curRep << "\n";
			curRep = 1;
			prev = s;
		}
	}
	cout << prev << ": " << curRep << "\n";
	return 0;
}


