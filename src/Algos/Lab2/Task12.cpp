#include <iostream>

const int size=7;
const int sizeTmp=7;
int arr[size] ={1,2,3,4,5,5,3};

int* reverseArray(int *arr,int size){
    int *tmp = new int[sizeTmp];
    int j = size-1;
    for(int i = 0;i<size;i++){
        tmp[i]=arr[j];
        j--;
    }
    return tmp;
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
    std::cout<<"Reversed Array : "<<std::endl;
    arrayOutput(reverseArray(arr,size),size);
}