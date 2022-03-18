#include <iostream>
int  X = 15;
int Y = 30;
int Z = 7;

void find(int x){
    if((x >= 7 ) && (x <= 30 )){
            if(x%2==0){
                std::cout << "Number : "<< x << " belongs to segment" <<std::endl;
            }else{
                std::cout << "Number : "<< x << " doesn't belong to segment" <<std::endl;
            }
    }else{
        std::cout << "Number : "<< x << " doesn't belong to segment" <<std::endl;
    }
}

int main() {
    find(X);
    find(Y);
    find(Z);
}