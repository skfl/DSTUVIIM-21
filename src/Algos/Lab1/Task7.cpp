#include <iostream>

double P = 10; // 0 - 25
double dep = 1000;

int calculateDeposit(double P,double dep){
    int k = 0;
    double percent = P/100;
    while(true){
        if(dep<1100){
            dep += dep*percent;
            k+=1;
        }else{
            std::cout << "It required : "<<k<< "month(s)"<<std::endl;
            std::cout << "Final deposit is equals to "<<dep<< std::endl;
            return -1;
        }
    }    
}

int main(){
    calculateDeposit(P,dep);
    
}