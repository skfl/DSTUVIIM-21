#include <iostream>
                                                                                                                
const int size = 10;
int arr[size]={1,0,1,0,0,6,7,8,0,10};

int* compressArray(int *arr,int size){
    
    for(int i = 0;i < size;i++){
        if(arr[i] == 0){
            for(int j = i;j < size;j++){
                if(arr[j] != 0){
                    arr[i] = arr[j];
                    arr[j] = 0;
                    break;
                }
            }
        }
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
    std::cout<<"Compressed array : "<<std::endl;
    arrayOutput(compressArray(arr,size),size);
}