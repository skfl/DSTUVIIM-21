#include <iostream>
using namespace std;

const int n = 7;
const int m = 7;
int A[n][m] ={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};


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
    int num = n;
    int centre = m/2;
    for(int i = 0;i < n;i++){
        arr[0][i] = i+1;
        arr[n-1][i] = 1;
        arr[i][n-1]=num;
        num += 1; 
        for(int j = 0;j < centre;j++){
            if(j!=centre && i==j){
                arr[i+1][j] = 1;
                arr[i+1][n - j - 1] = 1;
                arr[n-i-1][j-1] = 1;
                arr[n-i-1][n - j] = 1;   
            }
        }
    }
    arrayOutput(arr);
}

int main(){
    setArray(A);
}