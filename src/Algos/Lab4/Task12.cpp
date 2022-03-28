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
    int num = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i%2==0 && i != m-1){
                arr[j][i]=num;
                num+=1;
            }else if (i %2 != 0 && i != m-1){
                    arr[n-j-1][i]=num;
                    num+=1;
                }
            if(i == m-1){
                arr[n-j-1][i]=num;
                num -= 1;
            }
        }
        
    }
    arrayOutput(arr);
}

int main(){
    setArray(A);
}