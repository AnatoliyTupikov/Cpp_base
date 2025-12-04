//sorting an array using choice sort algorithm

#include <iostream>
#include <fstream>

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
void DescOrder(T arr[], int size)
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

int main()
{
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

	std::ofstream out("arr_input.txt"); //creat an object without new, because it is created on stack
	if (!out) {
		std::cout << "Файл открыть невозможно\n";
		return 1;
	}

	for (int i : a)
		out << i << ' ';
	out << std::endl;
	



	std::cout << "Array in ascending order: " << std::endl;
	AscOrder(a, N);
	for (int i : a) {
		std::cout << i << '\t';
		out << i << ' ';
	}
	out << std::endl;
		

	std::cout << std::endl << "Array in descending order " << std::endl;
	DescOrder(a, N);
	for (int i : a) {
		std::cout << i << '\t';
		out << i << ' ';
	}
	out << std::endl;

	
	out.close();

	return 0;


}