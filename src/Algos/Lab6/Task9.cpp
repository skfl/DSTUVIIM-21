#include <iostream>


using namespace std;

const int n = 7;
const int m = 7;
int A[n][m] ={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};


void fillArray(int arr[n][m]){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            arr[i][j] = rand() % 4;
        }
    }
}

void arrayOutput(int arr[n][m]){
    for(int i = 0;i < n;i++){
        for(int j = 0;j <m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int* getSubArray(int arr[n][m],int i,int j){
    int *tmp = new int[4];
    if(i+1<n && j+1<m){
        tmp[0]=arr[i][j];
        tmp[1]=arr[i+1][j];
        tmp[2]=arr[i][j+1];
        tmp[3]=arr[i+1][j+1];
    }else{
        return NULL;
    }
    return tmp;
}

bool checkSubArr(int arr[n]){
    bool v = true;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(i == j){
                continue;
            }else{
                if(arr[i]==arr[j]){
                    v = false;
                    return v;
                }
            }
        }
    }
    return v;
}

int checkArr(int arr[n][m]){
    int cnt = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<m-1;j++){
            if(checkSubArr(getSubArray(arr,i,j))){
                cnt +=1;
            }
        }
    }
    return cnt;
}

int main(){
    fillArray(A);
    arrayOutput(A);
    cout<<checkArr(A);
}