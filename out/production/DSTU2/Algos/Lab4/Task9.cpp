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
    int sumBefore = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if((j == 0) && (i%2==0) || j == 1){
                arr[i][j] = 1;
                sumBefore += 1;
            }else{
                arr[i][j]=sumBefore;
                sumBefore+=arr[i][j];
            }
            
        }
        sumBefore = 0;
    }
    arrayOutput(arr);
}

int main(){
    setArray(A);
}