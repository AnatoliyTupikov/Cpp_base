#include <iostream>
void main()
{
	// Dynamic Array
	{
		int size = 5;
		int* arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = i * 10;
			std::cout << arr[i] << "\t";
			std::cout << arr + i << std::endl;
		}
		std::cout << "=====================Reallocating Array=====================" << std::endl;
		size = 3; // it doesn't matter if the new size is smaller or larger, the array was created you can't change its size dynamically
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << "\t";
			std::cout << arr + i << std::endl;
		}
		delete[] arr; // free the memory allocated for the array
		arr = nullptr; // avoid dangling pointer

		// All size of dynamic arrays changes must be managed through new array allocation and copying data from the old array to the new one

	}

	// Two-dimensional Dynamic Array
	{
		int rows = 3;
		int cols = 4;
		int** matrix = new int* [rows]; // a two-dimensional array doesn't exist in C++, so we create an array of pointers (rows) to the first element of each array (cols)
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols]; // for each row, create an array of ints (cols)
		}
		// Initialize and print the matrix
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = i * cols + j; // assign values
				std::cout << matrix[i][j] << "\t"; // print values
			}
			std::cout << std::endl;
		}
		// Deallocate memory
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i]; // we should to delete each row first
		}
		delete[] matrix; // delete the array of pointers
		matrix = nullptr; // avoid dangling pointer
	}
	

}