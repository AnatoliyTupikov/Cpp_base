#include <iostream>
#include <string>
// Search by transposition method. Move the found element one position closer to the beginning of the array. In result, frequently searched elements will be found faster.
template <class T>
int indexOfValue(T arr[], const int size, const T value)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == value)
		{			
			if (i == 0) return i;
			T temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			return i - 1;
		}			
	}
	return -1;
}
void main()
{
	const int SIZE = 5;
	std::string arr[SIZE] = { "door", "house", "earth", "key", "0" };
	for (int i = 0; i < SIZE; i++)
	{
		int sind = indexOfValue<std::string>(arr, SIZE, "key");
		std::cout << "Index: " << sind << "\t";
		for (int i = 0; i < SIZE; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
		


}
	