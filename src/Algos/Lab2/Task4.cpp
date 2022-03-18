#include <iostream>
//using namespace std
int arr[4]={1,2,3,4};

double countPower(int *arr,int size){
    
    double power = 1;
    double sum = arr[0];

    for(int i=0;i<size;i++){
        for(int j=0;j<i+1;j++){
            power *= arr[i];
        }
        sum +=power;
        power=1;
    }
    return sum;
}

void arrayOutput(int *arr){
    for(int i = 0;i<sizeof(arr);i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::cout<<"Array : "<<std::endl;
    arrayOutput(arr);
    std::cout<<"Sum equals : "<<std::endl;
    std::cout<<countPower(arr,4);
}