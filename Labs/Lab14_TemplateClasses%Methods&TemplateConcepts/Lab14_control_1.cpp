#include <iostream>

template<class T>
double Average(T arr[], int size)
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return static_cast<double>(sum) / size;
}

int main()
{
	int intArr[] = { 1, 2, 3, 4, 5 };
	double doubleArr[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
	long longArr[] = { 100000L, 200000L, 300000L, 400000L, 500000L };
	char charArr[] = { 'A', 'B', 'C', 'D', 'E' };
	std::cout << "Average of intArr: " << Average(intArr, 5) << std::endl;
	std::cout << "Average of doubleArr: " << Average(doubleArr, 5) << std::endl;
	std::cout << "Average of longArr: " << Average(longArr, 5) << std::endl;
	std::cout << "Average of charArr: " << Average(charArr, 5) << std::endl;
	return 0;
}