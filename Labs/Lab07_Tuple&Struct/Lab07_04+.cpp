#include <iostream> 
#include <windows.h> 
#include <string> 
#include <tuple> // connect tuple
#include <vector> 
using namespace std;

using Tuple = tuple<string, int, double>; // it allows to use Tuple as an alias for tuple<string, int, double>
using TupleTwo = tuple<string, int>; 

void printTupleOfThree(Tuple t) // if not using typedef, then: void printTupleOfThree(tuple<string, int, double> t)
{
	cout << "("
		<< get<0>(t) << ", "  //index of tuple must be integer constant expression
		<< get<1>(t) << ", "
		<< get<2>(t) << ")" << endl;
	//cout << get<index>(t) << endl; //error: index must be constant expression, index must be known at compile time
}

Tuple funtup(string s, int a, double d)
{
	s.append("!");
	return make_tuple(s, a, d * 10);
}

void changeTuple(Tuple& t)
{
	get<0>(t).append("?");
	get<1>(t) += 10;
	get<2>(t) *= 100;	
}

TupleTwo makeTupleOfTwo(Tuple& t)
{
	changeTuple(t);
	return make_tuple(get<0>(t), get<1>(t));
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

	auto t1 = funtup(v1[1], v2[1], v3[1]);
	printTupleOfThree(t1);

	auto t2 = make_tuple(v1[2], v2[2], v3[2]);
	changeTuple(t2);
	printTupleOfThree(t2);

	auto t3 = make_tuple(v1[3], v2[3], v3[3]);
	auto t4 = makeTupleOfTwo(t3);
	printTupleOfThree(t3);
	cout << "(" << get<0>(t4) << ", " << get<1>(t4) << ")" << endl;

	
	return 0;
}