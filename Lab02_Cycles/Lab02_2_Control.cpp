
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

int main()
{
	std::string snils;
	std::cout << "Specify \"SNILS\" number:\n";
	std::cin >> snils;
	std::string main_number = snils.substr(0, snils.size() - 2);
	std::string ctrl_number = snils.substr(snils.size() - 2);
	std::string c(1, snils[0]);
	int counter{ 0 };
	for (int i = 1; i <= main_number.size() - 1; i++)
	{
		std::string ct(1, snils[i]);
		if (c != ct) c = ct;
		else if (counter >= 1)
		{
			std::cout << "False";
			return 0;
		}
		else counter++;
	}

	int summ{ 0 };
	for (int i = main_number.size(); i > 0; i--) 
	{
		int n = main_number[i - 1] - '0';
		summ += n * i;
	}

	if (summ < 100) summ = summ;
	else if (summ > 101)
	{
		int dev = summ % 101;
		if ( dev < 100) summ = dev; 
		else summ = 0;
	}
	else summ = 0;

	std::ostringstream oss;

	oss << std::setw(2) << std::setfill('0') << summ; 
	std::string result = oss.str();

	if (result == ctrl_number) std::cout << "True";
	else std::cout << "False";

}
