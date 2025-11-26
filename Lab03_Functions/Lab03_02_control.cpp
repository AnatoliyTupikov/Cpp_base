

#include <iostream>

double th_root(double a, double n = 3)
{
    double result = (a / (n * n) + 2 * 3) / 3;
	std::cout << "Iteration function: " << result << std::endl;
	return result;
}

double def_fn(double a, double n = 3)
{
	double result = pow(a, 1.0/n);
	std::cout << "Default function: " << result << std::endl;
	return result;
}



int main()
{
	double base{ 0 };
	std::cout << "Enter a number to find its cube root: ";
	std::cin >> base;
	std::cout << "Cube root of " << base << " : " << std::endl;
	th_root(base);
	def_fn(base);
    
}


