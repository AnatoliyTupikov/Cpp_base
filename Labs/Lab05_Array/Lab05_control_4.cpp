#include <iostream>
#include <cstring>

void sum(const int arr[], const int size) {
	int result = 0;
	for (int i = 0; i < size; i++) {
		result += arr[i];
	}
	std::cout << "Sum: " << result << std::endl;
}

void multiply(const int arr[], const int size) {
	int result = 1;
	for (int i = 0; i < size; i++) {
		result *= arr[i];
	}
	std::cout << "Multiply: " << result << std::endl;
}

void foo(void(*compare)(const int arr[], int b), int argc, char* argv[] )
{
	int* arr = new int[argc - 2];
	
	for (int i = 2; i < argc; i++) {
		int num = atoi(argv[i]);
		if (!num && strncmp(argv[i], "0", 1))
		{
			std::cout << "The parameter is not an integer number: " << argv[i] << std::endl;
			return;
		}
		arr[i - 2] = num;		
	}
	compare(arr, argc - 2);


	delete[] arr;

}

int main(int argc, char* argv[])
{
	if (argc < 4) {
		std::cout << "There is no required parameter" << std::endl;
		return -1;
	}
	int functionSelector = 0; // 0 - sum, 1 - multiply
	if (!strncmp(argv[1], "-a", 2)) functionSelector = 0;
	else if (!strncmp(argv[1], "-m", 2)) functionSelector = 1;
	else {
		std::cout << "Unknown parametr: " << argv[1] << std::endl;
		return -1;
	}
	
	void(*compare[2])(const int arr[], int b) = { sum , multiply };
	foo(compare[functionSelector], argc, argv);


	return 0;
}