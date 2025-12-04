

#include <iostream>
#include <string>

std::string toBinary(int n)
{
	if (n <= 0) return "";
	int remainder = n % 2;
	return toBinary(n / 2) + std::to_string(remainder);
}


int main()
{
	int number;
	std::cout << "Enter a positive integer: ";
	std::cin >> number;
	std::string binary = toBinary(number);
	std::cout << "Binary representation (in reverse order): " << binary << std::endl;
}


