#include <iostream>

const int k = 3;
const int num = 42;
int D[num];

int* getDArray(int *D,int k){
    int j = 0;
    for(int i = 0;i<num;i+=2){
        D[i]=k+j;
        D[i+1]=D[i]*-1;
        j++;
    }
    return D;
}


int arrayOutput(int *arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::cout<<"Array : "<<std::endl;
    arrayOutput(getDArray(D,k),num);
}