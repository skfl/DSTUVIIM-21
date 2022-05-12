#include <iostream>

using namespace std;
 const int n = 11;

 int B[n]={3,7,3,4,1,1,1,22,4,9,2};

void findEqualsBefore(int *arr,int size){
    int cnt = 0;
    for(int i = 1;i<size;i++){
        for(int j = i-1;j>=0;j--){
            if(arr[i]==arr[j]){
                cnt+=1;
            }
        }
        if(cnt>0){
            cout<<"There are "<<cnt<<" elements that equals : "<<arr[i]<<endl;
        }
        cnt = 0;
    }
}


 void arrayOutput(int *arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

 int main(){
     arrayOutput(B,n);
     findEqualsBefore(B,n);
 }