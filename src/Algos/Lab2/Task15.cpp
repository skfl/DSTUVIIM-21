#include <iostream>

const int size=7;
int D[size] ={1,21,3,4,-1,5,3};

int* changeOddEvenMinMax(int *D,int size){
    
    int maxEven=D[1];
    int minOdd=D[0];
    int maxEvenIndex = 1;
    int minOddIndex = 0;

    for(int i=0;i<size;i++){
        if(i%2==0){
            if(D[i]<minOdd){
                minOdd = D[i];
                minOddIndex = i;
            }else{
                if(D[i]>maxEven){
                    maxEven = D[i];
                    maxEvenIndex = i;
                }
            }
        }
    }
    int tmp = D[minOddIndex];
    D[minOddIndex] = D[maxEvenIndex];
    D[maxEvenIndex] = tmp;
    
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
    arrayOutput(D,size);
    std::cout<<"New Array : "<<std::endl;
    arrayOutput(changeOddEvenMinMax(D,size),size);
}