#include <iostream>

int getMult(){
    int mult=1;
    while (true){
        int a;
        std::cout << "Type number : "<<std::endl;
        std::cin >> a;
        if(a%2==0){
            std::cout << "Product equals to : "<< mult <<std::endl;
            return -1;
        }else{
            mult*=a;
        }
    }
    
    
}

int main(){
    getMult();
}