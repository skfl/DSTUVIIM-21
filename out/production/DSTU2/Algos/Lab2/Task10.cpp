#include <iostream>

const int size=7;
int A[size] ={1,2,3,4,5,5,3};
int C[size];

int* getCArray(int *A,int *C,int sizes){
    C[0]=A[0];
    for(int i=1;i<sizes;i++){
        for(int j=0;j<=i;j++){
            C[i]+=A[j];
        }
    }
    return C;
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
    std::cout<<"C Array : "<<std::endl;
    arrayOutput(getCArray(A,C,size),size);
}