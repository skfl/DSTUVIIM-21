#include <iostream>

using namespace std;

int getMin(int a,int b){
    cout<<1;
    if(a<b || a==b){
        return a;
    }else{
        return b;
    }
}


double getMin(double a,double b){
    cout<<2;
    if(a<b || a==b){
        return a;
    }else{
        return b;
    }
}


float getMin(float a,float b){
    cout<<3;
    if(a<b || a==b){
        return a;
    }else{
        return b;
    }
}

int main(){
    getMin(1,6);
    getMin(1.4,1.8);
    getMin(1.4f,1.5f);
}