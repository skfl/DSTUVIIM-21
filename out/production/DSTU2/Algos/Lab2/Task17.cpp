#include <iostream>

const int size = 16;
int B[size]={1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,1};

int checkForLongestStreak(int *arr,int size){
    int currentStrk = 0;
    int maxStrk = 0;
    for(int i = 0;i < size;i++){
        if(arr[i] == 1){
            while(arr[i] == 1){
                i+=1;
                currentStrk += 1;
            }
            if(currentStrk > maxStrk){
                maxStrk=currentStrk;
            }
            currentStrk = 0;    
        }
    }
    return maxStrk;
}

int arrayOutput(int *arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::cout<<"Array : "<<std::endl;
    arrayOutput(B,size);
    std::cout<<"Max streak of 1 : "<<std::endl;
    std::cout<<checkForLongestStreak(B,size);
}