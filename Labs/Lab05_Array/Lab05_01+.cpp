#include<iostream>;
#include<fstream>;
#include <filesystem>;


void main()
{
	auto exePath = std::filesystem::current_path();
	std::cout << "Current path is: " << exePath << std::endl;


	std::ifstream fileStream("Lab05_01+_input.txt"); //without new operator, because we don't need dynamic memory (heap) allocation here
	if (!fileStream) //check if file opened successfully. "Null" and "0" implicitly convert to false in C++
	{
		std::cout << "Error opening file!" << std::endl;
		return;
	}
	std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf of console input

	std::cin.rdbuf(fileStream.rdbuf()); //redirect std::cin to file Lab05_01_input.txt

	const int SIZE = 10;
	int arr[SIZE];
	int sum = 0;
	int negativeCount = 0;
	int positiveCount = 0;
	int evenCount = 0;
	int oddCount = 0;
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "mas[" << i << "]= ";
		std::cin >> arr[i];
		sum += arr[i];
		if (arr[i] < 0)	negativeCount += arr[i];
		else positiveCount += arr[i];
		if (i % 2 == 0) evenCount += arr[i];
		else oddCount += arr[i];
	}

	std::cout << "Sum= " << sum << std::endl;
	std::cout << "Average= " << static_cast<double>(sum) / SIZE << std::endl;
	std::cout << "Sum of negative numbers= " << negativeCount << std::endl;
	std::cout << "Sum of positive numbers= " << positiveCount << std::endl;
	std::cout << "Sum of even indexed numbers= " << evenCount << std::endl;
	std::cout << "Sum of odd indexed numbers= " << oddCount << std::endl;
	std::cin.rdbuf(cinbuf); //restore old buf to std::cin



}