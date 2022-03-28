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
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if((j+i)%2==0){
                arr[j][i]=1;
            }
        }
    }
    arrayOutput(arr);
}

int main(){
    setArray(A);
}