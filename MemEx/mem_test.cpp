#include <iostream>

int main(){
    int i = 1;
    int *p;
    while(true){
        std::cout << "iteration: " << i << endl;
        p = new int[i];
        i+=1;
    }
    return 0;
}
