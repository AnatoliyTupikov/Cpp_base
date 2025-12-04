
#include <iostream>
#include <string>


int main()
{
	setlocale(LC_ALL, "Rus");
	std::string name;
	std::cout << "What is your name? ";
	//std::cin >> name;  //считает воод до первого пробела
	std::getline(std::cin, name); //считает всю строку включая пробелы
	std::cout << "Hello, " << name << "\n";
}
