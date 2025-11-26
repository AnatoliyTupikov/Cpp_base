//sorting an array using choice sort algorithm

#include <iostream>

template <class T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


template <class T>
void AscOrder(T arr[], int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[minIndex])
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
void DescOrder(T arr[], int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		int maxIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if(arr[j] > arr[maxIndex])
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
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

	std::cout << "Array in ascending order: " << std::endl;
	AscOrder(a, N);
	for (int i : a)
		std::cout << i << '\t';

	std::cout << std::endl << "Array in descending order " << std::endl;
	DescOrder(a, N);
	for (int i : a)
		std::cout << i << '\t';

}