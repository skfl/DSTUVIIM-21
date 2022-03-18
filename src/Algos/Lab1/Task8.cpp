#include <iostream>

int N = 5;

int findMax(int N){
    
    int tmp;
    std::cout << "Type number : "<<std::endl;
    std::cin >> tmp;
    int max;
    max = tmp;

    for(int i = 0;i<N-1;i++){
        std::cout << "Type number : "<<std::endl;
        std::cin >> tmp;
        if(tmp>max){
            max=tmp;
        }
    }
    std::cout << "Maximal number is : "<<max<<std::endl;
}

int main(){
    findMax(N);
}