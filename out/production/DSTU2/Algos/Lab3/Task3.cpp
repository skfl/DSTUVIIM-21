#include <iostream>
#include <cmath>
using namespace std;

int countValues(){
    int cnt = 0;
    double w = 2.4;
    double x = 2;
    double y = 2;
    double z[4]={1.2,1.5,2.3,3.0};
    while(x<4){
        while (y<=6){
            if(y<3){
                for(int i = 0;i<4;i++){
                    cnt+=1;
                }
                y+=0.5;
            }if(y>=3){
                for(int i = 0;i<4;i++){
                    cnt+=1;
                }
                y+=0.75;
            }
        }
        x+=1;
    }
    while(x==4){
        for(int j = 0;j<=3;j++){
            cnt+=1;
        }
        x+=1;
    }
    return cnt;
}


int main(){
    cout<<countValues();
}