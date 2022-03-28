#include <iostream> 

double a = 10;
double b = 20;
double c = 3;
double d = 4;



void check_if_fits(double a, double b, double c, double d) {
	if ((a<c && b<d)||(a<d && b<c)) {
		std::cout << "Doesn't fit" << std::endl;
	}
	else
	{
		std::cout << "Fits" << std::endl;
	}
}

int main() {
	check_if_fits(a, b, c, d);
	//std::cout << a << std::endl;
}