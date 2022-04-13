#include <iostream>
#include <cmath>
using namespace std;

double subFunc(int num,int N){
    double subRes = 0;
    for(int j = 1;j<=N;j++){
        subRes += 1/(num+pow(j,2));
    }
    return subRes;
}

double func(int N,int M){
    double res = 0;
    for(int i = 1;i<=M;i++){
        res+=subFunc(i,N);
    }
    return res;
}

int main(){
    cout<<func(4,4);
}