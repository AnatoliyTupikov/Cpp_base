#include<iostream>;
#include<fstream>;
#include <filesystem>;

int SumArray(const int arr[], const int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int AverageArray(const int arr[], const int size)
{
	int sum = SumArray(arr, size);
	return sum / size;
}

int CountNegative(const int arr[], const int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0) sum += arr[i];
	}
	return sum;
}

int CountPositive(const int arr[], const int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0) sum += arr[i];
	}
	return sum;
}
int CountEvenIndexed(const int arr[], const int size)
{
	int sum = 0;
	for (int i = 0; i < size; i += 2)
	{
		sum += arr[i];
	}
	return sum;
}

int CountOddIndexed(const int arr[], const int size)
{
	int sum = 0;
	for (int i = 1; i < size; i += 2)
	{
		sum += arr[i];
	}
	return sum;
}

template <class T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


template <class T>
void AscOrder(T arr[], const int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			Swap(arr[i], arr[minIndex]);
		}
	}
}

template <class T>
void DescOrder(T arr[], const int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		int maxIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[maxIndex])
			{
				maxIndex = j;
			}
		}
		if (maxIndex != i)
		{
			Swap(arr[i], arr[maxIndex]);
		}
	}
}


void main()
{
	
	
	

	const int SIZE = 10;
	int arr[SIZE] = {1, 5, 78, -4, 23, -53, 123, 35, -122, -954};
	

	std::cout << "Sum= " << SumArray(arr, SIZE) << std::endl;
	std::cout << "Average= " << AverageArray(arr, SIZE) << std::endl;
	std::cout << "Sum of negative numbers= " << CountNegative(arr, SIZE) << std::endl;
	std::cout << "Sum of positive numbers= " << CountPositive(arr, SIZE) << std::endl;
	std::cout << "Sum of even indexed numbers= " << CountEvenIndexed(arr, SIZE) << std::endl;
	std::cout << "Sum of odd indexed numbers= " << CountOddIndexed(arr, SIZE) << std::endl;

	std::cout << "Array in ascending order: " << std::endl;
	AscOrder(arr, SIZE);
	for (int i : arr)
		std::cout << i << '\t';

	std::cout << std::endl << "Array in descending order " << std::endl;
	DescOrder(arr, SIZE);
	for (int i : arr)
		std::cout << i << '\t';
	



}