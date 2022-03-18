#include <iostream>
                                                                                                                
const int size = 10;
int arr[size]={1,1,1,1,5,6,7,8,9,10};

int checkForUncommon(int *arr,int size){
    
    int *tmp = new int[size];
    int cnt = 1;
    bool exist = false;
    tmp[0]=arr[0];

    for(int i = 0;i < size;i++){
        
        for(int j = 0;j < cnt;j++){
            if(tmp[j] == arr[i]){
                exist = true;
            }
        }

        if(exist != true){
            cnt += 1;
            exist = false;
        }else{
            exist = false;
        }
    }
    return cnt;
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
    std::cout<<"Number of uncommon nums : ";
    std::cout<<checkForUncommon(arr,size);
}