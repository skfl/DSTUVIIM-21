#include <iostream>

using namespace std;

struct blank
{
    int age;
};

int main(){
    blank arr[1];
    arr[0].age = 10;
    cout<<arr->age;
}
