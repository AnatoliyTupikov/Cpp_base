#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int FindMaxEven(vector<int> v) 
{
	auto itr = find_if(v.cbegin(), v.cend(),
		[](const int el)
		{
			return el % 2 == 0;
		});
	if (itr == v.end()) throw runtime_error("No even elemets found!");

	int maxEven = *itr;
	
	for_each(v.cbegin(), v.cend(),
		[&maxEven](const int el) // capture by default is by value, so we specify by reference. Now we can modify maxEven
		{
			if (el % 2 == 0 && el > maxEven) maxEven = el;
		});
	return maxEven;
}

int main()
{
	vector<int> vec = { 1, -2, 2, -10, 9 };
	try 
	{
		cout << FindMaxEven(vec) << endl;
	}
	catch (runtime_error& e) 
	{
		cerr << e.what() << endl;
	}
	return 0;
}