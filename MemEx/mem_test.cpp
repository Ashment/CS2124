#include <iostream>

int main(){
    int i = 1;
    int *p;
    while(true){
        try{
            p = new int[10000 * i];
            i+=1;
        }catch(const std::exception& e){
            std::cout << "Iteration: " << i << std::endl;
            std::cout << "Error: " << e.what() << std::endl;
            return 0;
        }
    }
    return 0;
}
