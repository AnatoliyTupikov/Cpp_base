
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

bool can_int_cast(const std::string& s, long long& out)
{
	std::istringstream iss(s);
	iss >> out;
	return iss.eof() && !iss.fail();
}

void str_formatting(std::string& snum)
{
	snum.erase(std::remove(snum.begin(), snum.end(), '-'), snum.end());
	snum.erase(std::remove(snum.begin(), snum.end(), ' '), snum.end());
}

bool is_correct(std::string snum) 
{
	long long c{ 0 };	
	return can_int_cast(snum, c);
}

std::string is_correct_snils(const std::string& snils)
{
	str_formatting(const_cast<std::string&>(snils));
	if (!is_correct(snils)) return "False";
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
			return "False";
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
		if (dev < 100) summ = dev;
		else summ = 0;
	}
	else summ = 0;

	std::ostringstream oss;

	oss << std::setw(2) << std::setfill('0') << summ;
	std::string result = oss.str();

	if (result == ctrl_number) return "True";
	else return "False";
	
}

int main()
{
	std::string snils;
	std::cout << "Specify \"SNILS\" number:\n";
	std::getline(std::cin, snils);
	std::cout << is_correct_snils(snils) << std::endl;
	
}
