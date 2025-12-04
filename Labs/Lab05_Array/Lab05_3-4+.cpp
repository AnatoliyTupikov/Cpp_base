#include <iostream>

void ShowArray(const int arr[], const int size);

bool from_min(const int a, const int b)
{
	return a > b;
}

bool from_max(const int a, const int b)
{
	return a < b;
}

void bubble_sort(int arr[], const int size, bool(*compare)(int a, int b)) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (compare(arr[j], arr[j + 1])) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}
	}
}


void main()
{
	bool (*from_f2[2])(int a, int b) = {from_min, from_max};
	int SIZE = 10;
	int sortDirection = 0; 
	int* arr = new int[SIZE] { 0, 2, 9, 1, -5, 6, 3, 7, 8, 4 };
	std::cout << "1. Сортировать по возрастанию\n";
	std::cout << "2. Сортировать по убыванию\n";
	std::cin >> sortDirection;
	std::cout << "Исходные данные: ";
	ShowArray(arr, SIZE);
	if (sortDirection != 1 && sortDirection != 2) 
	{
		std::cout << "Некорректный ввод!" << std::endl;
		return;

	}
	bubble_sort(arr, SIZE, from_f2[sortDirection - 1]);
	std::cout << "Отсортированные данные: ";
	ShowArray(arr, SIZE);

	delete[] arr;

}

void ShowArray(const int arr[], const int size)
{

	for (int i = 0; i < size; i++)
	{

		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}