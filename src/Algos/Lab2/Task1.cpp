#include <iostream>

const int n = 3;
const int m = 3;

int A[n][m] ={{1,2,-3},{-1,5,6},{6,-7,8}};


int main(){
    std::cout<<"Array : "<<std::endl;   
    int size = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            std::cout<<A[i][j]<<" ";
        }
    std::cout<<std::endl;
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0; j < m;j++){
            if(A[i][j]<0){
                size += 1;
            }
        }
    }
    int *B = new int[size];
    int k = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(A[i][j] < 0){
                B[k] = A[i][j];
                k++;
            }
        }
    }
    std::cout<<"New Array : "<<std::endl;
    for(int i=0;i<size;i++){
        std::cout<<B[i]<<" ";
    }
}