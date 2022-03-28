#include <iostream>
int arr[4]={1,7,5,4};

int* changeMinMax(int *arr){
    int minIndex=0;
    int maxIndex=0;
    for(int i=1;i<sizeof(arr);i++){
        if(arr[i]<arr[minIndex]){
            minIndex = i;
        }
        if(arr[i]>arr[maxIndex]){
            maxIndex = i;
        }
    }
    int tmp = arr[minIndex];
    arr[minIndex]=arr[maxIndex];
    arr[maxIndex]=tmp;
    return arr;
}
int arrayOutput(int *arr){
    for(int i = 0;i<sizeof(arr);i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    arrayOutput(arr);
    arrayOutput(changeMinMax(arr));
}