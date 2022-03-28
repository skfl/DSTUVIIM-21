#include <iostream>

double firstNum = 9;
double secondNum = 1;
double thirdNum = 12;

void find(double a, double b, double c) {
	double min = a;
	double max = a;
	// find min
	if (a > b) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
	// find max
	if(a < b){
		max = b;
	}
	if(c > max){
		max = c;
	}

	
	std::cout << "Maximal number is: " << max << std::endl;
}




int main() {
	find(firstNum,secondNum,thirdNum);
}