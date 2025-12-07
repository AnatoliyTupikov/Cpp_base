#include <iostream>
#include <math.h>
#include <tuple>
using namespace std;

struct QuadraticEquation
{
	double root1;
	double root2;	

	void printRoots()
	{
		if (isnan(root1) || isnan(root2))
		{
			cout << "No real roots." << endl;
			return;
		}
		if (root1 == root2)
		{
			cout << "One root: " << root1 << endl;
		}
		else
		{
			cout << "Root 1: " << root1 << endl;
			cout << "Root 2: " << root2 << endl;
		}
	}
};

QuadraticEquation& solveQuadraticEquation(double a, double b, double c)
{
	static QuadraticEquation qe;
	double d = b * b - 4 * a * c;
	if (d < 0)
	{
		qe.root1 = NAN;
		qe.root2 = NAN;
	}
	else
	{
		qe.root1 = (-b + sqrt(d)) / (2 * a);
		qe.root2 = (-b - sqrt(d)) / (2 * a);
	}
	return qe;
}

using Tuple = tuple<bool, double, double>;
Tuple solveQuadraticEquationTuple(double a, double b, double c)
{
	double d = b * b - 4 * a * c;
	if (d < 0)
	{
		return make_tuple(false, NAN, NAN);
	}
	else
	{
		double root1 = (-b + sqrt(d)) / (2 * a);
		double root2 = (-b - sqrt(d)) / (2 * a);
		return make_tuple(true, root1, root2);
	}
}

void printTuple(const Tuple& t)
{
	cout << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")" << endl;
}


using namespace std;
int main()
{

	solveQuadraticEquation(1, -5, 6).printRoots(); 
	printTuple(solveQuadraticEquationTuple(1, -5, 6));
	cout << endl;

	solveQuadraticEquation(1, -4, 4).printRoots();
	printTuple(solveQuadraticEquationTuple(1, -4, 4));
	cout << endl;

	solveQuadraticEquation(1, 4, 5).printRoots();
	printTuple(solveQuadraticEquationTuple(1, 4, 5));
	cout << endl;
	
	return 0;
}