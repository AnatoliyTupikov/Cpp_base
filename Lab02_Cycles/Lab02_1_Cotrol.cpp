
#include <iostream>
#include <vector>
#include <string>

int main()
{
	

	int number{ 2 };
	std::vector<int> result{2};
    std::cout << "Specify an integer number is greater than 1-> ";
	std::cin >> number;
	std::string not_sn = "This number is NOT super simple " + std::to_string(number) + "!";
	std::string yes_sn = "This number is super simple " + std::to_string(number) + "!";
	for (int i = 2; i <= number; ++i) 
	{
		if (i % 2 != 0) result.push_back(i);
		else if (i == number) 
		{ 
			std::cout << not_sn << std::endl;
			return 0;
		}
		
	}

	
	for (int i = 0; i <= number; i++) 
	{
		if (i >= result.size() - 1) break;
		for (int j = i + 1; j <= number; j++) 
		{
			if (j >= result.size()) break;

			if (result[j] % result[i] == 0 && result[j] != result[i]) 
			{ 
				if (result[j] == number)
				{
					std::cout << not_sn << std::endl;
					return 0;
				}
				result.erase(result.begin() + j); 
				j--;
			}
			 
		}
	}

	int pos = result.size();
	for (int n : result)
	{
		if (pos == n)
		{
			std::cout << yes_sn << std::endl;
			return 0;
		}
		
	}
	std::cout << not_sn << std::endl;

		
}


