#include <iostream>

const int size=15;
int arr[size] ={1,2,3,4,5,5,3,5,7,8,9,1,2,5,10};

double getProdOf5(int *arr,int size){
    double product;
    for(int i=4;i<size;i+=5){
        if(i == 4){
            product = arr[i];
        }else{
            product*=arr[i];
        }
    }
    return product;
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
    std::cout<<"Product equals : "<<std::endl;
    std::cout<<getProdOf5(arr,size);
}