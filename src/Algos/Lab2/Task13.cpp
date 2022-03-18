#include <iostream>

const int size=7;
int arr[size] ={1,2,3,4,-1,51,3};

int* setZeros(int *arr,int size){
    
    int maxIndex = 0;
    int max = arr[0];

    for(int i = 0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
            maxIndex = i; 
        }
    }
    for(int i = 0;i<maxIndex;i++){
        arr[i] = 0;
    }
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
    arrayOutput(arr,size);
    std::cout<<"New array : "<<std::endl;
    arrayOutput(setZeros(arr,size),size);
}