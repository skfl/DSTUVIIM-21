#include <iostream>

int findMinimal(){
    int min;
    int tmp;
    std::cout << "Type number : "<<std::endl;
    std::cin >> tmp;
    min = tmp;
    for(int i = 0;i<9;i++){
        std::cout << "Type number : "<<std::endl;
        std::cin >> tmp;
        if(tmp<min){
            min=tmp;
        }
    }
    std::cout << "Minimal number is : "<<min<<std::endl;
}

int main(){
    findMinimal();
}