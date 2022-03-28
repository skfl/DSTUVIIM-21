#include <iostream>
using namespace std;
const int n = 5;
const int m = 3;

int A[n][m] ={{1,2,-3},{-1,5,3},{6,-7,8},{14,21,11},{2,3,6}};

int find_max(int *arr,int size){
    int max = arr[0];

    for(int i = 0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}


int main(){
   //array output
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<A[i][j]<<" ";
        }
    cout<<std::endl;
    }
    cout<<std::endl;

    //swaping
    //1 - 2
    int tmp[m];
    for(int i = 0;i<m;i++){
        tmp[i]=A[0][i];
    }
    for(int i = 0;i<m;i++){
        A[0][i]=A[1][i];
        A[1][i]=tmp[i];
    }
    //3-2
    for(int i = 0;i<m;i++){
        tmp[i]=A[1][i];
    }
    for(int i = 0;i<m;i++){
        A[1][i]=A[2][i];
        A[2][i]=tmp[i];
    }
    //1-5
    for(int i = 0;i<m;i++){
        tmp[i]=A[0][i];
    }
    for(int i = 0;i<m;i++){
        A[0][i]=A[n-1][i];
        A[n-1][i]=tmp[i];
    }


    //array output
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<A[i][j]<<" ";
        }
    cout<<std::endl;
    }
    cout<<std::endl;
    
    //getting M
    int M[n];

    for(int i = 0;i<n;i++){
        M[i] = find_max(A[i],m);
    }

    // output M
    for(int i = 0;i<n;i++){
        cout<<M[i]<<" ";
    }

}