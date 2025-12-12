#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <concepts> 
using namespace std;


// Why one class for tuple? Because tuple with elements of different types is a class itself. tuple<int, double, string> is a whole class and tuple<char, float> is another class.
// In template we can use not only types but also values, objects, pointers, references, etc. as template parameters (non-type template parameter). Like variable for class of the template.
// Every different combination of types and values creates a new class from the template.
template <class tType, int N> 
	requires //this "requires" is operator of the template, which just says: the template has the following constraints. If they are satisfied, the class can be created, else compilation error occurs.
		(N > 0) &&
			requires (tType t) // this "requires" is expression, part of the constraints of the template. It checks if expressions inside can be compiled. If yes, returns true, else false.
		{
			// In requires body, compiler just try to compile the expressions. If it is possible, the operator returns true, else false.
			get<0>(t);
		}  

struct TuplePrinter
{
	static void print(const tType& t)
	{
		TuplePrinter<tType, N - 1>::print(t); // Recursive creation of classes from the template with decreasing N until N=1. N-1 becouse index of tuple starts from 0.
		cout << ", " << get<N - 1>(t);
	}
	
};

template <class tType>
// Before class from the specioalization template will be created, requirements of the general template will be checked.
struct TuplePrinter<tType, 1> // Partial specialization of the template for N=1. That means when N=1, this version of the class will be used instead of the general one. It is needed to stop the recursion.
{
	
	static void print(const tType& t)
	{
		cout << get<0>(t);
	}
};

template <class... Types> // Variadic template to accept any number of types.
void printTuple(const tuple<Types...>& t)
{
	cout << "(";
	TuplePrinter<decltype(t), sizeof...(Types)>::print(t); // "decltype(t)" gets the type of the variable t, "sizeof...(Types)" gets the number of types in the parameter pack Types.
	cout << ")" << endl;
}

int main()
{
	
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	auto t1 = std::make_tuple(v1[0], v1[1], v3[0]);
	auto t2 = std::make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);

	printTuple(t1);
	printTuple(t2);
	
	return 0;
}