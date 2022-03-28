#include <iostream>
using namespace std;

const int n = 5;
const int m = 5;
int A[n][m] ={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};


void arrayOutput(int ( &arr )[n][m]){
    for(int i = 0;i < n;i++){
        for(int j = 0;j <m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void setArray(int ( &arr )[n][m]){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i == j){
                arr[i][j] = 1;
                if(i == 0){
                    arr[i+1][j] = 1;
                    continue;
                }
                if(i == n-1){
                    arr[i-1][j] = 1;
                    continue;
                }
                arr[i+1][j] = 1;
                arr[i-1][j] = 1;
            }
        }
    }
    arrayOutput(arr);
}

int main(){
    setArray(A);
}