#include <iostream>
using namespace std;

template<class T>
void sorting(T arr[], int size) // Insertion Sort
{
	int j = 0;

	for (int i = 0; i < size; i++) 
	{
		int x = arr[i];

		for (j = i - 1; j >= 0 && x < arr[j]; j--)	arr[j + 1] = arr[j];

		arr[j + 1] = x;
	}
}

template<class T>
void printArray(T arr[], int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << "|";
	cout << endl;
}


int main()
{
	int arr[] = { 9,3,17,6,5,4,31,2,12 };
	double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
	char arrc[] = "Hello, word";
	int k1 = sizeof(arr) / sizeof(arr[0]);
	int k2 = sizeof(arrd) / sizeof(arrd[0]);
	int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1; // -1 to ignore the null terminator (\0)

	sorting(arr, k1);
	printArray(arr, k1);
	
	sorting(arrd, k2);
	printArray(arrd, k2);
	
	sorting(arrc, k3);
	printArray(arrc, k3);
	
	return 0;
}