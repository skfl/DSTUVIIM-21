#include <iostream>

using namespace std;
 const int n = 11;

 int B[n]={100,7,5,4,6,-999,1,22,4,9,2};
 int testArray[7] = {1,2,-1,4,0,2,6};
 
 int findMinFromEdges(int *arr,int size,int num){
     int min = arr[0];
     if(num<=size){
         for(int i = 1;i<num;i++){
            if(arr[i]<min){
                min = arr[i];
            }
         }
         for(int i = size-1;i>size-num-1;i--){
             if(arr[i]<min){
                 min = arr[i];
             }
         }
     }
     return min;
 }

void arrayOutput(int *arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

 int main(){
     arrayOutput(B,n);
     cout<<findMinFromEdges(B,n,5);
 }