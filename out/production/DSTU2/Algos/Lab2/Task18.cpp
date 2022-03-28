#include <iostream>

const int size=7;
int arr[size] ={1,21,3,4,-1,5,3};
const int quan = 3;

int* swapElements(int *arr,int size){
    int tmp[quan];
    if(size>=quan*2){
        for(int i=0;i<quan;i++){
            tmp[i]=arr[i];
        }

        int j=size-quan;
        for(int i=0;i<quan;i++){
            arr[i]=arr[j];
            j++;
        }

        j=0;
        for(int i=size-quan;i<size;i++){
            arr[i]=tmp[j];
            j++;
        }
        return arr;
    }else{
        std::cout<<"Can not swap due array size";
    }
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
    std::cout<<"New Array : "<<std::endl;
    arrayOutput(swapElements(arr,size),size);
}