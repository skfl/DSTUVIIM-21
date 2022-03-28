#include <iostream>

const int size = 8;
int arr[size]={11,7,5,4,3,11,8,11};

int countPrimeNums(int *arr,int size){
    
    bool v = false;
    int cnt = 0;

    for(int i=0;i<size;i++){
        if(arr[i]==1 || arr[i]==0){
                continue;
            } 
        for(int j=2;j<arr[i];j++){                               //для оптимизации можно брать j до sqrt(arr[i])
            if(arr[i]%j==0){     
                v = true;
                break;
            }
        }
        if(v!=true){
            cnt+=1;
            v = false;
        }else{
            v = false;
        }
    }
    return cnt;
}

int arrayOutput(int *arr){
    for(int i = 0;i<sizeof(arr);i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::cout<<"There are : "<<std::endl;
    std::cout<<countPrimeNums(arr,size);
    std::cout<<" prime number(s) in array"<<std::endl;
}