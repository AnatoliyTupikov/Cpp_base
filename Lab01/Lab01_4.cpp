// Lab01_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <fmt/core.h>

int main()
{
    int a{ 0 }, b{ 0 }, c { 0 };
    std::cout << "Specify 3 triangle's sides:\n";
    std::cin >> a >> b >> c;
	double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
	fmt::print("{:>10}  {:>10}\n", "Perimeter:", "Area:");
	fmt::print("{:>10.2f}  {:>10.2f}", p * 2, area);
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
