#include <iostream>
#include <cmath>
using namespace std;

double calculateY(double x,int maxPow){
    double y = pow(x,1.0/maxPow);;
    double tmp = pow(x,1.0/maxPow);
    for(int i = maxPow-1;i>=2;i--){
        y+=pow(x+tmp,1.0/i);
        tmp = pow(x+tmp,1.0/i);
    }
    y+=x;
    return y;
}

int main(){
    cout<<calculateY(3,10);
}