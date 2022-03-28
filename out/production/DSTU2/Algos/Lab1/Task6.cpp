#include <iostream>
int N =25;

int isPowerOfFive(int N){
    int k = 1;
    while(true){
        if(k!=N){
            if(k<N){
                k*=5;
            }else{
                std::cout << "Number : "<< N <<" is not power of 5"<<std::endl;
                return -1;    
            }
        }else{
            std::cout << "Number : "<< N <<" is power of 5"<<std::endl;
            return -1;
        }
    }
}

int main(){
    isPowerOfFive(N);
}