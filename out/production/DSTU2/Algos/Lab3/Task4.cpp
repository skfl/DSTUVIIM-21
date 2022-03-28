#include <iostream>
#include <cmath>
using namespace std;


int countValues(){
    double z[4]={1.1,1.3,1.5,2.1};
    double w = 0.2;
    double y;
    double v;
    int cnt = 0;

    for(int j = 1;j<=5;j++){
        if(j<3){
            y = 29; //???????????
            for(int i=0;i<4;i++){
                for(int q = 0;q<4;q++){
                    v = (3*w-5*y)/(z[q]);
                    cout<<v<<endl;
                    if(v>5){
                        cnt+=1;
                    }
                }
                w*=1.7;
            }
        }else{
            y = 7; 
            w=0.2;
            for(int i=0;i<4;i++){
                for(int q = 0;q<4;q++){
                    v = (3*w-5*y)/(z[q]);
                    cout<<v<<endl;
                    if(v>5){
                        cnt+=1;
                    }
                }
                w*=1.7;
            }
        }
    }
    return cnt;
}
int main(){
    cout<<countValues();
}