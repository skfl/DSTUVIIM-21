#include <iostream>
#include <cmath>
using namespace std;

double calculateY(double start,int step){
    double y = sqrt(start);
    double tmp = sqrt(start);
    for(int i = start-step; i>=step; i-=step){
        y+=sqrt(tmp+i);
        tmp = sqrt(tmp+i);
    }
    return y;
}
int main(){
    cout<<calculateY(99,3);
}
