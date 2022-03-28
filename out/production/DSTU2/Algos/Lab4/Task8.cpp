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
    int c = (n%2!=0)?(n+1)/2:n/2-1;
    int f = 0; 
    for(int i = 0;i<c;i++){
        for(int j=i;j<=n-i-1;j++){
            f = n-i-1;
            arr[j][i] = 1;
            arr[j][f] = 1;
        }
    }
    arrayOutput(arr);
}

int main(){
    setArray(A);
}