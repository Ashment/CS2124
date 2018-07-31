#include <iostream>

char c = 'a';
int i = 4092;
double d = 3.14;
char* pC = &c;
int* pI = &i;
double* pD = &d;


int main(){
	std::cout << "pI = " << pI << " with value " << *pI << std::endl;
	std::cout << "pC = " << pC << " with value " << *pC << std::endl;
	std::cout << "pD = " << pD << " with value " << *pD << std::endl;

	std::cout << "size of pI = " << sizeof(pI) << ", size of (i) = " << sizeof(i) << std::endl;
	std::cout << "size of pC = " << sizeof(pC) << ", size of (c) = " << sizeof(c) << std::endl;
	std::cout << "size of pD = " << sizeof(pD) << ", size of (d) = " << sizeof(d) << std::endl;
}
