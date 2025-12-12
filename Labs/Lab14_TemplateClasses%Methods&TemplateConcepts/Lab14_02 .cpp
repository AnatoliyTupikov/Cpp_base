#include <iostream> 
#include <windows.h> 
#include <string> 
#include <tuple> // connect tuple
#include <vector> 
using namespace std;


template<class Tuple>
void printTupleOfThree(Tuple t) 
{
	cout << "("
		<< get<0>(t) << ", "  //index of tuple must be integer constant expression
		<< get<1>(t) << ", "
		<< get<2>(t) << ")" << endl;
	//cout << get<index>(t) << endl; //error: index must be constant expression, index must be known at compile time
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	auto t0 = make_tuple(v1[0], v2[0], v3[0]);  //auto is the same var
	printTupleOfThree(t0);	

	auto t1 = make_tuple(v1[3], v1[3], v3[3]);	//another tuple
	printTupleOfThree(t1);
	

	
	return 0;
}