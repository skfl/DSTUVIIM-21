#include <iostream>

const int size=7;
int A[size] ={1,2,3,4,5,5,3};
int D[size];

int* getDArray(int *A,int *D,int size){ 
    
    D[0]=A[0];
    D[1]=A[1];
    D[2]=A[2];

    for(int i=3;i<size;i++){
        D[i]=1;
        for(int j = i-3;j<i;j++){
            D[i]*=A[j];
        }
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
    std::cout<<"A Array : "<<std::endl;
    arrayOutput(A,size);
    std::cout<<"D Array : "<<std::endl;
    arrayOutput(getDArray(A,D,size),size);
}