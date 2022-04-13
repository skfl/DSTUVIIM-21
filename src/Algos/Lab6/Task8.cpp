#include <iostream>

using namespace std;


double getPow(int num,int pow){
    double power = 1;
    if(pow == 0){
        return 1;
    }
    if(num == 0){
        cout<<"Zero is restricted"<<endl;
        return -1;
    }
    for(int i = 0;i<pow;i++){
        power *= num;
    }
    return power;
}


int main(){
    cout<<getPow(3,3);
}