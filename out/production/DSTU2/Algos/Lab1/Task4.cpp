#include <iostream>
int N = 88;

int find_k(int N){
    int num = 3;
    if(N<=3){
        std::cout << "Required number is 3 in power less than 1"<<std::endl;   
        return -1;    
    }
    while(num*3<N){
        num *= 3;
    }
    std::cout << "Required number is : "<< num <<std::endl;

}
int main() {
    find_k(N);
}