
#include <iostream>


void main()
{
	const int SIZE = 5;
	int arr[SIZE] = { 10, 20, 30, 40, 50 }; //static array of integers

	std::cout << arr << "\n"; //here we will see the addres of the memory location where there is the first element of the array
	std::cout << *arr << "\n"; //dereferencing the pointer to the first element of the array, so we will see 10
	
	//it means that the variable of array is a pointer to the first element of the array.
	//It follows that we can use pointer arithmetic to access the elements of the array.

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << *(arr + i) << " "; //accessing the elements of the array using pointer arithmetic. Here it adds sizeof(int) (4 bytes) * i to the address of the first element of the array.
		std::cout << arr + i << "\n"; //printing the address of each element of the array. How we can see, the address increases by 4 bytes (sizeof(int)) for each element.
	}



}