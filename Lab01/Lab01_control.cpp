// Lab01_control.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fmt/core.h>
#include <iostream>

int main()
{
	int n{ 0 }, x{ 0 }, y{ 0 };
	std::cout << "Specify the number of vertices of the polygon: \n";
	std::cin >> n;

	std::vector<std::vector<int>> matrix;
	for (int i = 0; i < n; i++) {
		fmt::print("Enter the coordinates of vertex №{}\n", i + 1);
		std::cout << "x: ";
		std::cin >> x;
		std::cout << "y: ";
		std::cin >> y;
		std::cout << "\n";
		matrix.push_back({ x, y });
	}
	matrix.push_back({matrix[0][0], matrix[0][1]});

	int left{ 0 }, right{ 0 };
	for (int i = 0; i < n; i++) {
		 left += matrix[i][0] * matrix[i + 1][1];
		 right += matrix[i][1] * matrix[i + 1][0];
	}
	int area = abs(left - right) / 2;

	fmt::print("The area of the polygon is: {}\n", area);



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
