#include <iostream>
using namespace std;
const int n = 6;
const int m = 3;

int A[n][m] ={{1,2,-3},{-1,5,3},{6,-7,8},{14,21,11},{2,3,6},{6,0,1}};


int main(){
   
   //array output
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<A[i][j]<<" ";
        }
    cout<<std::endl;
    }
    /////////////

    int k = 3;
    int p = 1;

    if(k>n){
        cout<<"K should be less than n";
        return -1;
    }
    if(p>n){
        cout<<"P should be less than n";
        return -1;
    }
    cout<<"K equals : "<<k<<endl;
    cout<<"P equals : "<<k<<endl;
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        for(int j = 0 ;j<m; j++){ 
            if(i == k || i == p){
                continue;
            }
            if(A[i][j]==3 || A[i][j]==7 || A[i][j]==11 || A[i][j]==16){
                cnt += 1;
            }
        }
    }
    cout<<"There are : "<<cnt<<" elems that equals 3,7,11 or 16";

}