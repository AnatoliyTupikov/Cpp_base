// Lab02_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fmt/core.h>

int main()
{
	std::vector<int> nom = { 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 }; // обязатольно отсортирован по убыванию
    std::cout << "Введите сумму -> ";
	int summ{ 0 };
	std::cin >> summ;

	for (int cup : nom)
	{
		int count = summ / cup;
		if (count > 0)
		{
			fmt::print("Купюр номиналом {} - {} шт.\n", cup, count);
			summ -= cup * count;
		}
	}
}

