#include <iostream>

const int size = 16;
int A[size]={5, 4, 3, 1, 2, 3, 1, 2, 8, 17, 40, 1, 2, 3, 10,11};
int B[3]={1,2,3};
int* checkForOneTwoThree(int *arr,int size){
    int cnt = 0;
    for(int i = 0;i < size;i++){
        if(arr[i]==1 && arr[i+1]==2 && arr[i+2]==3){
            cnt+=1;
            arr[i+1] = 0;
        }
    }
    std::cout<<"There are : "<<cnt<<" occurencies"<<std::endl;
    return arr;
}
int arrayOutput(int *arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::cout<<"Array : "<<std::endl;
    arrayOutput(A,size);
    std::cout<<"New array : "<<std::endl;
    arrayOutput(checkForOneTwoThree(A,size),size);
}