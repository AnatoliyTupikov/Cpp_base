#include <iostream>
#include <concepts>
#include <vector>
#include <string>
#include <complex>
using namespace std;

template <class T>
concept Sortable = requires(const T & a) {
	begin(a);  // requires that the type T has a begin() function, which returns an iterator to the beginning of the collection
	end(a);		// requires that the type T has an end() function, which returns an iterator to the end of the collection

	{ *begin(a) <= *begin(a)} -> std::convertible_to<bool>;
	{ *begin(a) >= *begin(a)} -> std::convertible_to<bool>;

};

template <Sortable T>
bool is_sorted(const T & coll)
{
	bool ASC = true;
	bool DESC = true;
	for (auto it = begin(coll); it != end(coll) - 1; ++it) // iterate through the collection
	{		
		if (ASC && !(*it <= *(it + 1))) ASC = false;		
		if (DESC && !(*it >= *(it + 1))) DESC = false;
		if (!ASC && !DESC) break;		
	}
	return ASC || DESC;
}

int main()
{
	vector<int> vec1 = { 1, 2, 2, 3, 5 };
	vector<int> vec2 = { 5, 4, 4, 2, 1 };
	cout << "vec1 is sorted: " << (is_sorted(vec1) ? "true" : "false") << endl;
	cout << "vec2 is sorted: " << (is_sorted(vec2) ? "true" : "false") << endl;

	vector<string > vec3 = { "apple", "banana", "cherry" };
	vector<string > vec4 = { "cherry", "banana", "apple" };
	cout << "vec3 is sorted: " << (is_sorted(vec3) ? "true" : "false") << endl;
	cout << "vec4 is sorted: " << (is_sorted(vec4) ? "true" : "false") << endl;

	vector<complex<double>> vec5 = { {1.0, 2.0}, {3.0, 4.0} };
	//cout << "vec5 is sorted: " << (is_sorted(vec5) ? "true" : "false") << endl; // this line will cause a compilation error because complex numbers do not support <= or >= operators
	return 0;
}