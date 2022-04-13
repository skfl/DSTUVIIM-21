#include <iostream>
#include <cmath>

using namespace std;

double getTriangleSquare(double base,double height){
    return 0.5*base*height;
}

double getTriangleSquare(double side){
    return side*side/2;
}

double getTriangleSquare(double a,double b,double c){
    double halfPerimetr = (a + b + c) / 2;
    return sqrt(halfPerimetr*(halfPerimetr - a)*(halfPerimetr - b)*(halfPerimetr - c));
}
int main(){
    cout<<getTriangleSquare(10,15)<<endl;
    cout<<getTriangleSquare(15)<<endl;
    cout<<getTriangleSquare(13,14,16)<<endl;
}