#include <iostream>
#include <concepts>
#include <string>
#include <vector>

using namespace std;

template <class T>
concept Collection = requires(const T& a) {
	begin(a);
	end(a);	
	cout << a[0];

};

template <Collection T>
void printCollection(const T& coll, const char sep[])
{
	for (auto el : coll)
	{
		cout << el << sep;
	}
	cout << "\n";
}



int main()
{
	vector<string> vec = { "one", "two", "three", "four", "five" }; 
	vector<string> vec2 = { "a", "b", "c", "d", "f" };
	vector<int> vec3 = { 1, 2, 3, 4, 5 }; 
	vector<string> arr[2] = { vec, vec2 };// this array is not compatible with the concept Collection and can't be used in printCollection function. For example, comment "cout << a[0];" in the concept definition to make it compatible.
	int arr2[5] = { 1, 2, 3, 4, 5 };
	int a = 4;
	
	printCollection(arr2, ", ");
	return 0;
}