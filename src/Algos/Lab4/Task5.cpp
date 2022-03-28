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
    int leftUppper = 0;
    int rightBottom = n-1;
    for(int j = 0;j<m/2;j+=2){
        for(int i = leftUppper;i < rightBottom+1;i++){
            arr[leftUppper][i]=1;
            arr[i][leftUppper]=1;
            arr[rightBottom][i]=1;
            arr[i][rightBottom]=1;
        }
        leftUppper+=2;
        rightBottom-=2;
    }
    arrayOutput(arr);
}

int main(){
    setArray(A);
}